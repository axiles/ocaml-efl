(** Radio *)

(** The following function will not be interfaced:

elm_radio_value_pointer_set

Use a callback with the signal "changed" instead.

*)

val add : Evas.obj -> Evas.obj

val addx : Elm_object.t_addx

val group_add : Evas.obj -> Evas.obj -> unit

val state_value_set : Evas.obj -> int -> unit

val state_value_get : Evas.obj -> int

val value_set : Evas.obj -> int -> unit

val value_get : Evas.obj -> int

val selected_object_get : Evas.obj -> Evas.obj

