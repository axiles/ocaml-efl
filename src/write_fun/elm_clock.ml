open Common

let edit_mode = flags_ty "Elm_Clock" "Edit_Mode"

let funs = [
  simple_unit "time_set" [evas_object; int; int; int];
  prop "edit" bool;
  prop_flags "edit_mode" edit_mode;
  prop "show_am_pm" bool;
  prop "show_seconds" bool;
  prop "first_interval" double;
]

