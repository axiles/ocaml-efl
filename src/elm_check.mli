(** Check *)

(** The following function will not be interfaced

elm_check_state_pointer_set

Use a callback with signal "changed" instead.*)

val add : Evas.obj -> Evas.obj

val state_set : Evas.obj -> bool -> unit

val state_get : Evas.obj -> bool

