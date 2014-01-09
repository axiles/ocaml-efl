(** elm_frame_* *)

val add : Evas.obj -> Evas.obj

val autocollapse_set : Evas.obj -> bool -> unit

val autocollapse_get : Evas.obj -> bool

val collapse_set : Evas.obj -> bool -> unit

val collapse_get : Evas.obj -> bool

val collapse_go : Evas.obj -> bool -> unit

module E : sig
  type u = Evas.Event_type.u
  val clicked : u
end

