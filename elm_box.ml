external add : Evas.obj -> Evas.obj = "ml_elm_box_add"

external horizontal_set : Evas.obj -> bool -> unit = "ml_elm_box_horizontal_set"

external horizontal_get : Evas.obj -> bool = "ml_elm_box_horizontal_get"

external homogeneous_set : Evas.obj -> bool -> unit =
  "ml_elm_box_homogeneous_set"

external homogeneous_get : Evas.obj -> bool = "ml_elm_box_homogeneous_get"

external pack_start : Evas.obj -> Evas.obj -> unit = "ml_elm_box_pack_start"

external pack_end : Evas.obj -> Evas.obj -> unit = "ml_elm_box_pack_end"

