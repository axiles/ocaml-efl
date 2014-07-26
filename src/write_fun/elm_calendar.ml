open Common

let funs = [
  simple_unit "min_max_year_set" [evas_object; int; int];
  prop "select_mode" elm_calendar_select_mode;
  prop_flags "selectable" elm_calendar_selectable;
  simple_unit "mark_del" [elm_calendar_mark];
  simple_unit "marks_clear" [evas_object];
  simple_unit "marks_draw" [evas_object];
  prop "interval" double;
  prop "first_day_of_week" elm_calendar_weekday;
]

