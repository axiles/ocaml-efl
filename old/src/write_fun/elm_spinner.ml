open Common

let funs = [
  simple_unit "min_max_set" [evas_object; double; double];
  prop "step" double;
  prop "value" double;
  prop "wrap" bool;
  prop "editable" bool;
  simple_unit "special_value_add" [evas_object; double; safe_string];
  prop "interval" double;
  prop "base" double;
  prop "round" int;
]

