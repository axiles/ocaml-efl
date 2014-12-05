open Format

let string_iteri f s =
  for i = 0 to String.length s - 1 do
    f i s.[i]
  done

(* Forward compatible implementation of String.mapi *)
let string_mapi f s =
  let buf = Buffer.create (String.length s) in
  let aux i c = Buffer.add_char buf (f i c) in
  string_iteri aux s;
  Buffer.contents buf
  
let elm_eo_class_obj = Array.length Sys.argv >= 3

module Event_info : sig
  type t = {
    input : bool;
    c_name : string;
    cb_name : string;
    ml_name : string;
    conv : string option;
  }
  val print_c_impl : formatter -> t -> unit
end = struct
  type t = {
    input : bool;
    c_name : string;
    cb_name : string;
    ml_name : string;
    conv : string option;
  }
  let print_c_impl_in fmt ei =
    fprintf fmt "void %s(void* data, Evas_Object* obj, void* event_info)\n"
      ei.cb_name;
    fprintf fmt "{\n";
    fprintf fmt "        CAMLparam0();\n";
    fprintf fmt "        CAMLlocal1(v_ei);\n";
    fprintf fmt "        value* v_fun = (value*) data;\n";
    fprintf fmt "        %s ei = (%s) event_info;\n" ei.c_name ei.c_name;
    (match ei.conv with
    | None -> fprintf fmt "        v_ei = (value) ei;\n";
    | Some x -> fprintf fmt "        v_ei = %s(ei);\n" x);
    fprintf fmt "        caml_callback2(*v_fun, (value) obj, v_ei);\n";
    fprintf fmt "        CAMLreturn0;\n";
    fprintf fmt "}\n\n"
  let print_c_impl_out fmt ei =
    fprintf fmt "void %s(void* data, Evas_Object* obj, void* event_info)\n"
      ei.cb_name;
    fprintf fmt "{\n";
    fprintf fmt "        CAMLparam0();\n";
    fprintf fmt "        CAMLlocal1(v_r);\n";
    fprintf fmt "        value* v_fun = (value*) data;\n";
    fprintf fmt "        v_r = caml_callback(*v_fun, (value) obj);\n";
    (match ei.conv with
    | None -> fprintf fmt "        %s r = (%s) v_r;\n" ei.c_name ei.c_name
    | Some x -> fprintf fmt "        %s r = %s(v_r);\n" ei.c_name x);
    fprintf fmt "        %s* ei = (%s*) event_info;\n" ei.c_name ei.c_name;
    fprintf fmt "        *ei = r;\n";
    fprintf fmt "        CAMLreturn0;\n";
    fprintf fmt "}\n\n"
  let print_c_impl fmt ei =
    let f = if ei.input then print_c_impl_in else print_c_impl_out in
    f fmt ei
end

module Env : sig
  type t
  val empty : t
  val add : t -> string -> Event_info.t -> t
  val of_list : (string * Event_info.t) list -> t
  val find : t -> string -> Event_info.t option
  val print_c_impl : formatter -> t -> unit
end = struct
  module MapString = Map.Make(struct type t = string let compare = compare end)
  type t = Event_info.t MapString.t
  let empty = MapString.empty
  let add env name ei = MapString.add name ei env
  let of_list list = List.fold_left (fun accu (s, x) -> add accu s x) empty list
  let find env name = try Some (MapString.find name env) with Not_found -> None
  let print_c_impl fmt env =
    let aux name ei = Event_info.print_c_impl fmt ei in
    MapString.iter aux env
end

module Signal : sig
  type ty = Event_info.t option
  type t = private {name : string; ml_name : string; ty : ty}
  val create : Expr.Signal.t -> Env.t -> t
  val print_ml_sig : formatter -> t -> unit
  val print_ml_impl : t -> formatter -> string -> unit
  val print_c_impl : t -> string -> formatter -> string -> unit
