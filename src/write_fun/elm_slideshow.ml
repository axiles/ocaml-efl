open Common

let funs = [
  simple_unit "item_show" [elm_object_item];
  simple_unit "next" [evas_object];
  simple_unit "previous" [evas_object];
  prop "transition" safe_string;
  prop "timeout" double;
  prop "loop" bool;
  simple_unit "clear" [evas_object];
  prop "layout" safe_string;
  prop "cache_before" int;
  prop "cache_after" int;
  simple "count_get" [evas_object] int;
]

