(** Layout *)

val add : Evas.obj -> Evas.obj

val addx : Elm_object.t_addx

val file_set : Evas.obj -> string -> string -> bool

val theme_set : Evas.obj -> string -> string -> string -> bool

val signal_emit : Evas.obj -> string -> string -> unit

val signal_callback_add : Evas.obj -> string -> string -> Edje.signal_cb -> unit

val box_append : Evas.obj -> string -> Evas.obj -> bool

val box_prepend : Evas.obj -> string -> Evas.obj -> bool

val box_insert_before : Evas.obj -> string -> Evas.obj -> Evas.obj -> bool

val box_insert_at : Evas.obj -> string -> Evas.obj -> int -> bool

val box_remove : Evas.obj -> string -> Evas.obj -> Evas.obj option

val box_remove_all : Evas.obj -> string -> bool -> bool

val table_pack :
  Evas.obj -> string -> Evas.obj -> int -> int -> int -> int -> bool

val table_unpack : Evas.obj -> string -> Evas.obj -> Evas.obj option

val table_clear : Evas.obj -> string -> bool -> bool

val edje_get : Evas.obj -> Evas.obj

val data_get : Evas.obj -> string -> string option

val sizing_eval : Evas.obj -> unit

val part_cursor_set : Evas.obj -> string -> string -> bool

val part_cursor_get : Evas.obj -> string -> string

val part_cursor_unset : Evas.obj -> string -> bool

val part_cursor_style_set : Evas.obj -> string -> string -> bool

val part_cursor_style_get : Evas.obj -> string -> string option

val part_cursor_engine_only_set : Evas.obj -> string -> bool -> bool

val part_cursor_engine_only_get : Evas.obj -> string -> bool

val icon_set : Evas.obj -> Evas.obj -> unit

val icon_get : Evas.obj -> Evas.obj

val end_set : Evas.obj -> Evas.obj -> unit

val end_get : Evas.obj -> Evas.obj

