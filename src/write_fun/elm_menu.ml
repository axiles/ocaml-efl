open Common

let funs = [
  prop "parent" evas_object;
  simple_unit "move" [evas_object; int; int];
  simple_unit "close" [evas_object];
  simple "item_object_get" [elm_object_item] evas_object;
  simple_unit "item_icon_name_set" [elm_object_item; safe_string];
  prop ~args:[elm_object_item] "item_selected" bool;
  simple "item_is_separator" [elm_object_item] bool;
  simple_unit "item_subitems_clear" [elm_object_item];
  simple "item_index_get" [elm_object_item] int;
]

