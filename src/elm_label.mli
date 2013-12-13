(** elm_label_* *)

val add : Evas.obj -> Evas.obj

val line_wrap_set : Evas.obj -> Elm.wrap_type -> unit

val line_wrap_get : Evas.obj -> Elm.wrap_type

val wrap_width_set : Evas.obj -> int -> unit

val wrap_width_get : Evas.obj -> int

val ellipsis_set : Evas.obj -> bool -> unit

val ellipsis_get : Evas.obj -> bool

val slide_mode_set : Evas.obj -> bool -> unit

val slide_mode_get : Evas.obj -> bool

val slide_duration_set : Evas.obj -> float -> unit

val slide_duration_get : Evas.obj -> float
