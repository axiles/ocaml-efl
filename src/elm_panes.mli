(** Panes *)

val add : Evas.obj -> Evas.obj

val fixed_set : Evas.obj -> bool -> unit

val fixed_get : Evas.obj -> bool

val content_left_size_get : Evas.obj -> float

val content_left_size_set : Evas.obj -> float -> unit

val content_right_size_get : Evas.obj -> float

val content_right_size_set : Evas.obj -> float -> unit

val horizontal_set : Evas.obj -> bool -> unit

val horizontal_get : Evas.obj -> bool

