type zoom_mode = [`manual | `auto_fit | `auto_fill | `auto_fit_in | `last]

val add : Evas.obj -> Evas.obj

val file_set : Evas.obj -> string -> Evas.load_error

val file_get : Evas.obj -> string

val zoom_set : Evas.obj -> float -> unit

val zoom_get : Evas.obj -> float

val zoom_mode_set : Evas.obj -> zoom_mode -> unit

val zoom_mode_get : Evas.obj -> zoom_mode

val image_size_get : Evas.obj -> int * int

val image_region_get : Evas.obj -> int * int * int * int

val image_region_show : Evas.obj -> int -> int -> int -> int -> unit

val image_region_bring_in : Evas.obj -> int -> int -> int -> int -> unit

val paused_set : Evas.obj -> bool -> unit

val paused_get : Evas.obj -> bool

val internal_image_get : Evas.obj -> Evas.obj option

val gesture_enabled_set : Evas.obj -> bool -> unit

val gesture_enabled_get : Evas.obj -> bool

