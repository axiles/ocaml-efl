external add : Evas.obj -> Evas.obj = "ml_elm_conformant_add"

module E = struct
  type u = Evas.Event_type.u
  let f = Evas.Event_type.create_unit
  let virtualkeypad_state_on = f "virtualkeypad,state,on"
  let virtualkeypad_state_off = f "virtualkeypad,state,off"
  let clipboard_state_on = f "clipboard,state,on"
  let clipboard_state_off = f "clipboard,state,off"
end

