external add : Evas.obj -> Evas.obj = "ml_elm_actionslider_add"

external selected_label_get : Evas.obj -> string =
  "ml_elm_actionslider_selected_label_get"

external indicator_pos_set : Evas.obj -> bool -> bool -> bool -> unit =
  "ml_elm_actionslider_indicator_pos_set"

external indicator_pos_get : Evas.obj -> bool * bool * bool =
  "ml_elm_actionslider_indicator_pos_get"

