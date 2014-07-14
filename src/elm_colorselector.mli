(** Colorselector *)

type mode = [
| `palette
| `components
| `both
| `picker
| `all
]


val add : Evas.obj -> Evas.obj

val addx : Elm_object.t_addx

val color_set :  Evas.obj -> int -> int -> int -> int -> unit

val color_get :  Evas.obj -> int * int * int * int

val mode_set : Evas.obj -> mode -> unit

val mode_get : Evas.obj -> mode

val palette_item_color_get : Elm_object.item -> int * int * int * int

val palette_item_color_set : Elm_object.item -> int -> int -> int -> int -> unit

val palette_color_add : Evas.obj -> int -> int -> int -> int -> Elm_object.item

val palette_clear : Evas.obj -> unit

val palette_name_set : Evas.obj -> string -> unit

val palette_name_get : Evas.obj -> string

