type select_mode = [`default | `always | `none | `ondemand]

type mark_repeat_type = [
  `unique | `daily | `weekly | `monthly | `annually | `last_day_of_month]

type mark

val add : Evas.obj -> Evas.obj

val weekdays_names_get : Evas.obj -> string array

val weekdays_names_set : Evas.obj -> string array -> unit

val min_max_year_set : Evas.obj -> int -> int -> unit

val min_max_year_get : Evas.obj -> int * int

val select_mode_set : Evas.obj -> select_mode -> unit

val select_mode_get : Evas.obj -> select_mode

val selected_time_set : Evas.obj -> Unix.tm -> unit

val selected_time_get : Evas.obj -> Unix.tm option

val mark_add : Evas.obj -> string -> Unix.tm -> mark_repeat_type -> mark

val mark_del : mark -> unit

val marks_clear : Evas.obj -> unit

