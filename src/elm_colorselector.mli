type mode = [`palette | `components | `both | `picker | `all]

val add : Evas.obj -> Evas.obj

val color_set :  Evas.obj -> int -> int -> int -> int -> unit

val color_get :  Evas.obj -> int * int * int * int

val mode_set : Evas.obj -> mode -> unit

val mode_get : Evas.obj -> mode

