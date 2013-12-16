external add : Evas.obj -> Evas.obj = "ml_elm_button_add"

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

module E = struct
  type u = Evas.Event_type.u
  let f = Evas.Event_type.create_unit
  let clicked = f "clicked"
  let repeated = f "repeated"
  let pressed = f "pressed"
  let unpressed = f "unpressed"
  let focused = f "focused"
  let unfocused = f "unfocused"
end

