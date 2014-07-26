open Common

let funs = [
  prop "option" elm_bg_option;
  simple_unit "color_set" [evas_object; int; int; int];
  simple_unit "load_size_set" [evas_object; int; int];
]

