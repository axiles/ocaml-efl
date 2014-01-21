type zoom_mode = [`manual | `auto_fit | `auto_fill | `last]

external add : Evas.obj -> Evas.obj = "ml_elm_map_add"

external zoom_set : Evas.obj -> int -> unit = "ml_elm_map_zoom_set"

external zoom_get : Evas.obj -> int = "ml_elm_map_zoom_get"

external zoom_mode_set : Evas.obj -> zoom_mode -> unit =
  "ml_elm_map_zoom_mode_set"

external zoom_mode_get : Evas.obj -> zoom_mode = "ml_elm_map_zoom_mode_get"

