(** Evas Object *)

type t = Evas.obj

type box_data

type box_layout = t -> box_data -> unit

type 'a event_cb = Evas.t -> t -> 'a -> unit

val rectangle_add : Evas.t -> t

val box_layout_flow_horizontal : t -> box_data -> unit

val box_layout_horizontal : t -> box_data -> unit

val box_layout_vertical : t -> box_data -> unit

val box_layout_stack : t -> box_data -> unit

val box_layout_homogeneous_vertical : t -> box_data -> unit

val box_layout_homogeneous_horizontal : t -> box_data -> unit

val box_layout_flow_vertical : t -> box_data -> unit

(* {2 Basic Object Manipulation} *)

val clip_set : t -> t -> unit

val ref : t -> unit

val unref : t -> unit

val ref_get : t -> int

val del : t -> unit

val move : t -> int -> int -> unit

val resize : t -> int -> int -> unit

val geometry_get : t -> int * int * int * int

val geometry_set : t -> int -> int -> int -> int -> unit

val show : t -> unit

val hide : t -> unit

val visible_get : t -> bool

val color_set : t -> int -> int -> int -> int -> unit

val color_get : t -> int * int * int * int

val evas_get : t -> Evas.t

val clip_get : t -> t option

val clip_unset : t -> unit

val clipees_get : t -> t list

val clipees_has : t -> bool

val focus_set : t -> bool -> unit

val focus_get : t -> bool

val layer_set : t -> int -> unit

val layer_get : t -> int

val name_set : t -> string -> unit

val name_get : t -> string

val type_get : t -> string

val raise : t -> unit

val lower : t -> unit

val stack_above : t -> t -> unit

val stack_below : t -> t -> unit

val above_get : t -> t option

val below_get : t -> t option

(* {2 Object Events} *)

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

val event_callback_priority_add_mouse_in :
  t -> Evas.callback_priority -> Evas_event.mouse_in event_cb -> unit

val event_callback_priority_add_mouse_out :
  t -> Evas.callback_priority -> Evas_event.mouse_out event_cb -> unit

val event_callback_priority_add_mouse_down :
  t -> Evas.callback_priority -> Evas_event.mouse_down event_cb -> unit

val event_callback_priority_add_mouse_up :
  t -> Evas.callback_priority -> Evas_event.mouse_up event_cb -> unit

val event_callback_priority_add_mouse_move :
  t -> Evas.callback_priority -> Evas_event.mouse_move event_cb -> unit

val event_callback_priority_add_mouse_wheel :
  t -> Evas.callback_priority -> Evas_event.mouse_wheel event_cb -> unit

val event_callback_priority_add_multi_down :
  t -> Evas.callback_priority -> Evas_event.multi_down event_cb -> unit

val event_callback_priority_add_multi_up :
  t -> Evas.callback_priority -> Evas_event.multi_up event_cb -> unit

val event_callback_priority_add_multi_move :
  t -> Evas.callback_priority -> Evas_event.multi_move event_cb -> unit

val event_callback_priority_add_free :
  t -> Evas.callback_priority -> unit event_cb -> unit

val event_callback_priority_add_key_down :
  t -> Evas.callback_priority -> Evas_event.key_down event_cb -> unit

val event_callback_priority_add_key_up :
  t -> Evas.callback_priority -> Evas_event.key_up event_cb -> unit

val event_callback_priority_add_focus_in :
  t -> Evas.callback_priority -> unit event_cb -> unit

val event_callback_priority_add_focus_out :
  t -> Evas.callback_priority -> unit event_cb -> unit

val event_callback_priority_add_show :
  t -> Evas.callback_priority -> unit event_cb -> unit

val event_callback_priority_add_hide :
  t -> Evas.callback_priority -> unit event_cb -> unit

val event_callback_priority_add_move :
  t -> Evas.callback_priority -> unit event_cb -> unit

val event_callback_priority_add_resize :
  t -> Evas.callback_priority -> unit event_cb -> unit

val event_callback_priority_add_restack :
  t -> Evas.callback_priority -> unit event_cb -> unit

val event_callback_priority_add_del :
  t -> Evas.callback_priority -> unit event_cb -> unit

val event_callback_priority_add_hold :
  t -> Evas.callback_priority -> Evas_event.hold event_cb -> unit

val event_callback_priority_add_changed_size_hints :
  t -> Evas.callback_priority -> unit event_cb -> unit

val event_callback_priority_add_image_preloaded :
  t -> Evas.callback_priority -> unit event_cb -> unit

val event_callback_priority_add_image_unloaded :
  t -> Evas.callback_priority -> unit event_cb -> unit

val pass_events_set : t -> bool -> unit

val pass_events_get : t -> bool

val repeat_events_set : t -> bool -> unit

val repeat_events_get : t -> bool

val propagate_events_set : t -> bool -> unit

val propagate_events_get : t -> bool

val freeze_events_set : t -> bool -> unit

val freeze_events_get : t -> bool

(** {2 UV Mapping} *)

val map_enable_set : t -> bool -> unit

val map_enable_get : t -> bool

val map_set : t -> Evas.map -> unit

val map_get : t -> Evas.map

(* {2 Size Hints} *)

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

val size_hint_min_get : t -> int * int

val size_hint_min_set : t -> int -> int -> unit

val size_hint_max_get : t -> int * int

val size_hint_max_set : t -> int -> int -> unit

val size_hint_display_mode_get : t -> Evas.display_mode

val size_hint_display_mode_set : t -> Evas.display_mode -> unit

val size_hint_request_get : t -> int * int

val size_hint_request_set : t -> int -> int -> unit

val size_hint_aspect_get : t -> Evas.aspect_control * int * int

val size_hint_aspect_set : t -> Evas.aspect_control -> int -> int -> unit

val size_hint_align_get : t -> float * float

val size_hint_align_set : t -> float -> float -> unit

val size_hint_weight_get : t -> float * float

val size_hint_weight_set : t -> float -> float -> unit

val size_hint_padding_get : t -> int * int * int * int

val size_hint_padding_set : t -> int -> int -> int -> int -> unit

val size_hint_set : t -> size_hint list -> unit

(** {2 Extra Object Manipulation} *)

type pointer_mode = [`autograb | `nograb | `no_grab_no_repeat_updown]

val pointer_mode_set : t -> pointer_mode -> unit

val pointer_mode_get : t -> pointer_mode

val anti_alias_set : t -> bool -> unit

val anti_alias_get : t -> bool

val scale_set : t -> float -> unit

val scale_get : t -> float

val render_op_set : t -> Evas.render_op -> unit

val render_op_get : t -> Evas.render_op

val precise_is_inside_set : t -> bool -> unit

val precise_is_inside_get : t -> bool

val static_clip_set : t -> bool -> unit

val static_clip_get : t -> bool

(** {2 Finding Objects} *)

val name_find : Evas.t -> string -> t option

val name_child_find : t -> string -> int -> t option

val top_at_xy_get : Evas.t -> int -> int -> bool -> bool -> t option

val top_at_pointer_get : Evas.t -> t option

val top_in_rectangle_get :
  Evas.t -> int -> int -> int -> int -> bool -> bool -> t option

val bottom_get : Evas.t -> t option

val top_get : Evas.t -> t option

(** {2 Line Object Functions} *)

val line_add : Evas.t -> Evas.obj

val line_xy_set : Evas.obj -> int -> int -> int -> int -> unit

val line_xy_get : Evas.obj -> int * int * int * int

