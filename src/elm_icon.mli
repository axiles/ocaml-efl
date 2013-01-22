type ty = [`none | `file | `standard]

type lookup_order = [`fdo_theme | `theme_fdo | `fdo | `theme]

val add : Evas.obj -> Evas.obj

val thumb_set : Evas.obj -> string -> string -> ?g:string -> unit -> unit

val standard_set_with_bool : Evas.obj -> string -> bool

val standard_set : Evas.obj -> string -> unit

val standard_get : Evas.obj -> string option

val order_lookup_set : Evas.obj -> lookup_order -> unit

