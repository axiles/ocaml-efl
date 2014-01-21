type zoom_mode = [`manual | `auto_fit | `auto_fill | `last]

external add : Evas.obj -> Evas.obj = "ml_elm_map_add"

external zoom_set : Evas.obj -> int -> unit = "ml_elm_map_zoom_set"

external zoom_get : Evas.obj -> int = "ml_elm_map_zoom_get"

external zoom_mode_set : Evas.obj -> zoom_mode -> unit =
  "ml_elm_map_zoom_mode_set"

external zoom_mode_get : Evas.obj -> zoom_mode = "ml_elm_map_zoom_mode_get"

external zoom_min_set : Evas.obj -> int -> unit = "ml_elm_map_zoom_min_set"

external zoom_min_get : Evas.obj -> int = "ml_elm_map_zoom_min_get"

external zoom_max_set : Evas.obj -> int -> unit = "ml_elm_map_zoom_max_set"

external zoom_max_get : Evas.obj -> int = "ml_elm_map_zoom_max_get"

external region_get : Evas.obj -> float * float = "ml_elm_map_region_get"

external region_bring_in : Evas.obj -> float -> float -> unit =
  "ml_elm_map_region_bring_in"

external region_show : Evas.obj -> float -> float -> unit =
  "ml_elm_map_region_show"

external canvas_to_region_convert : Evas.obj -> int -> int -> float * float =
  "ml_elm_map_canvas_to_region_convert"

external region_to_canvas_convert : Evas.obj -> float -> float -> int * int =
  "ml_elm_map_region_to_canvas_convert"

external paused_set : Evas.obj -> bool -> unit = "ml_elm_map_paused_set"

external paused_get : Evas.obj -> bool = "ml_elm_map_paused_get"

external rotate_set : Evas.obj -> float -> int -> int -> unit =
  "ml_elm_map_rotate_set"

external rotate_get : Evas.obj -> float * int * int = "ml_elm_map_rotate_get"

external wheel_disabled_set : Evas.obj -> bool -> unit =
  "ml_elm_map_wheel_disabled_set"

external wheel_disabled_get : Evas.obj -> bool = "ml_elm_map_wheel_disabled_get"

