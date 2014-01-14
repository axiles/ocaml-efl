(** elm_table_* *)

val add : Evas.obj -> Evas.obj

val homogeneous_set : Evas.obj -> bool -> unit

val homogeneous_get : Evas.obj -> bool

val padding_set : Evas.obj -> int -> int -> unit

val padding_get : Evas.obj -> int * int

val pack : Evas.obj -> Evas.obj -> int -> int -> int -> int -> unit

val unpack : Evas.obj -> Evas.obj -> unit

val clear : Evas.obj -> bool -> unit

val pack_set : Evas.obj -> int -> int -> int -> int -> unit

val pack_get : Evas.obj -> int * int * int * int

