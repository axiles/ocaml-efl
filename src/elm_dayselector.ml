type day = Henums.Elm_dayselector.day

external add : Evas.obj -> Evas.obj = "ml_elm_dayselector_add"

let addx = Elm_object.create_addx add

external day_selected_set : Evas.obj -> day -> bool -> unit =
  "ml_elm_dayselector_day_selected_set"

external day_selected_get : Evas.obj -> day -> bool =
  "ml_elm_dayselector_day_selected_get"

external week_start_set : Evas.obj -> day -> unit =
  "ml_elm_dayselector_week_start_set"

external week_start_get : Evas.obj -> day = "ml_elm_dayselector_week_start_get"

external weekend_start_set : Evas.obj -> day -> unit =
  "ml_elm_dayselector_weekend_start_set"

external weekend_start_get : Evas.obj -> day =
  "ml_elm_dayselector_weekend_start_get"

external weekend_length_set : Evas.obj -> int -> unit =
  "ml_elm_dayselector_weekend_length_set"

external weekend_length_get : Evas.obj -> int =
  "ml_elm_dayselector_weekend_length_get"

external weekdays_names_set : Evas.obj -> string array -> unit =
  "ml_elm_dayselector_weekdays_names_set"

external weekdays_names_get : Evas.obj -> string list =
  "ml_elm_dayselector_weekdays_names_get"

external day_of_ptr : Evas.ptr -> day = "ml_Elm_Dayselector_Day_of_ptr"

