(** elm_icon_* Elm_Icon_* *)

type ty = [`none | `file | `standard]

type lookup_order = [`fdo_theme | `theme_fdo | `fdo | `theme]

val add : Evas.obj -> Evas.obj

val thumb_set : Evas.obj -> string -> string -> ?g:string -> unit -> unit

val standard_set : Evas.obj -> string -> bool

val standard_get : Evas.obj -> string option

val order_lookup_set : Evas.obj -> lookup_order -> unit

val order_lookup_get : Evas.obj -> lookup_order

module E : sig
  type u = Evas.Event_type.u
  val thumb_done : u
  val thumb_error : u
end

