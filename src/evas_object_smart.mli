val callback_add : Evas.obj -> string -> Evas.smart_cb -> unit

val callback_add_safe : Evas.obj -> ('a, 'b) Evas.Event_type.t -> 'b -> unit

