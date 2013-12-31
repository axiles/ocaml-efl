type policy = [`auto | `on | `off]

val add : Evas.obj -> Evas.obj

val content_min_limit : Evas.obj -> int -> int -> unit

val bounce_set : Evas.obj -> bool -> bool -> unit

val bounce_get : Evas.obj -> bool * bool

val policy_set : Evas.obj -> policy -> policy -> unit

val policy_get : Evas.obj -> policy * policy

