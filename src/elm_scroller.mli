type policy = [`auto | `on | `off]

val bounce_set : Evas.obj -> bool -> bool -> unit

val policy_set : Evas.obj -> policy -> policy -> unit

