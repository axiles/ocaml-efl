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

