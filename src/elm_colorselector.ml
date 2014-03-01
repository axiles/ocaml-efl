type mode = [`palette | `components | `both | `picker | `all]

external add : Evas.obj -> Evas.obj = "ml_elm_colorselector_add"

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

external palette_item_selected_get : Elm_object.item -> bool =
  "ml_elm_colorselector_palette_item_selected_get"

external palette_item_selected_set : Elm_object.item -> bool -> unit =
  "ml_elm_colorselector_palette_item_selected_set"

external palette_color_add :
  Evas.obj -> int -> int -> int -> int -> Elm_object.item =
    "ml_elm_colorselector_palette_color_add"

external palette_clear : Evas.obj -> unit = "ml_elm_colorselector_palette_clear"

external palette_items_get : Evas.obj -> Elm_object.item list =
  "ml_elm_colorselector_palette_items_get"

external palette_selected_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_colorselector_palette_selected_item_get"

external palette_name_set : Evas.obj -> string -> unit =
  "ml_elm_colorselector_palette_name_set"

external palette_name_get : Evas.obj -> string =
  "ml_elm_colorselector_palette_name_get"

