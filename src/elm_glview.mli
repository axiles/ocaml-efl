type mode = [`none | `alpha | `depth | `stencil | `direct]

type resize_policy = [`recreate | `scale]

type render_policy = [`on_demand | `always]

type func_cb = Evas.obj -> unit

val add : Evas.obj -> Evas.obj

val size_set : Evas.obj -> int -> int -> unit

val size_get : Evas.obj -> int * int

val gl_api_get : Evas.obj -> Evas.gl_api

val mode_set : Evas.obj -> mode list -> unit

val resize_policy_set : Evas.obj -> resize_policy -> bool

val render_policy_set : Evas.obj -> render_policy -> bool

val init_func_set : Evas.obj -> func_cb -> unit

val del_func_set : Evas.obj -> func_cb -> unit

val resize_func_set : Evas.obj -> func_cb -> unit

val render_func_set : Evas.obj -> func_cb -> unit

val changed_set : Evas.obj -> unit

