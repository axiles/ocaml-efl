external add : Evas.obj -> Evas.obj =
  "ml_elm_layout_add"

external file_set : Evas.obj -> string -> string -> bool =
  "ml_elm_layout_file_set"

external theme_set : Evas.obj -> string -> string -> string -> bool =
  "ml_elm_layout_theme_set"

external signal_emit : Evas.obj -> string -> string -> unit =
  "ml_elm_layout_signal_emit"

external signal_callback_add :
  Evas.obj -> string -> string -> Edje.signal_cb -> unit =
  "ml_elm_layout_signal_callback_add"

external signal_callback_del :
  Evas.obj -> string -> string -> Edje.signal_cb -> unit =
  "ml_elm_layout_signal_callback_del"

external box_append : Evas.obj -> string -> Evas.obj -> bool =
  "ml_elm_layout_box_append"

external box_prepend : Evas.obj -> string -> Evas.obj -> bool =
  "ml_elm_layout_box_prepend"

external box_insert_before :
  Evas.obj -> string -> Evas.obj -> Evas.obj -> bool =
  "ml_elm_layout_box_insert_before"

external box_insert_at :
  Evas.obj -> string -> Evas.obj -> int -> bool = "ml_elm_layout_box_insert_at"

external box_remove : Evas.obj -> string -> Evas.obj -> Evas.obj option =
  "ml_elm_layout_box_remove"

external box_remove_all : Evas.obj -> string -> bool -> bool =
  "ml_elm_layout_box_remove_all"

external table_pack :
  Evas.obj -> string -> Evas.obj -> int -> int -> int -> int -> bool =
  "ml_elm_layout_table_pack_byte"
  "ml_elm_layout_table_pack_native"

external table_unpack : Evas.obj -> string -> Evas.obj -> Evas.obj option =
  "ml_elm_layout_table_unpack"

external table_clear : Evas.obj -> string -> bool -> bool =
  "ml_elm_layout_table_clear"

external edje_get : Evas.obj -> Evas.obj =
  "ml_elm_layout_edje_get"

external data_get : Evas.obj -> string -> string option =
  "ml_elm_layout_data_get"

external sizing_eval : Evas.obj -> unit =
  "ml_elm_layout_sizing_eval"

external part_cursor_set : Evas.obj -> string -> string -> bool =
  "ml_elm_layout_part_cursor_set"

external part_cursor_get : Evas.obj -> string -> string =
  "ml_elm_layout_part_cursor_get"

external part_cursor_unset : Evas.obj -> string -> bool =
  "ml_elm_layout_part_cursor_unset"

external part_cursor_style_set : Evas.obj -> string -> string -> bool =
  "ml_elm_layout_part_cursor_style_set"

external part_cursor_style_get : Evas.obj -> string -> string option =
  "ml_elm_layout_part_cursor_style_get"

external part_cursor_engine_only_set : Evas.obj -> string -> bool -> bool =
  "ml_elm_layout_part_cursor_engine_only_set"

external part_cursor_engine_only_get : Evas.obj -> string -> bool =
  "ml_elm_layout_part_cursor_engine_only_get"

external icon_set : Evas.obj -> Evas.obj -> unit = "ml_elm_layout_icon_set"

let icon_get ly = Elm_object.part_content_get ly ~p:"elm.swallow.icon" ()

external end_set : Evas.obj -> Evas.obj -> unit = "ml_elm_layout_end_set"

let end_get ly = Elm_object.part_content_get ly ~p:"elm.swallow.end" ()

module E = struct
  type u = Evas.Event_type.u
  let f = Evas.Event_type.create_unit
  let theme_changed = f "theme,changed"
end

