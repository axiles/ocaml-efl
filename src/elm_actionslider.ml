external add : Evas.obj -> Evas.obj = "ml_elm_actionslider_add"

external selected_label_get : Evas.obj -> string option =
  "ml_elm_actionslider_selected_label_get"

external indicator_pos_set : Evas.obj -> bool -> bool -> bool -> unit =
  "ml_elm_actionslider_indicator_pos_set"

external indicator_pos_get : Evas.obj -> bool * bool * bool =
  "ml_elm_actionslider_indicator_pos_get"

external magnet_pos_set : Evas.obj -> bool -> bool -> bool -> unit =
  "ml_elm_actionslider_magnet_pos_set"

external magnet_pos_get : Evas.obj -> bool * bool * bool =
  "ml_elm_actionslider_magnet_pos_get"

external enabled_pos_set : Evas.obj -> bool -> bool -> bool -> unit =
  "ml_elm_actionslider_enabled_pos_set"

external enabled_pos_get : Evas.obj -> bool * bool * bool =
  "ml_elm_actionslider_enabled_pos_get"

module E = struct
  type u = Evas.Event_type.u
  type 'a v = 'a Evas.Event_type.v
  let f = Evas.Event_type.create_unit
  let g x = Evas.Event_type.create x Evas.string_opt_of_ptr
  let selected = g "selected"
  let pos_changed = g "pos_changed"
end

