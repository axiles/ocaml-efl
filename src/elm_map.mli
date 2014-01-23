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

val add : Evas.obj -> Evas.obj

val zoom_set : Evas.obj -> int -> unit

val zoom_get : Evas.obj -> int

val zoom_mode_set : Evas.obj -> zoom_mode -> unit

val zoom_mode_get : Evas.obj -> zoom_mode

val zoom_min_set : Evas.obj -> int -> unit

val zoom_min_get : Evas.obj -> int

val zoom_max_set : Evas.obj -> int -> unit

val zoom_max_get : Evas.obj -> int

val region_get : Evas.obj -> float * float

val region_bring_in : Evas.obj -> float -> float -> unit

val region_show : Evas.obj -> float -> float -> unit

val canvas_to_region_convert : Evas.obj -> int -> int -> float * float

val region_to_canvas_convert : Evas.obj -> float -> float -> int * int

val paused_set : Evas.obj -> bool -> unit

val paused_get : Evas.obj -> bool

val rotate_set : Evas.obj -> float -> int -> int -> unit

val rotate_get : Evas.obj -> float * int * int

val wheel_disabled_set : Evas.obj -> bool -> unit

val wheel_disabled_get : Evas.obj -> bool

val user_agent_set : Evas.obj -> string -> unit

val user_agent_get : Evas.obj -> string

val overlay_add : Evas.obj -> float -> float -> overlay

val overlays_get : Evas.obj -> overlay list

val overlay_del : overlay -> unit

val overlay_type_get : overlay -> overlay_type

val overlay_hide_set : overlay -> bool -> unit

val overlay_hide_get : overlay -> bool

val overlay_displayed_zoom_min_set : overlay -> int -> unit

val overlay_displayed_zoom_min_get : overlay -> int

val overlay_paused_set : overlay -> bool -> unit

val overlay_paused_get : overlay -> bool

val overlay_visible_get : overlay -> bool

val overlay_content_set : overlay -> Evas.obj option -> unit

val overlay_content_get : overlay -> Evas.obj option

val overlay_icon_set : overlay -> Evas.obj option -> unit

val overlay_icon_get : overlay -> Evas.obj option

val overlay_region_set : overlay -> float -> float -> unit

val overlay_region_get : overlay -> float * float

val overlay_color_set : overlay -> int -> int -> int -> int -> unit

val overlay_color_get : overlay -> int * int * int * int

val overlay_show : overlay -> unit

val overlays_show : overlay list -> unit

val overlay_get_cb_set : overlay -> overlay_get_cb -> unit

val overlay_class_add : Evas.obj -> overlay

val overlay_class_append : overlay -> overlay -> unit

val overlay_class_remove : overlay -> overlay -> unit

val overlay_class_zoom_max_set : overlay -> int -> unit

val overlay_class_zoom_max_get : overlay -> int

