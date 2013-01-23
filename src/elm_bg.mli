type opt = [`center | `scale | `stretch | `tile | `last]

val add : Evas.obj -> Evas.obj

val file_set : Evas.obj -> string -> ?g:string -> unit -> unit

val file_get : Evas.obj -> string * string option

val color_set : Evas.obj -> int -> int -> int -> unit

