type t = Elm.transit

val add : unit -> t

val del : t -> unit

val effect_add : t -> (t -> float -> unit) -> unit

val object_add : t -> Evas.obj -> unit

val object_remove : t -> Evas.obj -> unit

val objects_get : t -> Evas.obj list

