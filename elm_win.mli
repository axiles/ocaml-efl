type ty = [`basic]

val add : ?p:Evas.obj -> string -> ty -> Evas.obj

val util_standard_add : string -> string -> Evas.obj

val resize_object_add : Evas.obj -> Evas.obj -> unit

val resize_object_del : Evas.obj -> Evas.obj -> unit

val title_set : Evas.obj -> string -> unit

val title_get : Evas.obj -> string

val icon_name_set : Evas.obj -> string -> unit

val icon_name_get : Evas.obj -> string

val role_set : Evas.obj -> string -> unit

val role_get : Evas.obj -> string

val icon_object_set : Evas.obj -> Evas.obj -> unit

val icon_object_get : Evas.obj -> Evas.obj

val autodel_set : Evas.obj -> bool -> unit

val autodel_get : Evas.obj -> bool

val activate : Evas.obj -> unit

val lower : Evas.obj -> unit

(** elm_win_raise *)
val raises : Evas.obj -> unit

val center : Evas.obj -> bool -> bool -> unit

val borderless_set : Evas.obj -> bool -> unit

val borderless_get : Evas.obj -> bool

val shaped_set : Evas.obj -> bool -> unit

val shaped_get : Evas.obj -> bool

val alpha_set : Evas.obj -> bool -> unit

