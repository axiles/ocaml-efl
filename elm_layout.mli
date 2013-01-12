val add : Evas.obj -> Evas.obj

val file_set_with_bool : Evas.obj -> string -> string -> bool

val file_set : Evas.obj -> string -> string -> unit

val theme_set_with_bool : Evas.obj -> string -> string -> string -> bool

val theme_set : Evas.obj -> string -> string -> string -> unit

val signal_emit : Evas.obj -> string -> string -> unit

val signal_callback_add : Evas.obj -> string -> string -> Edje.signal_cb -> unit

val signal_callback_del : Evas.obj -> string -> string -> Edje.signal_cb -> unit

val box_append_with_bool : Evas.obj -> string -> Evas.obj -> bool

val box_append : Evas.obj -> string -> Evas.obj -> unit

val box_prepend_with_bool : Evas.obj -> string -> Evas.obj -> bool

val box_prepend : Evas.obj -> string -> Evas.obj -> unit

val box_insert_before_with_bool :
  Evas.obj -> string -> Evas.obj -> Evas.obj -> bool

val box_insert_before : Evas.obj -> string -> Evas.obj -> Evas.obj -> unit

val box_insert_at_with_bool : Evas.obj -> string -> Evas.obj -> int -> bool

val box_insert_at : Evas.obj -> string -> Evas.obj -> int -> unit

val box_remove : Evas.obj -> string -> Evas.obj -> Evas.obj option

val box_remove_all_with_bool : Evas.obj -> string -> bool -> bool

val box_remove_all : Evas.obj -> string -> bool -> unit

val table_pack_with_bool :
  Evas.obj -> string -> Evas.obj -> int -> int -> int -> int -> bool

val table_pack :
  Evas.obj -> string -> Evas.obj -> int -> int -> int -> int -> unit

val table_unpack : Evas.obj -> string -> Evas.obj -> Evas.obj option

val table_clear_with_bool : Evas.obj -> string -> bool -> bool

val table_clear : Evas.obj -> string -> bool -> unit

val edje_get : Evas.obj -> Evas.obj

val data_get : Evas.obj -> string -> string option

val sizing_eval : Evas.obj -> unit

val part_cursor_set_with_bool : Evas.obj -> string -> string -> bool

val part_cursor_set : Evas.obj -> string -> string -> unit

val part_cursor_get : Evas.obj -> string -> string

val part_cursor_unset_with_bool : Evas.obj -> string -> bool

val part_cursor_unset : Evas.obj -> string -> unit

val part_cursor_style_set_with_bool : Evas.obj -> string -> string -> bool

val part_cursor_style_set : Evas.obj -> string -> string -> unit

