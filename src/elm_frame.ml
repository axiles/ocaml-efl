external add : Evas.obj -> Evas.obj = "ml_elm_frame_add"

external autocollapse_set : Evas.obj -> bool -> unit =
  "ml_elm_frame_autocollapse_set"

external autocollapse_get : Evas.obj -> bool = "ml_elm_frame_autocollapse_get"

external collapse_set : Evas.obj -> bool -> unit = "ml_elm_frame_collapse_set"

external collapse_get : Evas.obj -> bool = "ml_elm_frame_collapse_get"

external collapse_go : Evas.obj -> bool -> unit = "ml_elm_frame_collapse_go"

module E =  struct
  type u = Evas.Event_type.u
  let f = Evas.Event_type.create_unit
  let clicked = f "clicked"
end

