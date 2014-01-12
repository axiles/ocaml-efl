(** elm_conformant_ *)

val add : Evas.obj -> Evas.obj

module E : sig
  type u = Evas.Event_type.u
  val virtualkeypad_state_on : u
  val virtualkeypad_state_off : u
  val clipboard_state_on : u
  val clipboard_state_off : u
end

