type box_data

type box_layout = Evas.obj -> box_data -> unit

type 'a event_cb = Evas.t -> Evas.obj -> 'a -> unit

external show : Evas.obj -> unit = "ml_evas_object_show"

external size_hint_weight_set : Evas.obj -> float -> float -> unit =
  "ml_evas_object_size_hint_weight_set"

external size_hint_align_set : Evas.obj -> float -> float -> unit =
  "ml_evas_object_size_hint_align_set"

external resize : Evas.obj -> int -> int -> unit =
  "ml_evas_object_resize"

external move : Evas.obj -> int -> int -> unit =
  "ml_evas_object_move"

external size_hint_align_get : Evas.obj -> float * float =
  "ml_evas_object_size_hint_align_get"

external hide : Evas.obj -> unit = "ml_evas_object_hide"

external color_set : Evas.obj -> int -> int -> int -> int -> unit =
  "ml_evas_object_color_set"

external del : Evas.obj -> unit = "ml_evas_object_del"

external evas_get : Evas.obj -> Evas.t = "ml_evas_object_evas_get"

external rectangle_add : Evas.t -> Evas.obj = "ml_evas_object_rectangle_add"

external size_hint_min_set : Evas.obj -> int -> int -> unit =
  "ml_evas_object_size_hint_min_set"

external event_callback_add_mouse_down :
  Evas.obj -> Evas.event_mouse_down event_cb -> unit =
    "ml_evas_object_event_callback_add_mouse_down"

external visible_get : Evas.obj -> bool = "ml_evas_object_visible_get"

external size_hint_aspect_set :
  Evas.obj -> Evas.aspect_control -> int -> int -> unit =
    "ml_evas_object_size_hint_aspect_set"

external geometry_get : Evas.obj -> int * int * int * int =
  "ml_evas_object_geometry_get"

external box_layout_flow_horizontal : Evas.obj -> box_data -> unit =
  "ml_evas_object_box_layout_flow_horizontal"

