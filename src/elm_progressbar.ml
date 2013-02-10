type format =
  | Hidden
  | Unit of (unit, unit, unit) Pervasives.format
  | Float of (float -> unit, unit, unit) Pervasives.format

external add : Evas.obj -> Evas.obj = "ml_elm_progressbar_add"

external pulse_set : Evas.obj -> bool -> unit = "ml_elm_progressbar_pulse_set"

external pulse_get : Evas.obj -> bool = "ml_elm_progressbar_pulse_get"

external pulse : Evas.obj -> bool -> unit = "ml_elm_progressbar_pulse"

external value_set : Evas.obj -> float -> unit = "ml_elm_progressbar_value_set"

external value_get : Evas.obj -> float = "ml_elm_progressbar_value_get"

external span_size_set : Evas.obj -> int -> unit =
  "ml_elm_progressbar_span_size_set"

external span_size_get : Evas.obj -> int = "ml_elm_progressbar_span_size_get"

external unit_format_set_ : Evas.obj -> string option -> unit =
  "ml_elm_progressbar_unit_format_set"

let unit_format_set obj fmt =
  let fmt1 = match fmt with
  | Hidden -> None
  | Unit f -> Some (string_of_format f)
  | Float f -> Some (string_of_format f) in
  unit_format_set_ obj fmt1

