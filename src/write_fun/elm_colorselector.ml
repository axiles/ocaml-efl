open Common

let mode = simple_ty "Elm_Colorselector" "Mode"

let funs = [
  simple_unit "color_set" [evas_object; int; int; int; int];
  prop "mode" mode;
  simple_unit "palette_item_color_set" [elm_object_item; int; int; int; int];
  simple_unit "palette_clear" [evas_object];
  prop "palette_name" safe_string;
]

