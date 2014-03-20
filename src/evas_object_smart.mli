(** Smart Evas Object *)

val callback_add_ : Evas.obj -> string -> Evas.smart_cb -> unit

val callback_add : Evas.obj -> 'a Evas.Signal.t -> 'a -> unit

type sig_with_cb

val create_sig_with_cb : 'a Evas.Signal.t -> 'a -> sig_with_cb

val connect : sig_with_cb -> Evas.obj -> unit

