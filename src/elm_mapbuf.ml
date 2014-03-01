external add : Evas.obj -> Evas.obj = "ml_elm_mapbuf_add"

external enabled_set : Evas.obj -> bool -> unit = "ml_elm_mapbuf_enabled_set"

external enabled_get : Evas.obj -> bool = "ml_elm_mapbuf_enabled_get"

external smooth_set : Evas.obj -> bool -> unit = "ml_elm_mapbuf_smooth_set"

external smooth_get : Evas.obj -> bool = "ml_elm_mapbuf_smooth_get"

external alpha_set : Evas.obj -> bool -> unit = "ml_elm_mapbuf_alpha_set"

external alpha_get : Evas.obj -> bool = "ml_elm_mapbuf_alpha_get"

external auto_set : Evas.obj -> bool -> unit = "ml_elm_mapbuf_auto_set"

external auto_get : Evas.obj -> bool = "ml_elm_mapbuf_auto_get"

external point_color_set : Evas.obj -> int -> int -> int -> int -> int -> unit =
  "ml_elm_mapbuf_point_color_set_byte"
  "ml_elm_mapbuf_point_color_set_native"

external point_color_get : Evas.obj -> int -> int * int * int * int =
  "ml_elm_mapbuf_point_color_get"

