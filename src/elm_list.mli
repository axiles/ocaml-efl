type mode = [`compress | `scroll | `limit | `expand | `last]

val add : Evas.obj -> Evas.obj

val go : Evas.obj -> unit

val multi_select_set : Evas.obj -> bool -> unit 

val multi_select_get : Evas.obj -> bool

val mode_set : Evas.obj -> mode -> unit

