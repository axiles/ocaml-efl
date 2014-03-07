type t = Evas.obj

type box_data

type box_layout = t -> box_data -> unit

type 'a event_cb = Evas.t -> t -> 'a -> unit

external rectangle_add : Evas.t -> t = "ml_evas_object_rectangle_add"

external box_layout_flow_horizontal : t -> box_data -> unit =
  "ml_evas_object_box_layout_flow_horizontal"

external box_layout_horizontal : t -> box_data -> unit =
  "ml_evas_object_box_layout_horizontal"

external box_layout_vertical : t -> box_data -> unit =
  "ml_evas_object_box_layout_vertical"

external box_layout_stack : t -> box_data -> unit =
  "ml_evas_object_box_layout_stack"

external box_layout_homogeneous_vertical : t -> box_data -> unit =
  "ml_evas_object_box_layout_homogeneous_vertical"

external box_layout_homogeneous_horizontal : t -> box_data -> unit =
  "ml_evas_object_box_layout_homogeneous_horizontal"

external box_layout_flow_vertical : t -> box_data -> unit =
  "ml_evas_object_box_layout_flow_vertical"

(* Basic Object Manipulation *)

external clip_set : t -> t -> unit = "ml_evas_object_clip_set"

external ref : t -> unit = "ml_evas_object_ref"

external unref : t -> unit = "ml_evas_object_unref"

external ref_get : t -> int = "ml_evas_object_ref_get"

external del : t -> unit = "ml_evas_object_del"

external move : t -> int -> int -> unit = "ml_evas_object_move"

external resize : t -> int -> int -> unit = "ml_evas_object_resize"

external geometry_get : t -> int * int * int * int =
  "ml_evas_object_geometry_get"

external geometry_set : t -> int -> int -> int -> int -> unit =
  "ml_evas_object_geometry_set"

external show : t -> unit = "ml_evas_object_show"

external hide : t -> unit = "ml_evas_object_hide"

external visible_get : t -> bool = "ml_evas_object_visible_get"

external color_set : t -> int -> int -> int -> int -> unit =
  "ml_evas_object_color_set"

external color_get : Evas.obj -> int * int * int * int =
  "ml_evas_object_color_get"

external evas_get : t -> Evas.t = "ml_evas_object_evas_get"

external clip_get : t -> t option = "ml_evas_object_clip_get"

external clip_unset : t -> unit = "ml_evas_object_clip_unset"

external clipees_get : t -> t list = "ml_evas_object_clipees_get"

external clipees_has : t -> bool = "ml_evas_object_clipees_has"

external focus_set : t -> bool -> unit = "ml_evas_object_focus_set"

external focus_get : t -> bool = "ml_evas_object_focus_get"

external layer_set : t -> int -> unit = "ml_evas_object_layer_set"

external layer_get : t -> int = "ml_evas_object_layer_get"

external name_set : t -> string -> unit = "ml_evas_object_name_set"

external name_get : t -> string = "ml_evas_object_name_get"

external type_get : t -> string = "ml_evas_object_type_get"

external raise : t -> unit = "ml_evas_object_raise"

external lower : t -> unit = "ml_evas_object_lower"

external stack_above : t -> t -> unit = "ml_evas_object_stack_above"

external stack_below : t -> t -> unit = "ml_evas_object_stack_below"

external above_get : t -> t option = "ml_evas_object_above_get"

external below_get : t -> t option = "ml_evas_object_below_get"

(* Object Events *)

external event_callback_add_mouse_in :
  t -> Evas_event.mouse_in event_cb -> unit =
    "ml_evas_object_event_callback_add_mouse_in"

external event_callback_add_mouse_out :
  t -> Evas_event.mouse_out event_cb -> unit =
    "ml_evas_object_event_callback_add_mouse_out"

external event_callback_add_mouse_down :
  t -> Evas_event.mouse_down event_cb -> unit =
    "ml_evas_object_event_callback_add_mouse_down"

external event_callback_add_mouse_up :
  t -> Evas_event.mouse_up event_cb -> unit =
    "ml_evas_object_event_callback_add_mouse_up"

external event_callback_add_mouse_move :
  t -> Evas_event.mouse_move event_cb -> unit =
    "ml_evas_object_event_callback_add_mouse_move"

