(** elm_hoversel_* *)

val add : Evas.obj -> Evas.obj

val horizontal_set : Evas.obj -> bool -> unit

val horizontal_get : Evas.obj -> bool

val hover_parent_set : Evas.obj -> Evas.obj -> unit

val hover_parent_get : Evas.obj -> Evas.obj

val hover_begin : Evas.obj -> unit

val hover_end : Evas.obj -> unit

val expanded_get : Evas.obj -> bool

val clear : Evas.obj -> unit

