(** elm_grid_* *)

val add : Evas.obj -> Evas.obj

val size_set : Evas.obj -> int -> int -> unit

val size_get : Evas.obj -> int * int

val pack : Evas.obj -> Evas.obj -> int -> int -> int -> int -> unit

val unpack : Evas.obj -> Evas.obj -> unit

val clear : Evas.obj -> bool -> unit

val pack_set : Evas.obj -> int -> int -> int -> int -> unit

val pack_get : Evas.obj -> int * int * int * int

val children_get : Evas.obj -> Evas.obj list

