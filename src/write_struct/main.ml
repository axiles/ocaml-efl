open Format

module Ty = struct
  type t = {
    name : string;
    ml_name : string;
    c_name : string;
    c_of_ml : string;
    ml_of_c : string;
    base : bool;
  }
end

module Tys : sig
  type t
  val empty : t
  val add : t -> Ty.t -> t
  val find : t -> string -> Ty.t option
end = struct
  module StringMap = Map.Make (struct
    type t = string
    let compare : string -> string -> int = compare
  end)
  type t = Ty.t StringMap.t
  let empty = StringMap.empty
  let add tys t = StringMap.add t.Ty.name t tys
  let find tys name =
    try Some (StringMap.find name tys) with Not_found -> None
end

module Field : sig
  type t
  val create : Tys.t -> Expr.field -> t
  val print_ml : formatter -> t -> unit
  val print_ml_hidden : formatter -> t -> unit
  val print_c_of_ml : string -> bool -> string -> int -> formatter -> t -> unit
  val print_ml_of_c : string -> int -> string -> bool -> formatter -> t -> unit
  val get_param : t -> string option
end = struct
  type t = {
    ml_name : string;
    c_name : string;
    ty : Ty.t;
  }
  let create env e =
    let c_name = e.Expr.Field.name in
    let ml_name = String.copy (String.lowercase c_name) in
    for i = 0 to String.length ml_name - 1 do
      if ml_name.[i] = '.' then ml_name.[i] <- '_'
    done;
    let e_ty = e.Expr.Field.ty in
    let ty = match Tys.find env e_ty with
    | None -> failwith (sprintf "Unknown type %s" e_ty)
    | Some s -> s in
    {ml_name; c_name; ty}
  let print_ml fmt f =
    fprintf fmt "%s : %s;\n" f.ml_name f.ty.Ty.ml_name
  let print_ml_hidden fmt f =
    let name =
      if f.ty.Ty.base then f.ty.Ty.ml_name else sprintf "T.%s" f.ty.Ty.name in
    fprintf fmt "%s : %s;\n" f.ml_name name
  let print_c_of_ml c_var ptr ml_var i fmt f =
    let s = if ptr then "->" else "." in
    fprintf fmt "        %s%s%s = %s(Field(%s, %d));\n"
      c_var s f.c_name f.ty.Ty.c_of_ml ml_var i
  let print_ml_of_c ml_var i c_var ptr fmt f =
    let s = if ptr then "->" else "." in
    fprintf fmt "        Store_field(%s, %d, %s(%s%s%s));\n"
      ml_var i f.ty.Ty.ml_of_c c_var s f.c_name
  let get_param f = if f.ty.Ty.base then None else Some f.ty.Ty.name
end

module St : sig
  type t
  val create : Tys.t -> Expr.st -> t
  val print_ml : formatter -> t -> unit
  val print_mli : formatter -> t -> unit
  val print_c_impl : formatter -> t -> unit
  val print_c_header : formatter -> t -> unit
end = struct
  module StringSet = Set.Make (struct
    type t = string
    let compare : string -> string -> int = compare
  end)
  type t = {
    ml_name : string;
    c_name : string;
    modu : string option;
    ptr : bool;
    fields : Field.t list;
    c_of_ml : string;
    ml_of_c : string;
    params : StringSet.t
  }
  module E = Expr.St
  let create env e =
    let ml_name = e.E.ml_name in
    let c_name = e.E.c_name in
    let modu =
      if e.E.modu then (
        let s = String.copy ml_name in
        s.[0] <- Char.uppercase s.[0];
        Some s)
      else None in
    let ptr = e.E.ptr in
    let fields = List.map (Field.create env) e.E.fields in
    let c_of_ml = sprintf "inline %s %s_val(value v)" c_name c_name in
    let ml_of_c =
      let s = if ptr then sprintf "%s*" c_name else c_name in
      sprintf "inline value copy_%s(%s x)" c_name s in
    let params =
      let aux accu f =
        match Field.get_param f with
        | Some s -> StringSet.add s accu
        | None -> accu in
      List.fold_left aux StringSet.empty fields in
    {ml_name; c_name; modu; ptr; fields; c_of_ml; ml_of_c; params}
  let print_ml_aux print_field be fmt st =
    (match st.modu with
    | Some s -> fprintf fmt "module %s %s\ntype t = {\n" s be
    | None -> fprintf fmt "type %s = {\n" st.ml_name);
    List.iter (print_field fmt) st.fields;
    (match st.modu with
    | Some s -> fprintf fmt "}\nend\n\ntype %s = %s.t\n\n" st.ml_name s 
    | None -> fprintf fmt "}\n\n")
  let print_ml fmt st =
    fprintf fmt "module type S%s = sig\n" st.ml_name;
    StringSet.iter (fun s -> fprintf fmt "type %s\n" s) st.params;
    fprintf fmt "end\n\n";
    fprintf fmt "module F%s (T : S%s) = struct\n" st.ml_name st.ml_name;
    print_ml_aux Field.print_ml_hidden "= struct" fmt st;
    fprintf fmt "end\n\n"
  let print_mli = print_ml_aux Field.print_ml ": sig"
  let print_c_impl fmt st =
    if not st.ptr then (
      fprintf fmt "%s\n{\n" st.c_of_ml;
      fprintf fmt "        %s x;\n" st.c_name;
      let aux i f = Field.print_c_of_ml "x" false "v" i fmt f; i + 1 in
      ignore (List.fold_left aux 0 st.fields);
      fprintf fmt "        return x;\n}\n\n";
    );
    fprintf fmt "%s\n{\n" st.ml_of_c;
    fprintf fmt "        CAMLlocal1(v);\n";
    fprintf fmt "        v = caml_alloc(%d, 0);\n" (List.length st.fields);
    let aux i f = Field.print_ml_of_c "v" i "x" st.ptr fmt f; i + 1 in
    ignore (List.fold_left aux 0 st.fields);
    fprintf fmt "        CAMLreturn(v);\n}\n\n"
  let print_c_header fmt st =
    fprintf fmt "%s;\n" st.c_of_ml;
    fprintf fmt "%s;\n" st.ml_of_c