external event_callback_add_mouse_wheel :
  t -> Evas_event.mouse_wheel event_cb -> unit =
    "ml_evas_object_event_callback_add_mouse_wheel"

external event_callback_add_multi_down :
  t -> Evas_event.multi_down event_cb -> unit =
    "ml_evas_object_event_callback_add_multi_down"

external event_callback_add_multi_up :
  t -> Evas_event.multi_up event_cb -> unit =
    "ml_evas_object_event_callback_add_multi_up"

external event_callback_add_multi_move :
  t -> Evas_event.multi_move event_cb -> unit =
    "ml_evas_object_event_callback_add_multi_move"

external event_callback_add_free : t -> unit event_cb -> unit =
  "ml_evas_object_event_callback_add_free"

external event_callback_add_key_down :
  t -> Evas_event.key_down event_cb -> unit =
    "ml_evas_object_event_callback_add_key_down"

external event_callback_add_key_up : t -> Evas_event.key_up event_cb -> unit =
  "ml_evas_object_event_callback_add_key_up"

external event_callback_add_focus_in : t -> unit event_cb -> unit =
  "ml_evas_object_event_callback_add_focus_in"

external event_callback_add_focus_out : t -> unit event_cb -> unit =
  "ml_evas_object_event_callback_add_focus_out"

external event_callback_add_show : t -> unit event_cb -> unit =
  "ml_evas_object_event_callback_add_show"

external event_callback_add_hide : t -> unit event_cb -> unit =
  "ml_evas_object_event_callback_add_hide"

external event_callback_add_move : t -> unit event_cb -> unit =
  "ml_evas_object_event_callback_add_move"

external event_callback_add_resize : t -> unit event_cb -> unit =
  "ml_evas_object_event_callback_add_resize"

external event_callback_add_restack : t -> unit event_cb -> unit =
  "ml_evas_object_event_callback_add_restack"

external event_callback_add_del : t -> unit event_cb -> unit =
  "ml_evas_object_event_callback_add_del"

external event_callback_add_hold : t -> Evas_event.hold event_cb -> unit =
  "ml_evas_object_event_callback_add_hold"

external event_callback_add_changed_size_hints : t -> unit event_cb -> unit =
  "ml_evas_object_event_callback_add_changed_size_hints"

external event_callback_add_image_preloaded : t -> unit event_cb -> unit =
  "ml_evas_object_event_callback_add_image_preloaded"

external event_callback_add_image_unloaded : t -> unit event_cb -> unit =
  "ml_evas_object_event_callback_add_image_unloaded"

external event_callback_priority_add_mouse_in :
  t -> Evas.callback_priority -> Evas_event.mouse_in event_cb -> unit =
    "ml_evas_object_event_callback_priority_add_mouse_in"

external event_callback_priority_add_mouse_out :
  t -> Evas.callback_priority -> Evas_event.mouse_out event_cb -> unit =
    "ml_evas_object_event_callback_priority_add_mouse_out"

external event_callback_priority_add_mouse_down :
  t -> Evas.callback_priority -> Evas_event.mouse_down event_cb -> unit =
    "ml_evas_object_event_callback_priority_add_mouse_down"

external event_callback_priority_add_mouse_up :
  t -> Evas.callback_priority -> Evas_event.mouse_up event_cb -> unit =
    "ml_evas_object_event_callback_priority_add_mouse_up"

external event_callback_priority_add_mouse_move :
  t -> Evas.callback_priority -> Evas_event.mouse_move event_cb -> unit =
    "ml_evas_object_event_callback_priority_add_mouse_move"

external event_callback_priority_add_mouse_wheel :
  t -> Evas.callback_priority -> Evas_event.mouse_wheel event_cb -> unit =
    "ml_evas_object_event_callback_priority_add_mouse_wheel"

external event_callback_priority_add_multi_down :
  t -> Evas.callback_priority -> Evas_event.multi_down event_cb -> unit =
    "ml_evas_object_event_callback_priority_add_multi_down"

external event_callback_priority_add_multi_up :
  t -> Evas.callback_priority -> Evas_event.multi_up event_cb -> unit =
    "ml_evas_object_event_callback_priority_add_multi_up"

external event_callback_priority_add_multi_move :
  t -> Evas.callback_priority -> Evas_event.multi_move event_cb -> unit =
    "ml_evas_object_event_callback_priority_add_multi_move"

