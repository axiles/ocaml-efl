type mode = [`palette | `components | `both | `picker | `all]

external add : Evas.obj -> Evas.obj = "ml_elm_colorselector_add"

external color_set : Evas.obj -> int -> int -> int -> int -> unit =
  "ml_elm_colorselector_color_set"

external color_get : Evas.obj -> int * int * int * int =
  "ml_elm_colorselector_color_get"

external mode_set : Evas.obj -> mode -> unit = "ml_elm_colorselector_mode_set"

external mode_get : Evas.obj -> mode = "ml_elm_colorselector_mode_get"

