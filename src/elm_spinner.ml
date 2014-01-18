external add : Evas.obj -> Evas.obj = "ml_elm_spinner_add"

external min_max_set : Evas.obj -> float -> float -> unit =
  "ml_elm_spinner_min_max_set"

external label_format_set : Evas.obj -> string -> unit =
  "ml_elm_spinner_label_format_set"

external editable_set : Evas.obj -> bool -> unit = "ml_elm_spinner_editable_set"

external special_value_add : Evas.obj -> float -> string -> unit =
  "ml_elm_spinner_special_value_add"

external value_get : Evas.obj -> float = "ml_elm_spinner_value_get"

