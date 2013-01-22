val add : Evas.obj -> Evas.obj

val file_set : Evas.obj -> string -> ?g:string -> unit -> bool

val file_get : Evas.obj -> string * string option

val smooth_set : Evas.obj -> bool -> unit

val smooth_get : Evas.obj -> bool

val object_size_get : Evas.obj -> int * int

val no_scale_set : Evas.obj -> bool -> unit

val no_scale_get : Evas.obj -> bool

val resizable_set : Evas.obj -> bool -> bool -> unit

val resizable_get : Evas.obj -> bool * bool

val fill_outside_set : Evas.obj -> bool -> unit

val fill_outside_get : Evas.obj -> bool

val preload_disabled_set : Evas.obj -> bool -> unit

val prescale_set : Evas.obj -> int -> unit

