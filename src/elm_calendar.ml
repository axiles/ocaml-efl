external add : Evas.obj -> Evas.obj = "ml_elm_calendar_add"

external weekdays_names_get : Evas.obj -> string array =
  "ml_elm_calendar_weekdays_names_get"

external weekdays_names_set : Evas.obj -> string array -> unit =
  "ml_elm_calendar_weekdays_names_set"

external min_max_year_set : Evas.obj -> int -> int -> unit =
  "ml_elm_calendar_min_max_year_set"

external min_max_year_get : Evas.obj -> int * int =
  "ml_elm_calendar_min_max_year_get"

