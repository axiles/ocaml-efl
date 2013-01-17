type ty = [`basic]

val add : ?p:Evas.obj -> string -> ty -> Evas.obj

val util_standard_add : string -> string -> Evas.obj

val resize_object_add : Evas.obj -> Evas.obj -> unit

val resize_object_del : Evas.obj -> Evas.obj -> unit

val title_set : Evas.obj -> string -> unit

val title_get : Evas.obj -> string

val icon_name_set : Evas.obj -> string -> unit

val icon_name_get : Evas.obj -> string

val autodel_set : Evas.obj -> bool -> unit

