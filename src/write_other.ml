open Format

let ptr_types = [
  "Ecore_Animator";
  "Ecore_Timer";
  "Evas";
  "Ecore_Evas";
  "Evas_Modifier";
  "Evas_Object";
  "Evas_Device";
  "Elm_Object_Item";
  "Elm_Calendar_Mark";
  "Elm_Map_Overlay";
  "Elm_Map_Route";
  "Elm_Map_Name";
  "Elm_Toolbar_Item_State";
  "Elm_Transit";
  "Elm_Web_Window_Features";
  "Ecore_Window";
  "Ecore_Event_Handler";
  "Ecore_Event";
  "Evas_GL";
  "Elm_Box_Transition";
  "Evas_Object_Box_Data";
]

let print_ptr_type_c_impl fmt name =
  fprintf fmt "inline %s* %s_val(value v)\n" name name;
  fprintf fmt "{\n";
  fprintf fmt "        return (%s*) v;\n" name;
  fprintf fmt "}\n\n";
(* Keeping Val_%s, for now for compatibility reasons *)
  let of_c name1 = 
    fprintf fmt "inline value %s(const %s* x)\n" name1 name;
    fprintf fmt "{\n";
    fprintf fmt "        return (value) x;\n";
    fprintf fmt "}\n\n" in
  of_c (sprintf "Val_%s" name);
  of_c (sprintf "copy_%s" name)

let print_ptr_type_c_header fmt name =
  fprintf fmt "%s* %s_val(value v);\n\n" name name;
  let of_c name1 = fprintf fmt "value %s(const %s* x);\n\n" name1 name in
  of_c (sprintf "Val_%s" name);
  of_c (sprintf "copy_%s" name)

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