end = struct
  type ty = Event_info.t option
  type t = {name : string; ml_name : string; ty : ty}
  let ml_name_of_name name =
    let ml_name = String.sub name 1 (String.length name - 2) in
    let aux i c = if c = ',' then '_' else c in
    let ml_name = string_mapi aux ml_name in
    match ml_name with
    | "end" | "done" -> sprintf "_%s" ml_name
    | _ -> ml_name
  let create e env =
    let name = e.Expr.Signal.name in
    let ml_name = ml_name_of_name name in
    let ty = match e.Expr.Signal.ty with
    | None -> None
    | Some ei_name ->
      (match Env.find env ei_name with
      | Some x -> Some x
      | None -> failwith (sprintf "Unknown kind of event_info: %s" ei_name)) in
    {name; ml_name; ty}
  let print_cb_type fmt s =
    match s.ty with
    | None -> fprintf fmt "Evas.obj -> unit"
    | Some ei when ei.Event_info.input ->
       fprintf fmt "Evas.obj -> %s -> unit" ei.Event_info.ml_name
    | Some ei -> fprintf fmt "Evas.obj -> %s" ei.Event_info.ml_name
  let print_type fmt s =
    fprintf fmt "Evas.obj -> (%a) -> unit" print_cb_type s
  let print_ml_sig fmt s =
    fprintf fmt "val %s : %a" s.ml_name print_type s
  let get_external_name s widget_name =
    sprintf "ml_connect_%s_%s" widget_name s.ml_name
  let print_ml_impl s fmt widget_name =
    fprintf fmt "external %s : %a = \"%s\"" s.ml_name print_type s
      (get_external_name s widget_name)
  let print_c_impl s widget_name fmt eo_name =
    fprintf fmt "PREFIX value %s(value v_obj, value v_cb) {\n"
      (get_external_name s widget_name);
    fprintf fmt "        Evas_Object* obj = (Evas_Object*) v_obj;\n";
    fprintf fmt "#ifdef EFL_EO_API_SUPPORT\n";
    fprintf fmt "        if(!eo_isa(obj, %s)) \
                           caml_failwith(\"Widget is not a %s\");\n"
      eo_name widget_name;
    fprintf fmt "#endif\n";
    fprintf fmt
      "        value* data = ml_Evas_Object_register_value(obj, v_cb);\n";
    let cb_name = match s.ty with
    | None -> "ml_Evas_Smart_Cb_connect_unit"
    | Some ei -> ei.Event_info.cb_name in
    fprintf fmt
      "        evas_object_smart_callback_add(obj, %s, %s, data);\n"
      s.name cb_name;
    fprintf fmt "return Val_unit;\n";
    fprintf fmt "}\n\n"
end

module Widget : sig
  type t = private {
    ml_name : string;
    eo_name : string;
    signals : Signal.t list
  }
  val create : string -> Env.t -> t
  val print_ml_sig : formatter -> t -> unit
  val print_ml_impl : formatter -> t -> unit
  val print_c_impl : formatter -> t -> unit
end = struct
  type t = {
    ml_name : string;
    eo_name : string;
    signals : Signal.t list
  }
  let ml_name_of_name name =
    let aux i c = if i = 0 then Char.uppercase c else c in
    string_mapi aux name
  let get_expr name =
    let ( / ) = Filename.concat in
    let filename = "src" / "write_connect" / (sprintf "%s.txt" name) in
    let ch = open_in filename in
    let lexbuf = Lexing.from_channel ch in
    let e = Parser.widget Lexer.token lexbuf in
    close_in ch;
    e
  let replace_prefix s p1 p2 =
    let n = String.length s and m = String.length p1 in
    if n < m then s
    else if String.sub s 0 m = p1 then
      sprintf "%s%s" p2 (String.sub s m (n - m))
    else s
  let create name env =
    let e = get_expr name in
    let ml_name = ml_name_of_name name in
    let eo_name = e.Expr.name in
    let eo_name =
      if not elm_eo_class_obj then replace_prefix eo_name "ELM_OBJ" "ELM"
      else eo_name in
    let eo_name =
      if not elm_eo_class_obj && eo_name = "ELM_WIN_INWIN_CLASS" then
        "ELM_WIN_CLASS" else eo_name in
    let signals = List.map (fun e1 -> Signal.create e1 env) e.Expr.signals in
    {ml_name; eo_name; signals}
  let print_ml_sig fmt w =
    fprintf fmt "module %s : sig\n" w.ml_name;
    let f s = fprintf fmt " %a\n\n" Signal.print_ml_sig s in
    List.iter f w.signals;
    fprintf fmt "end\n\n"
  let print_ml_impl fmt w =
    fprintf fmt "module %s = struct\n" w.ml_name;
    let f s = fprintf fmt "%a\n\n" (Signal.print_ml_impl s) w.ml_name in
    List.iter f w.signals;
    fprintf fmt "end\n\n"
  let print_c_impl fmt w =
    let f s =
      fprintf fmt "%a\n\n" (Signal.print_c_impl s w.ml_name) w.eo_name in
    List.iter f w.signals
