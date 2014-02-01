type select_mode = [`default | `always | `none | `ondemand]

type mark_repeat_type = [
  `unique | `daily | `weekly | `monthly | `annually | `last_day_of_month]

type mark

external add : Evas.obj -> Evas.obj = "ml_elm_calendar_add"

external weekdays_names_get : Evas.obj -> string array =
  "ml_elm_calendar_weekdays_names_get"

external weekdays_names_set : Evas.obj -> string array -> unit =
  "ml_elm_calendar_weekdays_names_set"

external min_max_year_set : Evas.obj -> int -> int -> unit =
  "ml_elm_calendar_min_max_year_set"

external min_max_year_get : Evas.obj -> int * int =
  "ml_elm_calendar_min_max_year_get"

external select_mode_set : Evas.obj -> select_mode -> unit =
  "ml_elm_calendar_select_mode_set"

external select_mode_get : Evas.obj -> select_mode =
  "ml_elm_calendar_select_mode_get"

external selected_time_set : Evas.obj -> Unix.tm -> unit =
  "ml_elm_calendar_selected_time_set"

external selected_time_get : Evas.obj -> Unix.tm option =
  "ml_elm_calendar_selected_time_get"

external mark_add : Evas.obj -> string -> Unix.tm -> mark_repeat_type -> mark =
  "ml_elm_calendar_mark_add"

external mark_del : mark -> unit = "ml_elm_calendar_mark_del"

external marks_clear : Evas.obj -> unit = "ml_elm_calendar_marks_clear"

external marks_get : Evas.obj -> mark list = "ml_elm_calendar_marks_get"

external marks_draw : Evas.obj -> unit = "ml_elm_calendar_marks_draw"

external interval_set : Evas.obj -> float -> unit =
  "ml_elm_calendar_interval_set"

external interval_get : Evas.obj -> float = "ml_elm_calendar_interval_get"

