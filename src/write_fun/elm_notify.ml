open Common

let funs = [
  prop "parent" evas_object;
  simple_unit "align_set" [evas_object; double; double];
  prop "timeout" double;
  prop "allow_events" bool;
]

