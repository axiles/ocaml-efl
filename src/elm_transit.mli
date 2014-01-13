type t = Elm.transit

val add : unit -> t

val del : t -> unit

val effect_add : t -> (t -> float -> unit) -> unit

val object_add : t -> Evas.obj -> unit

val object_remove : t -> Evas.obj -> unit

val objects_get : t -> Evas.obj list

val objects_final_state_keep_set : t -> bool -> unit

val objects_final_state_keep_get : t -> bool

val event_enabled_set : t -> bool -> unit

val event_enabled_get : t -> bool

val del_cb_set : t -> (t -> unit) -> unit

val auto_reverse_set : t -> bool -> unit

val auto_reverse_get : t -> bool

val repeat_times_set : t -> int -> unit

val repeat_times_get : t -> int

