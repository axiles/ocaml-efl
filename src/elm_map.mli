type zoom_mode = [`manual | `auto_fit | `auto_fill | `last]

val add : Evas.obj -> Evas.obj

val zoom_set : Evas.obj -> int -> unit

val zoom_get : Evas.obj -> int

val zoom_mode_set : Evas.obj -> zoom_mode -> unit

val zoom_mode_get : Evas.obj -> zoom_mode

val zoom_min_set : Evas.obj -> int -> unit

val zoom_min_get : Evas.obj -> int

val zoom_max_set : Evas.obj -> int -> unit

val zoom_max_get : Evas.obj -> int

val region_get : Evas.obj -> float * float

