type ty = [`none | `file | `standard]

val add : Evas.obj -> Evas.obj

val thumb_set : Evas.obj -> string -> string -> ?g:string -> unit -> unit

val standard_set_with_bool : Evas.obj -> string -> bool

val standard_set : Evas.obj -> string -> unit

