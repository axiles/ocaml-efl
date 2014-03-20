external add : Evas.obj -> Evas.obj = "ml_elm_button_add"

let addx = Elm_object.create_addx add

external autorepeat_gap_timeout_get : Evas.obj -> float =
  "ml_elm_button_autorepeat_gap_timeout_get"

external autorepeat_gap_timeout_set : Evas.obj -> float -> unit =
  "ml_elm_button_autorepeat_gap_timeout_set"

external autorepeat_get : Evas.obj -> bool = "ml_elm_button_autorepeat_get"

external autorepeat_initial_timeout_get : Evas.obj -> float =
  "ml_elm_button_autorepeat_initial_timeout_get"

external autorepeat_initial_timeout_set : Evas.obj -> float -> unit =
  "ml_elm_button_autorepeat_initial_timeout_set"

external autorepeat_set : Evas.obj -> bool -> unit =
  "ml_elm_button_autorepeat_set"

