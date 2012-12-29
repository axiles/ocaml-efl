val add : Evas.obj -> Evas.obj

val file_set_with_bool : Evas.obj -> string -> string -> bool

val file_set : Evas.obj -> string -> string -> unit

val theme_set_with_bool : Evas.obj -> string -> string -> string -> bool

val theme_set : Evas.obj -> string -> string -> string -> unit

val signal_emit : Evas.obj -> string -> string -> unit

val box_append_with_bool : Evas.obj -> string -> Evas.obj -> bool

val box_append : Evas.obj -> string -> Evas.obj -> unit

val box_insert_at_with_bool : Evas.obj -> string -> Evas.obj -> int -> bool

val box_insert_at : Evas.obj -> string -> Evas.obj -> int -> unit

val box_insert_before_with_bool :
  Evas.obj -> string -> Evas.obj -> Evas.obj -> bool

val box_insert_before : Evas.obj -> string -> Evas.obj -> Evas.obj -> unit

val box_prepend_with_bool : Evas.obj -> string -> Evas.obj -> bool

val box_prepend : Evas.obj -> string -> Evas.obj -> unit

