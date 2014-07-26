open Common

let funs = [
  prop "autohide_disabled" bool;
  prop "item_level" int;
  simple_unit "item_selected_set" [elm_object_item; bool];
  simple_unit "item_clear" [evas_object];
  simple_unit "level_go" [evas_object; int];
  simple "item_letter_get" [elm_object_item] safe_string;
  prop "indicator_disabled" bool;
  prop "horizontal" bool;
  prop "delay_change_time" double;
  prop "omit_enabled" bool;
]

