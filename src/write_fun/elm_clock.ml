open Common

let funs = [
  simple_unit "time_set" [evas_object; int; int; int];
  prop "edit" bool;
  prop_flags "edit_mode" elm_clock_edit_mode;
  prop "show_am_pm" bool;
  prop "show_seconds" bool;
  prop "first_interval" double;
]

