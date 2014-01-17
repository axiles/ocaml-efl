type axis = [`none | `horizontal | `vertical | `both]

external add : Evas.obj -> Evas.obj = "ml_elm_hover_add"

external target_set : Evas.obj -> Evas.obj -> unit = "ml_elm_hover_target_set"

external target_get : Evas.obj -> Evas.obj = "ml_elm_hover_target_get"

external parent_set : Evas.obj -> Evas.obj -> unit = "ml_elm_hover_parent_set"

external parent_get : Evas.obj -> Evas.obj = "ml_elm_hover_parent_get"

external best_content_location_get : Evas.obj -> axis -> string option =
  "ml_elm_hover_best_content_location_get"

external dismiss : Evas.obj -> unit = "ml_elm_hover_dismiss"

module E = struct
  type u = Evas.Event_type.u
  let f = Evas.Event_type.create_unit
  let clicked = f "clicked"
  let dismissed = f "dismissed"
  let smart_changed = f "smart,changed"
  let focused = f "focused"
  let unfocused = f "unfocused"
end

