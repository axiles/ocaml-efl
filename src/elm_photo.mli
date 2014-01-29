val add : Evas.obj -> Evas.obj

val file_set : Evas.obj -> string -> bool

val file_set_none : Evas.obj -> bool

val thumb_set : Evas.obj -> string -> ?g:string -> unit -> unit

val thumb_set_none : Evas.obj -> ?g:string -> unit -> unit

val size_set : Evas.obj -> int -> unit

val fill_inside_set : Evas.obj -> bool -> unit

val editable_set : Evas.obj -> bool -> unit

val aspect_fixed_set : Evas.obj -> bool -> unit

val aspect_fixed_get : Evas.obj -> bool

