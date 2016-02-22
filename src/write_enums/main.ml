open Format

let get_hash_value s =
  let open Int32 in
  let val_int x = logor (shift_left x 1) 1l in
  let int_val x = shift_right x 1 in
  let accu = ref (val_int 0l) in
  let aux c =
    accu := val_int (add (mul 223l (int_val !accu)) (of_int (int_of_char c))) in
  String.iter aux s;
  to_string !accu

module Variant : sig
  type t = private {
    ml : string;
    c : string;
    macro : string;
  }
  val create : string -> int -> t
  val compare : t -> t -> int
end = struct
  type t = {
    ml : string;
    c : string;
    macro : string;
  }
  let keywords = ["end"; "done"; "in"; "class"]
  let create c n =
    let ml = String.lowercase (String.sub c n (String.length c - n)) in
    let macro = sprintf "Val_%s" ml in
    let ml = if List.mem ml keywords then sprintf "_%s" ml else ml in
    {ml; c; macro}
  let compare v1 v2 = compare v1.c v2.c
end

module Variants : sig
  type t
  val empty : t
  val add : t -> Variant.t -> t
  val print_def : formatter -> t -> unit
end = struct
  module S = Set.Make(Variant)
  type t = S.t
  let empty = S.empty
  let add set v = S.add v set
  let print_def fmt set =
    let aux v =
      let hash = get_hash_value v.Variant.ml in
      Variant.(fprintf fmt "#define %s (%s)\n" v.macro hash) in
    S.iter aux set
end

module Enum : sig
  type t = private {
    ml_name : string;
    c_name : string;
    ml_of_c : string;
    c_of_ml : string;
    variants : Variant.t list;
  }
  val create : string -> Expr.enum -> t
  val print_ml : formatter -> t -> unit
  val print_ml_sig_help : formatter -> t -> unit
  val print_ml_impl_help : formatter -> string -> t -> unit
  val print_c_include : formatter -> t -> unit
  val print_c_impl : formatter -> t -> unit
  val add_variants : t -> Variants.t -> Variants.t
end = struct
  type t = {
    ml_name : string;
    c_name : string;
    ml_of_c : string;
    c_of_ml : string;
    variants : Variant.t list;
  }
  let get_prefix_length list =
    match list with
    | [] -> 0
    | x :: xs ->
      let rec aux1 i n y =
        if i >= n then n
        else if x.[i] <> y.[i] then i
        else aux1 (i + 1) n y in
      let aux2 n y = aux1 0 n y in
      let rec aux3 n =
        if n = 0 then 0
        else if x.[n - 1] = '_' then n
        else aux3 (n - 1) in
      aux3 (List.fold_left aux2 (String.length x) list)
  let get_ml_name module_name c_name =
    let n = String.length module_name + 1 in
    String.lowercase (String.sub c_name n (String.length c_name - n))
  let create module_name e =
    let c_name = e.Expr.c_name in
    let ml_name = match e.Expr.ml_name with
    | "" -> get_ml_name module_name c_name
    | s -> s in
    let ml_of_c = sprintf "Val_%s" c_name in
    let c_of_ml = sprintf "%s_val" c_name in
    let prefix_length = match e.Expr.prefix_length with
    | Some n -> n
    | None -> get_prefix_length e.Expr.variants in
    let aux_variants s = Variant.create s prefix_length in
    let variants = List.map aux_variants e.Expr.variants in
    {ml_name; c_name; ml_of_c; c_of_ml; variants}
  let print_ml fmt enum =
    fprintf fmt "type %s = [\n" enum.ml_name;
    let aux v = fprintf fmt "| `%s\n" v.Variant.ml in
    List.iter aux enum.variants;
    fprintf fmt "]\n\n"
  let print_ml_sig_help = print_ml
  let print_ml_impl_help fmt prefix enum =
    fprintf fmt "type %s = %s.%s\n\n" enum.ml_name prefix enum.ml_name
  let print_c_include fmt enum =
    fprintf fmt "inline %s %s(value v);\n" enum.c_name enum.c_of_ml;
    fprintf fmt "inline value %s(%s x);\n\n" enum.ml_of_c enum.c_name
  let print_c_impl fmt enum =
    fprintf fmt "%s %s(value v)\n" enum.c_name enum.c_of_ml;
    fprintf fmt "{\n";
    fprintf fmt "        switch(v) {\n";
    let aux variant =
      let open Variant in
      fprintf fmt "                case %s: return %s;\n"
        variant.macro variant.c in
    List.iter aux enum.variants;
    (*fprintf fmt "                default: break;\n";*)
    fprintf fmt "        }\n";
    fprintf fmt "        caml_failwith(\"%s\");\n" enum.c_of_ml;
    (match enum.variants with
    | [] -> assert false
    | v :: _ -> fprintf fmt "        return %s;\n" v.Variant.c);
    fprintf fmt "}\n\n";
    fprintf fmt "value %s(%s x)\n" enum.ml_of_c enum.c_name;
    fprintf fmt "{\n";
    fprintf fmt "        switch(x) {\n";
    let aux variant =
      let open Variant in
      fprintf fmt "                case %s: return %s;\n"
        variant.c variant.macro in
    List.iter aux enum.variants;
    (*fprintf fmt "                default: break;\n";*)
    fprintf fmt "        }\n";
    fprintf fmt "        caml_failwith(\"%s\");\n" enum.ml_of_c;
    (match enum.variants with
    | [] -> assert false
    | v :: _ -> fprintf fmt "        return %s;\n" v.Variant.macro);
    fprintf fmt "}\n\n"
  let add_variants enum set =
    List.fold_left Variants.add set enum.variants
