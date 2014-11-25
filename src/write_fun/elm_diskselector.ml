open Common

let funs = [
  prop "round_enabled" bool;
  prop "side_text_max_length" int;
  prop "display_item_num" int;
  simple_unit "clear" [evas_object];
  prop ~args:[elm_object_item] "item_selected" bool;
]

