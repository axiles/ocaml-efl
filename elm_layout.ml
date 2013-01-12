external add : Evas.obj -> Evas.obj =
  "ml_elm_layout_add"

external file_set_with_bool : Evas.obj -> string -> string -> bool =
  "ml_elm_layout_file_set_with_bool"

let file_set obj file group =
  if not (file_set_with_bool obj file group) then
    failwith "elm_layout_file_set"

external theme_set_with_bool : Evas.obj -> string -> string -> string -> bool =
  "ml_elm_layout_theme_set_with_bool"

let theme_set obj clas group style =
  if not (theme_set_with_bool obj clas group style) then
    failwith "ml_elm_layout_theme"

external signal_emit : Evas.obj -> string -> string -> unit =
  "ml_elm_layout_signal_emit"

external signal_callback_add :
  Evas.obj -> string -> string -> Edje.signal_cb -> unit =
  "ml_elm_layout_signal_callback_add"

external signal_callback_del :
  Evas.obj -> string -> string -> Edje.signal_cb -> unit =
  "ml_elm_layout_signal_callback_del"

external box_append_with_bool : Evas.obj -> string -> Evas.obj -> bool =
  "ml_elm_layout_box_append_with_bool"

let box_append obj part child =
  if not (box_append_with_bool obj part child) then
    failwith "elm_layout_box_append"

external box_prepend_with_bool : Evas.obj -> string -> Evas.obj -> bool =
  "ml_elm_layout_box_prepend_with_bool"

let box_prepend obj part child =
  if not (box_prepend_with_bool obj part child) then
    failwith "elm_layout_box_prepend"

external box_insert_before_with_bool :
  Evas.obj -> string -> Evas.obj -> Evas.obj -> bool =
  "ml_elm_layout_box_insert_before_with_bool"

let box_insert_before obj part child ref =
  if not (box_insert_before_with_bool obj part child ref) then
    failwith "elm_layout_box_insert_before"

external box_insert_at_with_bool :
  Evas.obj -> string -> Evas.obj -> int -> bool =
  "ml_elm_layout_box_insert_at_with_bool"

let box_insert_at obj part child pos =
  if not (box_insert_at_with_bool obj part child pos) then
    failwith "elm_layout_box_insert_at"

external box_remove : Evas.obj -> string -> Evas.obj -> Evas.obj option =
  "ml_elm_layout_box_remove"

external box_remove_all_with_bool : Evas.obj -> string -> bool -> bool =
  "ml_elm_layout_box_remove_all_with_bool"

let box_remove_all obj part clear =
  if not (box_remove_all_with_bool obj part clear) then
    failwith "elm_layout_box_remove_all"

external table_pack_with_bool :
  Evas.obj -> string -> Evas.obj -> int -> int -> int -> int -> bool =
  "ml_elm_layout_table_pack_with_bool_byte"
  "ml_elm_layout_table_pack_with_bool_native"

let table_pack obj part child col row colspan rowspan =
  if not (table_pack_with_bool obj part child col row colspan rowspan) then
    failwith "elm_layout_table_pack"

external table_unpack : Evas.obj -> string -> Evas.obj -> Evas.obj option =
  "ml_elm_layout_table_unpack"

external table_clear_with_bool : Evas.obj -> string -> bool -> bool =
  "ml_elm_layout_table_clear_with_bool"

let table_clear obj part clear =
  if not (table_clear_with_bool obj part clear) then
    failwith "elm_layout_table_clear"

external edje_get : Evas.obj -> Evas.obj =
  "ml_elm_layout_edje_get"

external data_get : Evas.obj -> string -> string option =
  "ml_elm_layout_data_get"

external sizing_eval : Evas.obj -> unit =
  "ml_elm_layout_sizing_eval"

external part_cursor_set_with_bool : Evas.obj -> string -> string -> bool =
  "ml_elm_layout_part_cursor_set_with_bool"

let part_cursor_set obj part_name cursor =
  if not (part_cursor_set_with_bool obj part_name cursor) then
    failwith "elm_layout_part_cursor_set"

external part_cursor_get : Evas.obj -> string -> string =
  "ml_elm_layout_part_cursor_get"

external part_cursor_unset_with_bool : Evas.obj -> string -> bool =
  "ml_elm_layout_part_cursor_unset_with_bool"

let part_cursor_unset obj part_name =
  if not (part_cursor_unset_with_bool obj part_name) then
    failwith "elm_mayout_part_cursor_unset"

external part_cursor_style_set_with_bool :
  Evas.obj -> string -> string -> bool =
  "ml_elm_layout_part_cursor_style_set_with_bool"

let part_cursor_style_set obj part_name style =
  if not (part_cursor_style_set_with_bool obj part_name style) then
    failwith "elm_layout_cursor_style_set"

external part_cursor_style_get : Evas.obj -> string -> string option =
  "ml_elm_layout_part_cursor_style_get"

external part_cursor_engine_only_set_with_bool :
  Evas.obj -> string -> bool -> bool =
  "ml_elm_layout_part_cursor_engine_only_set_with_bool"

let part_cursor_engine_only_set obj part_name flag =
  if not (part_cursor_engine_only_set_with_bool obj part_name flag) then
    failwith "elm_layout_part_cursor_engine_only_set"