external event_callback_priority_add_free :
  t -> Evas.callback_priority -> unit event_cb -> unit =
    "ml_evas_object_event_callback_priority_add_free"

external event_callback_priority_add_key_down :
  t -> Evas.callback_priority -> Evas_event.key_down event_cb -> unit =
    "ml_evas_object_event_callback_priority_add_key_down"

external event_callback_priority_add_key_up :
  t -> Evas.callback_priority -> Evas_event.key_up event_cb -> unit =
    "ml_evas_object_event_callback_priority_add_key_up"

external event_callback_priority_add_focus_in :
  t -> Evas.callback_priority -> unit event_cb -> unit =
    "ml_evas_object_event_callback_priority_add_focus_in"

external event_callback_priority_add_focus_out :
  t -> Evas.callback_priority -> unit event_cb -> unit =
    "ml_evas_object_event_callback_priority_add_focus_out"

external event_callback_priority_add_show :
  t -> Evas.callback_priority -> unit event_cb -> unit =
    "ml_evas_object_event_callback_priority_add_show"

external event_callback_priority_add_hide :
  t -> Evas.callback_priority -> unit event_cb -> unit =
    "ml_evas_object_event_callback_priority_add_hide"

external event_callback_priority_add_move :
  t -> Evas.callback_priority -> unit event_cb -> unit =
    "ml_evas_object_event_callback_priority_add_move"

external event_callback_priority_add_resize :
  t -> Evas.callback_priority -> unit event_cb -> unit =
    "ml_evas_object_event_callback_priority_add_resize"

external event_callback_priority_add_restack :
  t -> Evas.callback_priority -> unit event_cb -> unit =
    "ml_evas_object_event_callback_priority_add_restack"

external event_callback_priority_add_del :
  t -> Evas.callback_priority -> unit event_cb -> unit =
    "ml_evas_object_event_callback_priority_add_del"

external event_callback_priority_add_hold :
  t -> Evas.callback_priority -> Evas_event.hold event_cb -> unit =
    "ml_evas_object_event_callback_priority_add_hold"

external event_callback_priority_add_changed_size_hints :
  t -> Evas.callback_priority -> unit event_cb -> unit =
    "ml_evas_object_event_callback_priority_add_changed_size_hints"

external event_callback_priority_add_image_preloaded :
  t -> Evas.callback_priority -> unit event_cb -> unit =
    "ml_evas_object_event_callback_priority_add_image_preloaded"

external event_callback_priority_add_image_unloaded :
  t -> Evas.callback_priority -> unit event_cb -> unit =
    "ml_evas_object_event_callback_priority_add_image_unloaded"

external pass_events_set : t -> bool -> unit =
  "ml_evas_object_pass_events_set"

external pass_events_get : t -> bool = "ml_evas_object_pass_events_get"

external repeat_events_set : t -> bool -> unit =
  "ml_evas_object_repeat_events_set"

external repeat_events_get : t -> bool =
  "ml_evas_object_repeat_events_get"

external propagate_events_set : t -> bool -> unit =
  "ml_evas_object_propagate_events_set"

external propagate_events_get : t -> bool =
  "ml_evas_object_propagate_events_get"

external freeze_events_set : t -> bool -> unit =
  "ml_evas_object_freeze_events_set"

external freeze_events_get : t -> bool =
  "ml_evas_object_freeze_events_get"

(* UV Mapping *)

external map_enable_set : t -> bool -> unit =
  "ml_evas_object_map_enable_set"

external map_enable_get : t -> bool = "ml_evas_object_map_enable_get"

external map_set : t -> Evas.map -> unit = "ml_evas_object_map_set"

external map_get : t -> Evas.map = "ml_evas_object_map_get"

(* Size Hints *)

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

external size_hint_min_get : t -> int * int =
  "ml_evas_object_size_hint_min_get"

external size_hint_min_set : t -> int -> int -> unit =
  "ml_evas_object_size_hint_min_set"

external size_hint_max_get : t -> int * int =
  "ml_evas_object_size_hint_max_get"

external size_hint_max_set : t -> int -> int -> unit =
  "ml_evas_object_size_hint_max_set"

external size_hint_display_mode_get : t -> Evas.display_mode =
  "ml_evas_object_size_hint_display_mode_get"

