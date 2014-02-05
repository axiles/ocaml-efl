type mode = [`none | `alpha | `depth | `stencil | `direct]

val add : Evas.obj -> Evas.obj

val size_set : Evas.obj -> int -> int -> unit

val size_get : Evas.obj -> int * int

val gl_api_get : Evas.obj -> Evas.gl_api

val mode_set : Evas.obj -> mode list -> unit

