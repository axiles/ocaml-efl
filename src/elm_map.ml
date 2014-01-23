type overlay_type = [
  | `none
  | `default
  | `_class
  | `group
  | `bubble
  | `rout
  | `line
  | `polygon
  | `circle
  | `scale]

type overlay

type zoom_mode = [`manual | `auto_fit | `auto_fill | `last]

type overlay_get_cb = Evas.obj -> overlay -> unit

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

external user_agent_set : Evas.obj -> string -> unit =
  "ml_elm_map_user_agent_set"

external user_agent_get : Evas.obj -> string = "ml_elm_map_user_agent_get"

external overlay_add : Evas.obj -> float -> float -> overlay =
  "ml_elm_map_overlay_add"

external overlays_get : Evas.obj -> overlay list = "ml_elm_map_overlays_get"

external overlay_del : overlay -> unit = "ml_elm_map_overlay_del"

external overlay_type_get : overlay -> overlay_type =
  "ml_elm_map_overlay_type_get"

external overlay_hide_set : overlay -> bool -> unit =
  "ml_elm_map_overlay_hide_set"

external overlay_hide_get : overlay -> bool = "ml_elm_map_overlay_hide_get"

external overlay_displayed_zoom_min_set : overlay -> int -> unit =
  "ml_elm_map_overlay_displayed_zoom_min_set"

external overlay_displayed_zoom_min_get : overlay -> int =
  "ml_elm_map_overlay_displayed_zoom_min_get"

external overlay_paused_set : overlay -> bool -> unit =
  "ml_elm_map_overlay_paused_set"

external overlay_paused_get : overlay -> bool = "ml_elm_map_overlay_paused_get"

external overlay_visible_get : overlay -> bool =
  "ml_elm_map_overlay_visible_get"

external overlay_content_set : overlay -> Evas.obj option -> unit =
  "ml_elm_map_overlay_content_set"

external overlay_content_get : overlay -> Evas.obj option =
  "ml_elm_map_overlay_content_get"

external overlay_icon_set : overlay -> Evas.obj option -> unit =
  "ml_elm_map_overlay_icon_set"

external overlay_icon_get : overlay -> Evas.obj option =
  "ml_elm_map_overlay_icon_get"

external overlay_region_set : overlay -> float -> float -> unit =
  "ml_elm_map_overlay_region_set"

external overlay_region_get : overlay -> float * float =
  "ml_elm_map_overlay_region_get"

external overlay_color_set : overlay -> int -> int -> int -> int -> unit =
  "ml_elm_map_overlay_color_set"

external overlay_color_get : overlay -> int * int * int * int =
  "ml_elm_map_overlay_color_get"

external overlay_show : overlay -> unit = "ml_elm_map_overlay_show"

external overlays_show : overlay list -> unit = "ml_elm_map_overlays_show"

external overlay_get_cb_set : overlay -> overlay_get_cb -> unit =
  "ml_elm_map_overlay_get_cb_set"

external overlay_class_add : Evas.obj -> overlay =
  "ml_elm_map_overlay_class_add"

external overlay_class_append : overlay -> overlay -> unit =
  "ml_elm_map_overlay_class_append"

external overlay_class_remove : overlay -> overlay -> unit =
  "ml_elm_map_overlay_class_remove"

