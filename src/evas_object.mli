(** Evas Object *)

type box_data

type box_layout = Evas.obj -> box_data -> unit

type 'a event_cb = Evas.t -> Evas.obj -> 'a -> unit

val show : Evas.obj -> unit

val size_hint_weight_set : Evas.obj -> float -> float -> unit

val size_hint_align_set : Evas.obj -> float -> float -> unit

type size_hint = [
  | `expand
  | `hexpand
  | `vexpand
  | `fill
  | `hfill
  | `vfill
  | `center
  | `hcenter
  | `vcenter
  | `weight0
  | `hweight0
  | `vweight0
  | `weight of float
  | `hweight of float
  | `vweight of float
  | `align of float
  | `halign of float
  | `valign of float]

val size_hint_set : Evas.obj -> size_hint list -> unit

val resize : Evas.obj -> int -> int -> unit

val move : Evas.obj -> int -> int -> unit

val size_hint_align_get : Evas.obj -> float * float

val hide : Evas.obj -> unit

val color_set : Evas.obj -> int -> int -> int -> int -> unit

val del : Evas.obj -> unit

val evas_get : Evas.obj -> Evas.t

val rectangle_add : Evas.t -> Evas.obj

val size_hint_min_set : Evas.obj -> int -> int -> unit

val event_callback_add_mouse_in :
  Evas.obj -> Evas_event.mouse_in event_cb -> unit

val event_callback_add_mouse_out :
  Evas.obj -> Evas_event.mouse_out event_cb -> unit

val event_callback_add_mouse_down :
  Evas.obj -> Evas_event.mouse_down event_cb -> unit

val event_callback_add_mouse_up :
  Evas.obj -> Evas_event.mouse_up event_cb -> unit

val event_callback_add_mouse_move :
  Evas.obj -> Evas_event.mouse_move event_cb -> unit

val event_callback_add_mouse_wheel :
  Evas.obj -> Evas_event.mouse_wheel event_cb -> unit

val event_callback_add_multi_down :
  Evas.obj -> Evas_event.multi_down event_cb -> unit

val event_callback_add_multi_up :
  Evas.obj -> Evas_event.multi_up event_cb -> unit

val event_callback_add_multi_move :
  Evas.obj -> Evas_event.multi_move event_cb -> unit

val event_callback_add_free : Evas.obj -> unit event_cb -> unit

val event_callback_add_key_down :
  Evas.obj -> Evas_event.key_down event_cb -> unit

val event_callback_add_key_up :
  Evas.obj -> Evas_event.key_up event_cb -> unit

val event_callback_add_focus_in : Evas.obj -> unit event_cb -> unit

val event_callback_add_focus_out : Evas.obj -> unit event_cb -> unit

val event_callback_add_show : Evas.obj -> unit event_cb -> unit

val event_callback_add_hide : Evas.obj -> unit event_cb -> unit

val event_callback_add_move : Evas.obj -> unit event_cb -> unit

val event_callback_add_resize : Evas.obj -> unit event_cb -> unit

val event_callback_add_restack : Evas.obj -> unit event_cb -> unit

val event_callback_add_del : Evas.obj -> unit event_cb -> unit

val event_callback_add_hold :
  Evas.obj -> Evas_event.hold event_cb -> unit

val event_callback_add_changed_size_hints : Evas.obj -> unit event_cb -> unit

val event_callback_add_image_preloaded : Evas.obj -> unit event_cb -> unit

val event_callback_add_image_unloaded : Evas.obj -> unit event_cb -> unit

val visible_get : Evas.obj -> bool

val size_hint_aspect_set : Evas.obj -> Evas.aspect_control -> int -> int -> unit

val geometry_get : Evas.obj -> int * int * int * int

val box_layout_flow_horizontal : Evas.obj -> box_data -> unit

val box_layout_horizontal : Evas.obj -> box_data -> unit

val box_layout_vertical : Evas.obj -> box_data -> unit

val box_layout_stack : Evas.obj -> box_data -> unit

val box_layout_homogeneous_vertical : Evas.obj -> box_data -> unit

val box_layout_homogeneous_horizontal : Evas.obj -> box_data -> unit

val box_layout_flow_vertical : Evas.obj -> box_data -> unit

