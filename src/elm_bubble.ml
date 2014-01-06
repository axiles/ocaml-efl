type pos = [`invalid | `top_left | `top_right | `bottom_left | `bottom_right]

external add : Evas.obj -> Evas.obj = "ml_elm_bubble_add"

external pos_set : Evas.obj -> pos -> unit = "ml_elm_bubble_pos_set"

external pos_get : Evas.obj -> pos = "ml_elm_bubble_pos_get"

module E = struct
  type u = Evas.Event_type.u
  let f = Evas.Event_type.create_unit
  let clicked = f "clicked"
  let focused = f "focused"
  let unfocused = f "unfocused"
end

