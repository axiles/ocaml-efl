open Common

let funs = [
  simple_unit "color_set" [evas_object; int; int; int; int];
  prop "mode" elm_colorselector_mode;
  simple_unit "palette_item_color_set" [elm_object_item; int; int; int; int];
  prop ~args:[elm_object_item] "palette_item_selected" bool;
  simple_unit "palette_clear" [evas_object];
  prop "palette_name" safe_string;
]

