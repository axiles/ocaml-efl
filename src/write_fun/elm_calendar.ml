open Common

let select_mode = simple_ty "Elm_Calendar" "Select_Mode"
let mark = simple_ty ~ptr:true "Elm_Calendar" "Mark"
let mark_repeat_type = simple_ty "Elm_Calendar" "Mark_Repeat_Type"
let weekday = simple_ty "Elm_Calendar" "Weekday"
let selectable = flags_ty "Elm_Calendar" "Selectable"

let funs = [
  simple_unit "min_max_year_set" [evas_object; int; int];
  prop "select_mode" select_mode;
  prop_flags "selectable" selectable;
  simple_unit "mark_del" [mark];
  simple_unit "marks_clear" [evas_object];
  simple_unit "marks_draw" [evas_object];
  prop "interval" double;
  prop "first_day_of_week" weekday;
]

