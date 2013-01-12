external add : Evas.obj -> Evas.obj = "ml_elm_radio_add"

external group_add : Evas.obj -> Evas.obj -> unit =
  "ml_elm_radio_group_add"

external state_value_set : Evas.obj -> int -> unit =
  "ml_elm_radio_state_value_set"

external state_value_get : Evas.obj -> int = "ml_elm_radio_state_value_get"

external value_set : Evas.obj -> int -> unit = "ml_elm_radio_value_set"

external value_get : Evas.obj -> int = "ml_elm_radio_value_get"

