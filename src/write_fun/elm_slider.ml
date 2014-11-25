open Common

let funs = [
  prop "span_size" int;
  prop "horizontal" bool;
  simple_unit "min_max_set" [evas_object; double; double];
  prop "value" double;
  prop "inverted" bool;
  prop "indicator_show" bool;
  prop "step" double;
]

