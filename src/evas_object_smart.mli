(** Smart Evas Object *)

val callback_add_ : Evas.obj -> string -> Evas.smart_cb -> unit

val callback_add : Evas.obj -> 'a Evas.Signal.t -> 'a -> unit

