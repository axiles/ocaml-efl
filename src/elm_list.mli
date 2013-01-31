type mode = [`compress | `scroll | `limit | `expand | `last]

val add : Evas.obj -> Evas.obj

val go : Evas.obj -> unit

val multi_select_set : Evas.obj -> bool -> unit 

val multi_select_get : Evas.obj -> bool

val mode_set : Evas.obj -> mode -> unit

val mode_get : Evas.obj -> mode

val horizontal_set : Evas.obj -> bool -> unit

val horizontal_get : Evas.obj -> bool

val select_mode_set : Evas.obj -> Elm_object.select_mode -> unit

val select_mode_get : Evas.obj -> Elm_object.select_mode

