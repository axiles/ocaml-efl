open Format
module Ty = struct
  type t = {
    name : string;
    ml_name : string;
    c_name : string;
    ml_of_c : string;
    c_of_ml : string;
    base : bool;
  }
end

module Fun : sig
  type res = Simple of Ty.t | Unit
  type arg = Ty.t
  type t = {
    ml_name : string;
    c_name : string;
    args : arg list;
    res : res
  }
  val print_ml : formatter -> t -> unit
  val print_c : formatter -> t -> unit
end = struct
  type res = Simple of Ty.t | Unit
  type arg = Ty.t
  type t = {
    ml_name : string;
    c_name : string;
    args : arg list;
    res : res
  }
  let print_ml fmt f =
    fprintf fmt "external %s : " f.ml_name;
    let string_of_ty ty =
      if ty.Ty.base then ty.Ty.ml_name else sprintf "T.%s" ty.Ty.name in
    List.iter (fun ty -> fprintf fmt "%s -> " (string_of_ty ty)) f.args;
    (match f.res with
    | Simple ty -> fprintf fmt " %s = " (string_of_ty ty)
    | Unit -> fprintf fmt " unit = ");
    if List.length f.args <= 5 then fprintf fmt "\"ml_%s\"\n\n" f.c_name
    else fprintf fmt "\"ml_%s_byte\" \"ml_%s_native\"\n\n" f.c_name f.c_name
  let print_seq sep fmt list =
    match list with
    | [] -> ()
    | x :: xs ->
      fprintf fmt "%s" x;
      let aux y = fprintf fmt "%s%s" sep y in
      List.iter aux xs
  let take_5_max list =
    match list with
    | [] | [_] | [_; _] | [_; _; _] | [_; _; _; _] -> (list, [])
    | x1 :: x2 :: x3 :: x4 :: x5 :: q -> ([x1; x2; x3; x4; x5], q)
  let print_call fmt (name, list) =
    fprintf fmt "%s(%a)" name (print_seq ", ") list
  let print_call_num fmt (name, list) =
    let n = List.length list in
    print_call fmt ((sprintf "%s%d" name n), list)
  let rec print_caml_xxx name fmt list =
    let (list1, list2) = take_5_max list in
    fprintf fmt "%a;\n" print_call_num (name, list1);
    match list2 with
    | [] -> ()
    | _ :: _ -> print_caml_xxx name fmt list2
  let print_caml_local = print_caml_xxx "CAMLlocal"
  let print_caml_xparam = print_caml_xxx "CAMLxparam"
  let print_caml_param fmt list =
    let (list1, list2) = take_5_max list in
    fprintf fmt "%a;\n" print_call_num ("CAMLparam", list1);
    (match list2 with
    | [] -> ()
    | _ :: _ -> print_caml_xparam fmt list2)
  let init_list n f =
    let rec aux accu k =
      if k < 0 then accu
      else aux (f k :: accu) (k - 1) in
    aux [] (n - 1)
  let mapi f list =
    let rec aux i = function
      | [] -> []
      | x :: xs -> f i x :: aux (i + 1) xs in
    aux 0 list
  let print_c_aux name fmt f =
    let args = mapi (fun i ty -> (sprintf "x%d" i, ty)) f.args in
    let aux1 (x, ty) = sprintf "value %s" x in
    fprintf fmt "PREFIX value %a\n{\n" print_call (name, List.map aux1 args);
    let aux2 (x, ty) = sprintf "%s(%s)" ty.Ty.c_of_ml x in
    (match f.res with
    | Simple ty ->
      fprintf fmt "        return %s(%a);\n" ty.Ty.ml_of_c print_call
        (f.c_name, List.map aux2 args)
    | Unit -> 
      fprintf fmt "        %a;\n" print_call (f.c_name, List.map aux2 args);
      fprintf fmt "        return Val_unit;\n");
    fprintf fmt "}\n\n"
  let print_c_aux_byte fmt f =
    fprintf fmt "PREFIX value ml_%s_byte(value* argv, int argn)\n{\n" f.c_name;
    let aux i _ = sprintf "argv[%d]" i in
    fprintf fmt "        return %a;\n}\n\n" print_call
      (sprintf "ml_%s_native" f.c_name, mapi aux f.args)
  let print_c fmt f =
    if List.length f.args <= 5 then print_c_aux (sprintf "ml_%s" f.c_name) fmt f
    else (
      print_c_aux (sprintf "ml_%s_native" f.c_name) fmt f;
      print_c_aux_byte fmt f
    )
