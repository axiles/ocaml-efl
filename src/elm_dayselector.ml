type day = [`sun | `mon | `tue | `wed | `thu | `fri | `sat | `max]

external add : Evas.obj -> Evas.obj = "ml_elm_dayselector_add"

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

