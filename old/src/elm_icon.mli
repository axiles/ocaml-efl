(** Icon *)

type ty = [`none | `file | `standard]

type lookup_order = [`fdo_theme | `theme_fdo | `fdo | `theme]

val add : Evas.obj -> Evas.obj

val addx : Elm_object.t_addx

val thumb_set : Evas.obj -> string -> string -> ?g:string -> unit -> unit

val standard_set : Evas.obj -> string -> bool

val standard_get : Evas.obj -> string option

val order_lookup_set : Evas.obj -> lookup_order -> unit

val order_lookup_get : Evas.obj -> lookup_order