end

module Section : sig
  type t
  val create : string -> Fun.t list list -> t
  val print_c : formatter -> t -> unit
  val print_ml : formatter -> t -> unit
end = struct
  module StringSet = Set.Make (struct
    type t = string
    let compare : string -> string -> int = compare
  end)
  type t = {
    name : string;
    c_prefix : string;
    funs : Fun.t list;
    params : StringSet.t;
  }
  let create name list =
    let c_prefix = String.lowercase name in
    let aux1 accu f =
      {f with Fun.c_name = sprintf "%s_%s" c_prefix f.Fun.c_name} :: accu in
    let aux2 accu list1 = List.fold_left aux1 accu list1 in
    let funs = List.rev (List.fold_left aux2 [] list) in
    let add_ty set ty =
      if not ty.Ty.base then StringSet.add ty.Ty.name set else set in
    let aux3 = add_ty in
    let aux4 accu f =
      let accu1 = List.fold_left aux3 accu f.Fun.args in
      let accu2 = match f.Fun.res with
      | Fun.Simple ty -> add_ty accu1 ty
      | Fun.Unit -> accu1 in
      accu2 in
    let params = List.fold_left aux4 StringSet.empty funs in
    {name; c_prefix; funs; params}
  let print_c fmt sec = List.iter (Fun.print_c fmt) sec.funs
  let print_ml fmt sec =
    fprintf fmt "module %s = struct\n\n" sec.name;
    fprintf fmt "module type S = sig\n";
    StringSet.iter (fun s -> fprintf fmt "type %s\n" s) sec.params;
    fprintf fmt "end\n\n";
    fprintf fmt "module F (T : S) = struct\n\n";
    List.iter (Fun.print_ml fmt) sec.funs;
    fprintf fmt "end\n\nend\n\n"
end

module Sections : sig
  type t
  val create : (string * Fun.t list list) list -> t
  val print_ml : formatter -> t -> unit
  val print_c : formatter -> t -> unit
end = struct
  type t = Section.t list
  let create = List.map (fun (s, l) -> Section.create s l)
  let print_ml fmt = List.iter (Section.print_ml fmt)
  let print_c fmt list =
    fprintf fmt "#include \"include.h\"\n\n";
    List.iter (Section.print_c fmt) list
end

open Ty

let int = {
  name = "int";
  ml_name = "int";
  c_name = "int";
  c_of_ml = "Int_val";
  ml_of_c = "Val_int";
  base = true;
}

let bool = {
  name = "bool";
  ml_name = "bool";
  c_name = "Eina_Bool";
  c_of_ml = "Bool_val";
  ml_of_c = "Val_bool";
  base = true;
}

let double = {
  name = "double";
  ml_name = "float";
  c_name = "double";
  c_of_ml = "Double_val";
  ml_of_c = "copy_double";
  base = true;
}

let unix_tm = {
  name = "unix_tm";
  ml_name = "Unix.tm";
  c_name = "struct tm";
  c_of_ml = "Tm_val";
  ml_of_c = "Val_Tm";
  base = true;
}

let safe_string = {
  name = "safe_string";
  ml_name = "string";
  c_name = "const char*";
  c_of_ml = "String_val";
  ml_of_c = "safe_copy_string";
  base = true;
}

