(** elm_radio_* *)

(** The following function will not be interfaced:

elm_radio_value_pointer_set

Use a callback with the signal "changed" instead.

*)

val add : Evas.obj -> Evas.obj

val group_add : Evas.obj -> Evas.obj -> unit

val state_value_set : Evas.obj -> int -> unit

val state_value_get : Evas.obj -> int

val value_set : Evas.obj -> int -> unit

val value_get : Evas.obj -> int

val selected_object_get : Evas.obj -> Evas.obj

module E : sig
  type u = Evas.Event_type.u
  val changed : u
  val focused : u
  val unfocused : u
end

