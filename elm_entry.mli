val add : Evas.obj -> Evas.obj

val text_style_user_push : Evas.obj -> string -> unit 

val text_style_user_pop : Evas.obj -> unit

val text_style_user_peek : Evas.obj -> string option

val single_line_set : Evas.obj -> bool -> unit

val single_line_get : Evas.obj -> bool

val password_set : Evas.obj -> bool -> unit

val password_get : Evas.obj -> bool

val entry_set : Evas.obj -> string -> unit

val entry_get : Evas.obj -> string

val entry_append : Evas.obj -> string -> unit

val is_empty : Evas.obj -> bool

val selection_get : Evas.obj -> string option

val textblock_get : Evas.obj ->  Evas.obj

val calc_force : Evas.obj -> unit

val entry_insert : Evas.obj -> string -> unit

val line_wrap_set : Evas.obj -> Elm.wrap_type -> unit

val line_wrap_get : Evas.obj -> Elm.wrap_type

