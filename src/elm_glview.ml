type mode = [`none | `alpha | `depth | `stencil | `direct]

type resize_policy = [`recreate | `scale]

external add : Evas.obj -> Evas.obj = "ml_elm_glview_add"

external size_set : Evas.obj -> int -> int -> unit = "ml_elm_glview_size_set"

external size_get : Evas.obj -> int * int = "ml_elm_glview_size_get"

external gl_api_get : Evas.obj -> Evas.gl_api = "ml_elm_glview_gl_api_get"

external mode_set : Evas.obj -> mode list -> unit = "ml_elm_glview_mode_set"

external resize_policy_set : Evas.obj -> resize_policy -> bool =
  "ml_elm_glview_resize_policy_set"

