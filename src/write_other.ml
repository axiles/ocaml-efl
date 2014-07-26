open Format

let ptr_types = [
  "Evas_Modifier";
  "Evas_Object";
  "Evas_Device";
  "Elm_Object_Item";
  "Elm_Calendar_Mark";
]

let print_ptr_type_c_impl fmt name =
  fprintf fmt "inline %s* %s_val(value v)\n" name name;
  fprintf fmt "{\n";
  fprintf fmt "        return (%s*) v;\n" name;
  fprintf fmt "}\n\n";
  fprintf fmt "inline value Val_%s(const %s* x)\n" name name;
  fprintf fmt "{\n";
  fprintf fmt "        return (value) x;\n";
  fprintf fmt "}\n\n"

let print_ptr_type_c_header fmt name =
  fprintf fmt "inline %s* %s_val(value v);\n\n" name name;
  fprintf fmt "inline value Val_%s(const %s* x);\n\n" name name

let ( / ) = Filename.concat

let print_c_impl () =
  let ch = open_out ("src" / "other_wrap.c") in
  let fmt = formatter_of_out_channel ch in
  fprintf fmt "#include \"include.h\"\n\n";
  List.iter (print_ptr_type_c_impl fmt ) ptr_types;
  fprintf fmt "%!";
  close_out ch

let print_c_header () =
  let ch = open_out ("src" / "other_wrap.h") in
  let fmt = formatter_of_out_channel ch in
  List.iter (print_ptr_type_c_header fmt) ptr_types;
  fprintf fmt "%!";
  close_out ch

let () =
  print_c_impl ();
  print_c_header ();
  exit 0

