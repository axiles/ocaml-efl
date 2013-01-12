external add : Evas.obj -> Evas.obj = "ml_elm_box_add"

external horizontal_set : Evas.obj -> bool -> unit = "ml_elm_box_horizontal_set"

external horizontal_get : Evas.obj -> bool = "ml_elm_box_horizontal_get"

external homogeneous_set : Evas.obj -> bool -> unit =
  "ml_elm_box_homogeneous_set"

external homogeneous_get : Evas.obj -> bool = "ml_elm_box_homogeneous_get"

external pack_start : Evas.obj -> Evas.obj -> unit = "ml_elm_box_pack_start"

external pack_end : Evas.obj -> Evas.obj -> unit = "ml_elm_box_pack_end"

external pack_before : Evas.obj -> Evas.obj -> Evas.obj -> unit =
  "ml_elm_box_pack_before"

external pack_after : Evas.obj -> Evas.obj -> Evas.obj -> unit =
  "ml_elm_box_pack_after"

external clear : Evas.obj -> unit = "ml_elm_box_clear"

external unpack : Evas.obj -> Evas.obj -> unit = "ml_elm_box_unpack"

external unpack_all : Evas.obj -> unit = "ml_elm_box_unpack_all"

external children_get : Evas.obj -> Evas.obj list = "ml_elm_box_children_get"

external padding_set : Evas.obj -> int -> int -> unit = "ml_elm_box_padding_set"

external padding_get : Evas.obj -> int * int = "ml_elm_box_padding_get"

external align_set : Evas.obj -> float -> float -> unit = "ml_elm_box_align_set"

external align_get : Evas.obj -> float * float = "ml_elm_box_align_get"

external recalculate : Evas.obj -> unit = "ml_elm_box_recalculate"

