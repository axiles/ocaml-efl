type zoom_mode = [`manual | `auto_fit | `auto_fill | `auto_fit_in | `last]

val add : Evas.obj -> Evas.obj

val file_set : Evas.obj -> string -> Evas.load_error

val file_get : Evas.obj -> string

val zoom_set : Evas.obj -> float -> unit

val zoom_get : Evas.obj -> float

val zoom_mode_set : Evas.obj -> zoom_mode -> unit

val zoom_mode_get : Evas.obj -> zoom_mode

val image_size_get : Evas.obj -> int * int

