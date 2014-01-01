type policy = [`auto | `on | `off]

type single_direction = [`none | `soft | `hard | `last]

type movement_block = [
  | `no_block
  | `block_vertical
  | `block_horizontal
  | `block_vertical_horizontal]

external add : Evas.obj -> Evas.obj = "ml_elm_scroller_add"

external content_min_limit : Evas.obj -> int -> int -> unit =
  "ml_elm_scroller_content_min_limit"

external region_show : Evas.obj -> int -> int -> int -> int -> unit =
  "ml_elm_scroller_region_show"

external policy_set : Evas.obj -> policy -> policy -> unit =
  "ml_elm_scroller_policy_set"

external policy_get : Evas.obj -> policy * policy = "ml_elm_scroller_policy_get"

external single_direction_set : Evas.obj -> single_direction -> unit =
  "ml_elm_scroller_single_direction_set"

external single_direction_get : Evas.obj -> single_direction =
  "ml_elm_scroller_single_direction_get"

external region_get : Evas.obj -> int * int * int * int =
  "ml_elm_scroller_region_get"

external child_size_get : Evas.obj -> int * int =
  "ml_elm_scroller_child_size_get"

external page_snap_set : Evas.obj -> bool -> bool -> unit =
  "ml_elm_scroller_page_snap_set"

external page_snap_get : Evas.obj -> bool * bool =
  "ml_elm_scroller_page_snap_get"

external bounce_set : Evas.obj -> bool -> bool -> unit =
  "ml_elm_scroller_bounce_set"

external bounce_get : Evas.obj -> bool * bool = "ml_elm_scroller_bounce_get"

external page_relative_set : Evas.obj -> float -> float -> unit =
  "ml_elm_scroller_page_relative_set"

external page_relative_get : Evas.obj -> float * float =
  "ml_elm_scroller_page_relative_get"

external page_size_set : Evas.obj -> int -> int -> unit =
  "ml_elm_scroller_page_size_set"

external page_size_get : Evas.obj -> int * int = "ml_elm_scroller_page_size_get"

external page_scroll_limit_set : Evas.obj -> int -> int -> unit =
  "ml_elm_scroller_page_scroll_limit_set"

external page_scroll_limit_get : Evas.obj -> int * int =
  "ml_elm_scroller_page_scroll_limit_get"

external current_page_get : Evas.obj -> int * int =
  "ml_elm_scroller_current_page_get"

external last_page_get : Evas.obj -> int * int =
  "ml_elm_scroller_last_page_get"

external page_show : Evas.obj -> int -> int -> unit =
  "ml_elm_scroller_page_show"

external page_bring_in : Evas.obj -> int -> int -> unit =
  "ml_elm_scroller_page_bring_in"

external region_bring_in : Evas.obj -> int -> int -> int -> int -> unit =
  "ml_elm_scroller_region_bring_in"

external propagate_events_set : Evas.obj -> bool -> unit =
  "ml_elm_scroller_propagate_events_set"

external propagate_events_get : Evas.obj -> bool =
  "ml_elm_scroller_propagate_events_get"

external gravity_set : Evas.obj -> float -> float -> unit =
  "ml_elm_scroller_gravity_set"

external gravity_get : Evas.obj -> float * float = "ml_elm_scroller_gravity_get"

external movement_block_set : Evas.obj -> movement_block -> unit =
  "ml_elm_scroller_movement_block_set"

external movement_block_get : Evas.obj -> movement_block =
  "ml_elm_scroller_movement_block_get"

module E = struct
  type u = Evas.Event_type.u
  let f = Evas.Event_type.create_unit
  let edge_left = f "edge,left"
  let edge_right = f "edge,right"
  let edge_top = f "edge,top"
  let edge_bottom = f "edge,bottom"
  let scroll = f "scroll"
  let scroll_left = f "scroll,left"
  let scroll_right = f "scroll,right"
  let scroll_up = f "scroll,up"
  let scroll_down = f "scroll,dwon"
  let scroll_anim_start = f "scroll,anim,start"
  let scroll_anim_stop = f "scroll,anim,stop"
  let scroll_drag_start = f "scroll,drag,start"
  let scroll_drag_stop = f "scroll,drag,stop"
  let vbar_drag = f "vbar,drag"
  let vbar_press = f "vbar,press"
  let vbar_unpress = f "vbar,unpress"
  let hbar_drag = f "hbar,drag"
  let hbar_press = f "hbar,press"
  let hbar_unpress = f "hbar,unpress"
  let scroll_page_changed = f "scroll,page,changed"
  let focused = f "focused"
  let unfocused = f "unfocused"
end