let simple_ty first second =
  let c_name = sprintf "%s_%s" first second in
  let name = String.lowercase c_name in
  let ml_name =
    let s1 = String.lowercase first in
    let s2 = String.lowercase second in
    s1.[0] <- Char.uppercase s1.[0];
    let s2 = match s2 with
    | "option" -> "opt"
    | "object" -> "obj"
    | _ -> s2 in
    sprintf "%s.%s" s1 s2 in
  let c_of_ml = sprintf "%s_val" c_name in
  let ml_of_c = sprintf "Val_%s" c_name in
  {name; ml_name; c_name; c_of_ml; ml_of_c; base = false}

let flags_ty first second =
  let c_name = sprintf "%s_%s" first second in
  let name = String.lowercase c_name in
  let name_ = sprintf "%s_" name in
  let name = sprintf "%s_list" name in
  let ml_name, ml_name_ =
    let s1 = String.lowercase first in
    let s2 = String.lowercase second in
    s1.[0] <- Char.uppercase s1.[0];
    let s3 = sprintf "%s.%s" s1 s2 in
    (sprintf "%s list" s3, sprintf "%s_" s3) in
  let c_of_ml = sprintf "%s_val_list" c_name in
  let ml_of_c = sprintf "copy_%s" c_name in
  let ty1 = {name; c_name; ml_name; c_of_ml; ml_of_c = "NOT IMPLEMENTED";
    base = false} in
  let ty2 = {name = name_; c_name; ml_name = ml_name_;
    c_of_ml = "NOT IMPLEMENTED"; ml_of_c; base = false} in
  (ty1, ty2)


let evas_object = simple_ty "Evas" "Object"
let elm_object_item = simple_ty "Elm_Object" "Item"
let elm_map_overlay = simple_ty "Elm_Map" "Overlay"
let elm_map_route = simple_ty "Elm_Map" "Route"
let elm_map_name = simple_ty "Elm_Map" "Name"
let elm_bg_option = simple_ty "Elm_Bg" "Option"
let elm_bubble_pos = simple_ty "Elm_Bubble" "Pos"
let elm_calendar_select_mode = simple_ty "Elm_Calendar" "Select_Mode"
let elm_calendar_mark = simple_ty "Elm_Calendar" "Mark"
let elm_calendar_mark_repeat_type = simple_ty "Elm_Calendar" "Mark_Repeat_Type"
let elm_calendar_weekday = simple_ty "Elm_Calendar" "Weekday"
let elm_colorselector_mode = simple_ty "Elm_Colorselector" "Mode"
let elm_datetime_field_type = simple_ty "Elm_Datetime" "Field_Type"
let elm_dayselector_day = simple_ty "Elm_Dayselector" "Day"
let elm_wrap_type = simple_ty "Elm" "Wrap_Type"
let elm_text_format = simple_ty "Elm" "Text_Format"
let elm_input_panel_layout = simple_ty "Elm" "Input_Panel_Layout"
let elm_autocapital_type = simple_ty "Elm" "Autocapital_Type"
let elm_input_panel_lang = simple_ty "Elm" "Input_Panel_Lang"
let elm_input_panel_return_key_type =
  simple_ty "Elm" "Input_Panel_Return_Key_Type"
let elm_cnp_mode = simple_ty "Elm" "Cnp_Mode"
let elm_flip_mode = simple_ty "Elm_Flip" "Mode"
let elm_flip_interaction = simple_ty "Elm_Flip" "Interaction"
let elm_flip_direction = simple_ty "Elm_Flip" "Direction"
let elm_gengrid_item_scrollto_type =
  simple_ty "Elm_Gengrid" "Item_Scrollto_Type"
let elm_object_select_mode = simple_ty "Elm_Object" "Select_Mode"
let elm_list_mode = simple_ty "Elm_List" "Mode"
let elm_genlist_item_scrollto_type =
  simple_ty "Elm_Genlist" "Item_Scrollto_Type"
