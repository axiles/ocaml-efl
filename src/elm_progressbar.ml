external add : Evas.obj -> Evas.obj = "ml_elm_progressbar_add"

external pulse_set : Evas.obj -> bool -> unit = "ml_elm_progressbar_pulse_set"

external pulse_get : Evas.obj -> bool = "ml_elm_progressbar_pulse_get"

external pulse : Evas.obj -> bool -> unit = "ml_elm_progressbar_pulse"

external value_set : Evas.obj -> float -> unit = "ml_elm_progressbar_value_set"

external value_get : Evas.obj -> float = "ml_elm_progressbar_value_get"

external span_size_set : Evas.obj -> int -> unit =
  "ml_elm_progressbar_span_size_set"

external span_size_get : Evas.obj -> int = "ml_elm_progressbar_span_size_get"