end

let print_cb_unit fmt =
  fprintf fmt "

#include \"include.h\"

void ml_Evas_Smart_Cb_connect_unit(
        void* data, Evas_Object* obj, void* event_info)
{
        value* v_fun = (value*) data;
        caml_callback(*v_fun, (value) obj);
}

"

let create_env () =
  let env = Env.empty in
  let open Event_info in
  let add env (name, c_name, ml_name, conv_name) =
    let cb_name = sprintf "ml_Evas_Smart_Cb_connect_%s" name in
    let ei = {input = true; c_name; ml_name; cb_name; conv = Some conv_name} in
    Env.add env name ei in
  let add_cast env (name, c_name, ml_name) =
    let cb_name = sprintf "ml_Evas_Smart_Cb_connect_%s" name in
    let ei = {input = true; c_name; ml_name; cb_name; conv = None} in
    Env.add env name ei in
  let add_ref env (name, c_name, ml_name, conv_name) =
    let cb_name = sprintf "ml_Evas_Smart_Cb_connect_%s" name in
    let ei = {input = false; c_name; ml_name; cb_name; conv = Some conv_name} in
    Env.add env name ei in
  let env1 = List.fold_left add env [
    ("string_opt", "const char*", "string option", "copy_string_opt");
    ("anchor", "Elm_Entry_Anchor_Info*", "Elm_entry.anchor_info",
      "copy_Elm_Entry_Anchor_Info");
    ("string", "const char*", "string", "copy_string");
    ("download", "Elm_Web_Download*", "Elm_web.download",
      "copy_Elm_Web_Download");
    ("bool", "Eina_Bool*", "bool", "Val_Eina_Bool_ptr");
    ("string_string", "char**", "string * string", "copy_string_string");
    ("frame_load_error", "Elm_Web_Frame_Load_Error*",
      "Elm_web.frame_load_error", "copy_Elm_Web_Frame_Load_Error");
    ("frame_load_error_opt", "Elm_Web_Frame_Load_Error*",
      "Elm_web.frame_load_error option", "copy_Elm_Web_Frame_Load_Error_opt");
    ("float", "double*", "float", "copy_double_ptr");
    ("web_menu", "Elm_Web_Menu*", "Elm_web.menu", "copy_Elm_Web_Menu");
    ("coord_size", "Evas_Coord_Size*", "int * int", "copy_Evas_Coord_Size");
    ("day", "Elm_Dayselector_Day", "Elm_dayselector.day",
      "Val_Elm_Dayselector_Day");
  ] in
  let env2 = List.fold_left add_cast env1 [
    ("item", "Elm_Object_Item*", "Elm_object.item");
    ("evas_obj", "Evas_Object*", "Evas.obj");
  ] in
  List.fold_left add_ref env2 [("bool_ref", "Eina_Bool", "bool", "Bool_val")]

let () =
  let ( / ) = Filename.concat in
  let filename = "src" / "write_connect" / "widgets.txt" in
  let ch = open_in filename in
  let ch_ml_sig = open_out ("src" / "elm_connect.mli") in
  let ch_ml_impl = open_out ("src" / "elm_connect.ml") in
  let ch_c_impl = open_out ("src" / "elm_connect_wrap.c") in 
  let fmt_ml_sig = formatter_of_out_channel ch_ml_sig in
  let fmt_ml_impl = formatter_of_out_channel ch_ml_impl in
  let fmt_c_impl = formatter_of_out_channel ch_c_impl in
  let env = create_env () in
  print_cb_unit fmt_c_impl;
  Env.print_c_impl fmt_c_impl env;
  fprintf fmt_ml_sig "(** Connect widgets and signals *)\n\n";
  (try while true do
    let widget_name = input_line ch in
    let w = Widget.create widget_name env in
    Widget.print_ml_sig fmt_ml_sig w;
    Widget.print_ml_impl fmt_ml_impl w;
    Widget.print_c_impl fmt_c_impl w;
  done with End_of_file -> ());
  fprintf fmt_ml_sig "%!";
  fprintf fmt_ml_impl "%!";
  fprintf fmt_c_impl "%!";
  close_out ch_ml_sig;
  close_out ch_ml_impl;
  close_out ch_c_impl;
  close_in ch;
  exit 0