end

module Section : sig
  type t
  val create : Tys.t -> Expr.section -> t
  val print_ml : formatter -> t -> unit
  val print_mli : formatter -> t -> unit
  val print_c_impl : formatter -> t -> unit
  val print_c_header : formatter -> t -> unit
end = struct
  type t = {
    name : string;
    sts : St.t list;
  }
  let create env e =
    let name = e.Expr.Section.name in
    let sts = List.map (St.create env) e.Expr.Section.sts in
    {name; sts}
  let print_ml fmt sec =
    fprintf fmt "module %s = struct\n\n" sec.name;
    List.iter (St.print_ml fmt) sec.sts;
    fprintf fmt "\nend\n\n"
  let print_aux print fmt sec = List.iter (print fmt) sec.sts
  let print_mli = print_aux St.print_mli
  let print_c_impl = print_aux St.print_c_impl
  let print_c_header = print_aux St.print_c_header
end

module Sections : sig
  type t
  val create : Tys.t -> Expr.t -> t
  val print_ml : formatter -> t -> unit
  val print_mli : formatter -> t -> unit
  val print_c_impl : formatter -> t -> unit
  val print_c_header : formatter -> t -> unit
end = struct
  type t = Section.t list
  let create env = List.map (Section.create env)
  let print_aux print fmt = List.iter (print fmt)
  let print_ml = print_aux Section.print_ml
  let print_mli = print_aux Section.print_mli
  let print_c_impl = print_aux Section.print_c_impl
  let print_c_header = print_aux Section.print_c_header
end

let write_file filename prolog print x =
  let ch = open_out filename in
  let fmt = formatter_of_out_channel ch in
  fprintf fmt "%s\n" prolog;
  print fmt x;
  fprintf fmt "%!";
  close_out ch

let read_file filename =
  let ch = open_in filename in
  let lexbuf = Lexing.from_channel ch in
  let e = Parser.expr Lexer.token lexbuf in
  close_in ch;
  e


let ( / ) = Filename.concat

let create_env () =
  let list = [
    {Ty.name = "int"; ml_name = "int"; c_name = "int";
      c_of_ml = "Int_val"; ml_of_c = "Val_int"; base = true};
    {Ty.name = "evas_point"; ml_name = "Evas.point"; c_name = "Evas_point";
      c_of_ml = "Evas_Point_val"; ml_of_c = "copy_Evas_Point"; base = false;}
  ] in
  List.fold_left Tys.add Tys.empty list

let env = create_env ()

let () =
  let e = read_file ("src" / "write_struct" / "structs.txt") in
  let secs = Sections.create env e in
  write_file ("src" / "hstructs.ml") "" Sections.print_ml secs;
  write_file ("src" / "write_struct" / "help.mli") "" Sections.print_mli secs;
  write_file ("src" / "structs_wrap.c") "#include \"include.h\""
    Sections.print_c_impl secs;
  write_file ("src" / "structs_wrap.h") "" Sections.print_c_header secs;
  exit 0

