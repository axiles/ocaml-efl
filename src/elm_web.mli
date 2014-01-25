type window_features

type window_open = Evas.obj -> bool -> window_features -> Evas.obj option

val add : Evas.obj -> Evas.obj

val useragent_set : Evas.obj -> string -> unit

val useragent_get : Evas.obj -> string

val webkit_view_get : Evas.obj -> Evas.obj

val window_create_hook_set : Evas.obj -> window_open -> unit

