(** Box *)

type transition

val add : Evas.obj -> Evas.obj

val horizontal_set : Evas.obj -> bool -> unit

val horizontal_get : Evas.obj -> bool

val homogeneous_set : Evas.obj -> bool -> unit

val homogeneous_get : Evas.obj -> bool

val pack_start : Evas.obj -> Evas.obj -> unit

val pack_end : Evas.obj -> Evas.obj -> unit

val pack_before : Evas.obj -> Evas.obj -> Evas.obj -> unit

val pack_after : Evas.obj -> Evas.obj -> Evas.obj -> unit

val clear : Evas.obj -> unit

val unpack : Evas.obj -> Evas.obj -> unit

val unpack_all : Evas.obj -> unit

val children_get : Evas.obj -> Evas.obj list

val padding_set : Evas.obj -> int -> int -> unit

val padding_get : Evas.obj -> int * int

val align_set : Evas.obj -> float -> float -> unit

val align_get : Evas.obj -> float * float

val recalculate : Evas.obj -> unit

val layout_set : Evas.obj -> Evas_object.box_layout -> Ecore.cb -> unit

val layout_transition : transition -> Evas_object.box_layout

val transition_new :
  float -> Evas_object.box_layout -> Ecore.cb -> Evas_object.box_layout ->
    Ecore.cb -> Ecore.cb -> transition

val transition_free : transition -> Ecore.cb

