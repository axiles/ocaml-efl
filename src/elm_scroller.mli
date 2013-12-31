type policy = [`auto | `on | `off]

val add : Evas.obj -> Evas.obj

val content_min_limit : Evas.obj -> int -> int -> unit

val region_show : Evas.obj -> int -> int -> int -> int -> unit

val policy_set : Evas.obj -> policy -> policy -> unit

val policy_get : Evas.obj -> policy * policy

val region_get : Evas.obj -> int * int * int * int

val child_size_get : Evas.obj -> int * int

val bounce_set : Evas.obj -> bool -> bool -> unit

val bounce_get : Evas.obj -> bool * bool

val page_relative_set : Evas.obj -> float -> float -> unit

val page_relative_get : Evas.obj -> float * float

