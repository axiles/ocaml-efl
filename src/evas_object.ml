type box_data

type box_layout = Evas.obj -> box_data -> unit

type 'a event_cb = Evas.t -> Evas.obj -> 'a -> unit

external show : Evas.obj -> unit = "ml_evas_object_show"

external size_hint_weight_set : Evas.obj -> float -> float -> unit =
  "ml_evas_object_size_hint_weight_set"

external size_hint_align_set : Evas.obj -> float -> float -> unit =
  "ml_evas_object_size_hint_align_set"

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

external event_callback_add_mouse_in :
  Evas.obj -> Evas.event_mouse_in event_cb -> unit =
    "ml_evas_object_event_callback_add_mouse_in"

external event_callback_add_mouse_out :
  Evas.obj -> Evas.event_mouse_out event_cb -> unit =
    "ml_evas_object_event_callback_add_mouse_out"

external event_callback_add_mouse_down :
  Evas.obj -> Evas.event_mouse_down event_cb -> unit =
    "ml_evas_object_event_callback_add_mouse_down"

external event_callback_add_mouse_up :
  Evas.obj -> Evas.event_mouse_up event_cb -> unit =
    "ml_evas_object_event_callback_add_mouse_up"

external event_callback_add_mouse_move :
  Evas.obj -> Evas.event_mouse_move event_cb -> unit =
    "ml_evas_object_event_callback_add_mouse_move"

external event_callback_add_mouse_wheel :
  Evas.obj -> Evas.event_mouse_wheel event_cb -> unit =
    "ml_evas_object_event_callback_add_mouse_wheel"

external event_callback_add_multi_down :
  Evas.obj -> Evas.event_multi_down event_cb -> unit =
    "ml_evas_object_event_callback_add_multi_down"

external event_callback_add_multi_up :
  Evas.obj -> Evas.event_multi_up event_cb -> unit =
    "ml_evas_object_event_callback_add_multi_up"

external event_callback_add_multi_move :
  Evas.obj -> Evas.event_multi_move event_cb -> unit =
    "ml_evas_object_event_callback_add_multi_move"

external event_callback_add_key_down :
  Evas.obj -> Evas.event_key_down event_cb -> unit =
    "ml_evas_object_event_callback_add_key_down"

external event_callback_add_free : Evas.obj -> unit event_cb -> unit =
  "ml_evas_object_event_callback_add_free"

external visible_get : Evas.obj -> bool = "ml_evas_object_visible_get"

external size_hint_aspect_set :
  Evas.obj -> Evas.aspect_control -> int -> int -> unit =
    "ml_evas_object_size_hint_aspect_set"

external geometry_get : Evas.obj -> int * int * int * int =
  "ml_evas_object_geometry_get"

external box_layout_flow_horizontal : Evas.obj -> box_data -> unit =
  "ml_evas_object_box_layout_flow_horizontal"

external box_layout_horizontal : Evas.obj -> box_data -> unit =
  "ml_evas_object_box_layout_horizontal"

external box_layout_vertical : Evas.obj -> box_data -> unit =
  "ml_evas_object_box_layout_vertical"

external box_layout_stack : Evas.obj -> box_data -> unit =
  "ml_evas_object_box_layout_stack"

external box_layout_homogeneous_vertical : Evas.obj -> box_data -> unit =
  "ml_evas_object_box_layout_homogeneous_vertical"

external box_layout_homogeneous_horizontal : Evas.obj -> box_data -> unit =
  "ml_evas_object_box_layout_homogeneous_horizontal"

external box_layout_flow_vertical : Evas.obj -> box_data -> unit =
  "ml_evas_object_box_layout_flow_vertical"