external size_hint_display_mode_set : t -> Evas.display_mode -> unit =
  "ml_evas_object_size_hint_display_mode_set"

external size_hint_request_get : t -> int * int =
  "ml_evas_object_size_hint_request_get"

external size_hint_request_set : t -> int -> int -> unit =
  "ml_evas_object_size_hint_request_set"

external size_hint_aspect_get : t -> Evas.aspect_control * int * int =
  "ml_evas_object_size_hint_aspect_get"

external size_hint_aspect_set : t -> Evas.aspect_control -> int -> int -> unit =
  "ml_evas_object_size_hint_aspect_set"

external size_hint_align_get : t -> float * float =
  "ml_evas_object_size_hint_align_get"

external size_hint_align_set : t -> float -> float -> unit =
  "ml_evas_object_size_hint_align_set"

external size_hint_weight_get : t -> float * float =
  "ml_evas_object_size_hint_weight_get"

external size_hint_weight_set : t -> float -> float -> unit =
  "ml_evas_object_size_hint_weight_set"

external size_hint_padding_get : t -> int * int * int * int =
  "ml_evas_object_size_hint_padding_get"

external size_hint_padding_set : t -> int -> int -> int -> int -> unit =
  "ml_evas_object_size_hint_padding_set"

let size_hint_set obj list =
  let aux (hw, vw, ha, va) hint =
    match (hint : size_hint) with
    | `expand -> (Evas.hint_expand, Evas.hint_expand, ha, va)
    | `hexpand -> (Evas.hint_expand, vw, ha, va)
    | `vexpand -> (hw, Evas.hint_expand, ha, va)
    | `fill -> (hw, vw, Evas.hint_fill, Evas.hint_fill)
    | `hfill -> (hw, vw, Evas.hint_fill, va)
    | `vfill -> (hw, vw, ha, Evas.hint_fill)
    | `center -> (hw, vw, 0.5, 0.5)
    | `hcenter -> (hw, vw, 0.5, va)
    | `vcenter -> (hw, vw, ha, 0.5)
    | `weight0 -> (0., 0., ha, va)
    | `hweight0 -> (0., vw, ha, va)
    | `vweight0 -> (hw, 0., ha, va)
    | `weight x -> (x, x, ha, va)
    | `hweight x -> (x, vw, ha, va)
    | `vweight x -> (hw, x, ha, va)
    | `align x -> (hw, vw, x, x)
    | `halign x -> (hw, vw, x, va)
    | `valign x -> (hw, vw, ha, x) in
  let (hw, vw, ha, va) = List.fold_left aux (0., 0., 0.5, 0.5) list in
  size_hint_weight_set obj hw vw;
  size_hint_align_set obj ha va

(* Extra Object Manipulation *)

type pointer_mode = [`autograb | `nograb | `no_grab_no_repeat_updown]

external pointer_mode_set : t -> pointer_mode -> unit =
  "ml_evas_object_pointer_mode_set"

external pointer_mode_get : t -> pointer_mode =
  "ml_evas_object_pointer_mode_get"

external anti_alias_set : t -> bool -> unit = "ml_evas_object_anti_alias_set"

external anti_alias_get : t -> bool = "ml_evas_object_anti_alias_get"

external scale_set : t -> float -> unit = "ml_evas_object_scale_set"

external scale_get : t -> float = "ml_evas_object_scale_get"

external render_op_set : t -> Evas.render_op -> unit =
  "ml_evas_object_render_op_set"

external render_op_get : t -> Evas.render_op = "ml_evas_object_render_op_get"

external precise_is_inside_set : t -> bool -> unit =
  "ml_evas_object_precise_is_inside_set"

external precise_is_inside_get : t -> bool =
  "ml_evas_object_precise_is_inside_get"

external static_clip_set : t -> bool -> unit = "ml_evas_object_static_clip_set"

external static_clip_get : t -> bool = "ml_evas_object_static_clip_get"

(* Finding Objects *)

external name_find : Evas.t -> string -> t option = "ml_evas_object_name_find"

external name_child_find : t -> string -> int -> t option =
  "ml_evas_object_name_child_find"

external top_at_xy_get : Evas.t -> int -> int -> bool -> bool -> t option =
  "ml_evas_object_top_at_xy_get"

external top_at_pointer_get : Evas.t -> t option =
  "ml_evas_object_top_at_pointer_get"

