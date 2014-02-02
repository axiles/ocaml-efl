external add : Evas.obj -> Evas.obj = "ml_elm_colorselector_add"

external color_set : Evas.obj -> int -> int -> int -> int -> unit =
  "ml_elm_colorselector_color_set"

external color_get : Evas.obj -> int * int * int * int =
  "ml_elm_colorselector_color_get"

