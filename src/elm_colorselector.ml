include Henums.Elm_colorselector

external add : Evas.obj -> Evas.obj = "ml_elm_colorselector_add"

let addx = Elm_object.create_addx add

external color_set : Evas.obj -> int -> int -> int -> int -> unit =
  "ml_elm_colorselector_color_set"

external color_get : Evas.obj -> int * int * int * int =
  "ml_elm_colorselector_color_get"

external mode_set : Evas.obj -> mode -> unit = "ml_elm_colorselector_mode_set"

external mode_get : Evas.obj -> mode = "ml_elm_colorselector_mode_get"

external palette_item_color_get : Elm_object.item -> int * int * int * int =
  "ml_elm_colorselector_palette_item_color_get"

external palette_item_color_set :
  Elm_object.item -> int -> int -> int -> int -> unit =
    "ml_elm_colorselector_palette_item_color_set"

external palette_color_add :
  Evas.obj -> int -> int -> int -> int -> Elm_object.item =
    "ml_elm_colorselector_palette_color_add"

external palette_clear : Evas.obj -> unit = "ml_elm_colorselector_palette_clear"

external palette_name_set : Evas.obj -> string -> unit =
  "ml_elm_colorselector_palette_name_set"

external palette_name_get : Evas.obj -> string =
  "ml_elm_colorselector_palette_name_get"

