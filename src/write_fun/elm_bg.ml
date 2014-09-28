open Common

let option = simple_ty "Elm_Bg" "Option"

let funs = [
  prop "option" option;
  simple_unit "color_set" [evas_object; int; int; int];
  simple_unit "load_size_set" [evas_object; int; int];
]

