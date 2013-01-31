(** elm_button_* *)

val add : Evas.obj -> Evas.obj

val autorepeat_gap_timeout_get : Evas.obj -> float

val autorepeat_gap_timeout_set : Evas.obj -> float -> unit

val autorepeat_get : Evas.obj -> bool

val autorepeat_initial_timeout_get : Evas.obj -> float

val autorepeat_initial_timeout_set : Evas.obj -> float -> unit

val autorepeat_set : Evas.obj -> bool -> unit

module E : sig
  type u = Evas.Event_type.u
  val clicked : u
  val repeated : u
  val pressed : u
  val unpressed : u
end

