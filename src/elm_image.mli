val add : Evas.obj -> Evas.obj

val file_set : Evas.obj -> string -> ?g:string -> unit -> bool

val file_get : Evas.obj -> string * string option

val no_scale_set : Evas.obj -> bool -> unit

val resizable_set : Evas.obj -> bool -> bool -> unit

