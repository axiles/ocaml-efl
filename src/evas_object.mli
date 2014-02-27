(** Evas Object *)

type t = Evas.obj

type box_data

type box_layout = t -> box_data -> unit

type 'a event_cb = Evas.t -> t -> 'a -> unit

val show : t -> unit

val size_hint_weight_set : t -> float -> float -> unit

val size_hint_align_set : t -> float -> float -> unit

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

val size_hint_set : t -> size_hint list -> unit

val resize : t -> int -> int -> unit

val move : t -> int -> int -> unit

val size_hint_align_get : t -> float * float

val hide : t -> unit

val color_set : t -> int -> int -> int -> int -> unit

val del : t -> unit

val evas_get : t -> Evas.t

val rectangle_add : Evas.t -> t

val size_hint_min_set : t -> int -> int -> unit

val event_callback_add_mouse_in : t -> Evas_event.mouse_in event_cb -> unit

val event_callback_add_mouse_out : t -> Evas_event.mouse_out event_cb -> unit

val event_callback_add_mouse_down : t -> Evas_event.mouse_down event_cb -> unit

val event_callback_add_mouse_up : t -> Evas_event.mouse_up event_cb -> unit

val event_callback_add_mouse_move : t -> Evas_event.mouse_move event_cb -> unit

val event_callback_add_mouse_wheel :
  t -> Evas_event.mouse_wheel event_cb -> unit

val event_callback_add_multi_down : t -> Evas_event.multi_down event_cb -> unit

val event_callback_add_multi_up : t -> Evas_event.multi_up event_cb -> unit

val event_callback_add_multi_move : t -> Evas_event.multi_move event_cb -> unit

val event_callback_add_free : t -> unit event_cb -> unit

val event_callback_add_key_down : t -> Evas_event.key_down event_cb -> unit

val event_callback_add_key_up : t -> Evas_event.key_up event_cb -> unit

val event_callback_add_focus_in : t -> unit event_cb -> unit

val event_callback_add_focus_out : t -> unit event_cb -> unit

val event_callback_add_show : t -> unit event_cb -> unit

val event_callback_add_hide : t -> unit event_cb -> unit

val event_callback_add_move : t -> unit event_cb -> unit

val event_callback_add_resize : t -> unit event_cb -> unit

val event_callback_add_restack : t -> unit event_cb -> unit

val event_callback_add_del : t -> unit event_cb -> unit

val event_callback_add_hold : t -> Evas_event.hold event_cb -> unit

val event_callback_add_changed_size_hints : t -> unit event_cb -> unit

val event_callback_add_image_preloaded : t -> unit event_cb -> unit

val event_callback_add_image_unloaded : t -> unit event_cb -> unit

val visible_get : t -> bool

val size_hint_aspect_set : t -> Evas.aspect_control -> int -> int -> unit

val geometry_get : t -> int * int * int * int

val box_layout_flow_horizontal : t -> box_data -> unit

val box_layout_horizontal : t -> box_data -> unit

val box_layout_vertical : t -> box_data -> unit

val box_layout_stack : t -> box_data -> unit

val box_layout_homogeneous_vertical : t -> box_data -> unit

val box_layout_homogeneous_horizontal : t -> box_data -> unit

val box_layout_flow_vertical : t -> box_data -> unit

(* {2 Basic Object Manipulation} *)

val clip_set : t -> t -> unit

