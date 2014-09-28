open Common

let mode = simple_ty "Elm_List" "Mode"

let funs = [
  simple_unit "go" [evas_object];
  prop "multi_select" bool;
  prop "mode" mode;
  prop "horizontal" bool;
  prop "select_mode" elm_object_select_mode;
  simple_unit "clear" [evas_object];
  prop ~args:[elm_object_item] "item_selected" bool;
  prop ~args:[elm_object_item]"item_separator" bool;
  simple_unit "item_show" [elm_object_item];
  simple_unit "item_bring_in" [elm_object_item];
  simple "item_object_get" [elm_object_item] evas_object;
]

