type t = Elm.transit

val add : unit -> t

val del : t -> unit

val effect_add : t -> (t -> float -> unit) -> unit

