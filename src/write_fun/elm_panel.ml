open Common

let orient = simple_ty "Elm_Panel" "Orient"

let funs = [
  prop "orient" orient;
  prop "hidden" bool;
  simple_unit "toggle" [evas_object]
]