end

module Section : sig
  type t
  val create : Expr.section -> t
  val print_ml : formatter -> t -> unit
  val print_ml_sig_help : formatter -> t -> unit
  val print_ml_impl_help : formatter -> string -> t -> unit
  val print_c_include : formatter -> t -> unit
  val print_c_impl : formatter -> t -> unit
  val print_ml_check : formatter -> string -> t -> unit
  val add_variants : t -> Variants.t -> Variants.t
end = struct
  type t = {name : string; enums : Enum.t list}
  let create e =
    let name = e.Expr.name in
    let enums = List.rev (List.rev_map (Enum.create name) e.Expr.enums) in
    {name; enums}
  let print_ml fmt s =
    fprintf fmt "module %s = struct\n\n" s.name;
    List.iter (fun enum -> Enum.print_ml fmt enum) s.enums;
    fprintf fmt "end\n\n"
  let print_ml_sig_help fmt s =
    List.iter (fun enum -> Enum.print_ml_sig_help fmt enum) s.enums
  let print_ml_impl_help fmt hidden_name s =
    let prefix = sprintf "%s.%s" hidden_name s.name in
    let aux enum = Enum.print_ml_impl_help fmt prefix enum in
    List.iter aux s.enums
  let print_c_include fmt s =
    List.iter (Enum.print_c_include fmt) s.enums
  let print_c_impl fmt s = List.iter (Enum.print_c_impl fmt) s.enums
  let print_ml_check fmt hidden_name s =
    fprintf fmt "module H%s : module type of %s.%s = %s\n"
      s.name hidden_name s.name s.name 
  let add_variants s set =
    let aux accu enum = Enum.add_variants enum accu in
    List.fold_left aux set s.enums
end

module Sections : sig
  type t
  val create : unit -> t
  val print_ml : t -> unit
  val print_ml_sig_help : t -> unit
  val print_ml_impl_help : t -> unit
  val print_c_include : t -> unit
  val print_c_impl : t -> unit
  val print_ml_check : t -> unit
end = struct
  type t = Section.t list
  let ( / ) = Filename.concat
  let create () =
    let ch = open_in ("src" / "write_enums" / "enums.txt") in
    let lexbuf = Lexing.from_channel ch in
    let expr = Parser.expr Lexer.token lexbuf in
    close_in ch;
    List.rev (List.rev_map Section.create expr)
  let print_aux filename prolog print list =
    let ch = open_out filename in
    let fmt = formatter_of_out_channel ch in
    if prolog <> "" then fprintf fmt "%s\n\n" prolog;
    List.iter (fun x -> print fmt x) list;
    fprintf fmt "%!";
    close_out ch
  let print_ml = print_aux ("src" / "henums.ml") "" Section.print_ml
  let print_ml_sig_help =
    print_aux ("src" / "write_enums" / "help.mli") "" Section.print_ml_sig_help
  let print_ml_impl_help =
    print_aux ("src" / "write_enums" / "help.ml") ""
      (fun fmt -> Section.print_ml_impl_help fmt "Henums")
  let print_c_include list =
    print_aux ("src" / "enums_wrap.h") "" Section.print_c_include list;
    let ch = open_out ("src" / "enums_variants_wrap.h") in
    let fmt = formatter_of_out_channel ch in
    let aux accu sec = Section.add_variants sec accu in
    let variants = List.fold_left aux Variants.empty list in
    Variants.print_def fmt variants;
    fprintf fmt "%!";
    close_out ch
  let print_c_impl =
    print_aux ("src" / "enums_wrap.c") "#include \"include.h\""
      Section.print_c_impl
  let print_ml_check =
    print_aux ("src" / "henums_check.ml") ""
      (fun fmt -> Section.print_ml_check fmt "Henums")
end

let () =
  let sections = Sections.create () in
  Sections.print_ml sections;
  Sections.print_ml_sig_help sections;
  Sections.print_ml_impl_help sections;
  Sections.print_c_include sections;
  Sections.print_c_impl sections;
  Sections.print_ml_check sections;
  exit 0