let elm_genlist_item_field_type = simple_ty "Elm_Genlist" "Item_Field_Type"
let elm_genlist_item_type = simple_ty "Elm_Genlist" "Item_Type"
let elm_glview_resize_policy = simple_ty "Elm_GLView" "Resize_Policy"
let elm_glview_render_policy = simple_ty "Elm_GLView" "Render_Policy"
let elm_icon_lookup_order = simple_ty "Elm_Icon" "Lookup_Order"
let elm_image_orient = simple_ty "Elm_Image" "Orient"
let elm_map_zoom_mode = simple_ty "Elm_Map" "Zoom_Mode"
let elm_map_overlay_type = simple_ty "Elm_Map" "Overlay_Type"
let elm_map_source_type = simple_ty "Elm_Map" "Source_Type"
let elm_panel_orient = simple_ty "Elm_Panel" "Orient"
let evas_load_error = simple_ty "Evas" "Load_Error"
let elm_photocam_zoom_mode = simple_ty "Elm_Photocam" "Zoom_Mode"
let elm_scroller_policy = simple_ty "Elm_Scroller" "Policy"
let elm_scroller_single_direction = simple_ty "Elm_Scroller" "Single_Direction"
let ethumb_thumb_aspect = simple_ty "Ethumb" "Thumb_Aspect"
let ethumb_thumb_fdo_size = simple_ty "Ethumb" "Thumb_FDO_Size"
let ethumb_thumb_format = simple_ty "Ethumb" "Thumb_Format"
let ethumb_thumb_orientation = simple_ty "Ethumb" "Thumb_Orientation"
let elm_thumb_animation_setting = simple_ty "Elm_Thumb" "Animation_Setting"
let elm_icon_lookup_order = simple_ty "Elm_Icon" "Lookup_Order"
let elm_toolbar_shrink_mode = simple_ty "Elm_Toolbar" "Shrink_Mode"
let elm_toolbar_item_state = simple_ty "Elm_Toolbar" "Item_State"
let elm_transit = simple_ty "Elm" "Transit"
let elm_transit_tween_mode = simple_ty "Elm_Transit" "Tween_Mode"
let elm_transit_effect_flip_axis = simple_ty "Elm_Transit" "Effect_Flip_Axis"
let elm_transit_effect_wipe_type = simple_ty "Elm_Transit" "Effect_Wipe_Type"
let elm_transit_effect_wipe_dir = simple_ty "Elm_Transit" "Effect_Wipe_Dir"
let elm_web_window_features = simple_ty "Elm_Web" "Window_Features"
let elm_web_window_feature_flag = simple_ty "Elm_Web" "Window_Feature_Flag"
let elm_web_zoom_mode = simple_ty "Elm_Web" "Zoom_Mode"

let elm_calendar_selectable = flags_ty "Elm_Calendar" "Selectable"
let elm_clock_edit_mode = flags_ty "Elm_Clock" "Edit_Mode"
let elm_scroller_movement_block = flags_ty "Elm_Scroller" "Movement_Block"

let simple name list res = {
  Fun.ml_name = name;
  c_name = name;
  args = list;
  res = Fun.Simple res
}

let simple_unit name list = {
  Fun.ml_name = name;
  c_name = name;
  args = list;
  res = Fun.Unit;
}

let prop ?(args = [evas_object]) name ty =
  [simple_unit (sprintf "%s_set" name) (args @ [ty]);
    simple (sprintf "%s_get" name) args ty
  ]

let prop_flags name (ty1, ty2) =
  [simple_unit (sprintf "%s_set" name) [evas_object; ty1];
    simple (sprintf "%s_get" name) [evas_object] ty2;
  ]

let _simple = simple

let _simple_unit = simple_unit

let simple name list res = [simple name list res]

let simple_unit name list = [simple_unit name list]

