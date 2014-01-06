type pos = [`invalid | `top_left | `top_right | `bottom_left | `bottom_right]

val add : Evas.obj -> Evas.obj

val pos_set : Evas.obj -> pos -> unit

val pos_get : Evas.obj -> pos

module E : sig
  type u = Evas.Event_type.u
  val clicked : u
  val focused : u
  val unfocused : u
end

