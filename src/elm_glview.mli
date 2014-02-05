type mode = [`none | `alpha | `depth | `stencil | `direct]

type resize_policy = [`recreate | `scale]

val add : Evas.obj -> Evas.obj

val size_set : Evas.obj -> int -> int -> unit

val size_get : Evas.obj -> int * int

val gl_api_get : Evas.obj -> Evas.gl_api

val mode_set : Evas.obj -> mode list -> unit

val resize_policy_set : Evas.obj -> resize_policy -> bool

