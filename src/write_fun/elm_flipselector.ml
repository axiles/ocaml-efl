open Common

let funs = [
  simple_unit "flip_next" [evas_object];
  simple_unit "flip_prev" [evas_object];
  prop ~args:[elm_object_item] "item_selected" bool;
  prop "first_interval" double;
]

