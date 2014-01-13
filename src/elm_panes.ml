external add : Evas.obj -> Evas.obj = "ml_elm_panes_add"

external fixed_set : Evas.obj -> bool -> unit = "ml_elm_panes_fixed_set"

external fixed_get : Evas.obj -> bool = "ml_elm_panes_fixed_get"

external content_left_size_get : Evas.obj -> float =
  "ml_elm_panes_content_left_size_get"

external content_left_size_set : Evas.obj -> float -> unit =
  "ml_elm_panes_content_left_size_set"

external content_right_size_get : Evas.obj -> float =
  "ml_elm_panes_content_right_size_get"

external content_right_size_set : Evas.obj -> float -> unit =
  "ml_elm_panes_content_right_size_set"

