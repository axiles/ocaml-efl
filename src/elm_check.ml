external add : Evas.obj -> Evas.obj = "ml_elm_check_add"

external state_set : Evas.obj -> bool -> unit = "ml_elm_check_state_set"

external state_get : Evas.obj -> bool = "ml_elm_check_state_get"

module E = struct
  type u = Evas.Event_type.u
  let f = Evas.Event_type.create_unit
  let changed = f "changed"
  let focused = f "focused"
  let unfocused = f "unfocused"
end

