(** elm_hover_* *)

type axis = [`none | `horizontal | `vertical | `both]

val add : Evas.obj -> Evas.obj

val target_set : Evas.obj -> Evas.obj -> unit

val target_get : Evas.obj -> Evas.obj

val parent_set : Evas.obj -> Evas.obj -> unit

val parent_get : Evas.obj -> Evas.obj

val best_content_location_get : Evas.obj -> axis -> string option

val dismiss : Evas.obj -> unit

module E : sig
  type u = Evas.Event_type.u
  val clicked : u
  val dismissed : u
  val smart_changed : u
  val focused : u
  val unfocused : u
end

