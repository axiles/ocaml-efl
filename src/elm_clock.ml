external add : Evas.obj -> Evas.obj = "ml_elm_clock_add"

external time_set : Evas.obj -> int -> int -> int -> unit =
  "ml_elm_clock_time_set"

external time_get : Evas.obj -> int * int * int = "ml_elm_clock_time_get"

