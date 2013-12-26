type item_class = Elm_gen.item_class = {
  item_style : string;
  func_text_get : Evas.obj -> string -> string;
  func_content_get : Evas.obj -> string -> Evas.obj option;
  func_state_get : Evas.obj -> string -> bool;
  func_del : Evas.obj -> unit;
}

type item_type = [`none | `tree | `group]

type item_field_type = [`all | `text | `content | `state]

type item_scrollto_type = [`none | `_in | `top | `middle]

external add : Evas.obj -> Evas.obj = "ml_elm_genlist_add"

external clear : Evas.obj -> unit = "ml_elm_genlist_clear"

external multi_select_set : Evas.obj -> bool -> unit =
  "ml_elm_genlist_multi_select_set"

external multi_select_get : Evas.obj -> bool = "ml_elm_genlist_multi_select_get"

external mode_set : Evas.obj -> Elm_list.mode -> unit =
  "ml_elm_genlist_mode_set"

external mode_get : Evas.obj -> Elm_list.mode = "ml_elm_genlist_mode_get"

external item_append :
  Evas.obj -> item_class -> Elm_object.item option -> item_type ->
    Evas.smart_cb -> Elm_object.item =
  "ml_elm_genlist_item_append"

external item_prepend :
  Evas.obj -> item_class -> Elm_object.item option -> item_type ->
    Evas.smart_cb -> Elm_object.item =
  "ml_elm_genlist_item_prepend"

external item_insert_before :
  Evas.obj -> item_class -> Elm_object.item option -> Elm_object.item ->
    item_type -> Evas.smart_cb -> Elm_object.item =
  "ml_elm_genlist_item_insert_before_byte"
  "ml_elm_genlist_item_insert_before_native"

external item_insert_after :
  Evas.obj -> item_class -> Elm_object.item option -> Elm_object.item ->
    item_type -> Evas.smart_cb -> Elm_object.item =
  "ml_elm_genlist_item_insert_after_byte"
  "ml_elm_genlist_item_insert_after_native"

external selected_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_genlist_selected_item_get"

external selected_items_get : Evas.obj -> Elm_object.item list =
  "ml_elm_genlist_selected_items_get"

external realized_items_get : Evas.obj -> Elm_object.item list =
  "ml_elm_genlist_realized_items_get"

external first_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_genlist_first_item_get"

external last_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_genlist_last_item_get"

external item_next_get : Elm_object.item -> Elm_object.item option =
  "ml_elm_genlist_item_next_get"

external item_prev_get : Elm_object.item -> Elm_object.item option =
  "ml_elm_genlist_item_prev_get"

external item_selected_set : Elm_object.item -> bool -> unit =
  "ml_elm_genlist_item_selected_set"

external item_selected_get : Elm_object.item -> bool =
  "ml_elm_genlist_item_selected_get"

external item_show : Elm_object.item -> item_scrollto_type -> unit =
  "ml_elm_genlist_item_show"

external item_bring_in : Elm_object.item -> item_scrollto_type -> unit =
  "ml_elm_genlist_item_bring_in"

external item_update : Elm_object.item -> unit = "ml_elm_genlist_item_update"

external item_index_get : Elm_object.item -> int =
  "ml_elm_genlist_item_index_get"

external realized_items_update : Evas.obj -> unit =
  "ml_elm_genlist_realized_items_update"

external items_count : Evas.obj -> int = "ml_elm_genlist_items_count"

external item_tooltip_text_set : Elm_object.item -> string -> unit =
  "ml_elm_genlist_item_tooltip_text_set"

external item_tooltip_content_cb_set_aux :
  Elm_object.item -> (Evas.obj -> Evas.obj -> Evas.obj) ->
    Evas.smart_cb -> unit =
      "ml_elm_genlist_item_tooltip_content_cb_set"

let item_tooltip_content_cb_set it func del_cb =
  let func1 obj tooltip = func obj tooltip it in
  let del_cb1 obj ptr = del_cb obj in
  item_tooltip_content_cb_set_aux it func1 del_cb1

external item_tooltip_unset : Elm_object.item -> unit =
  "ml_elm_genlist_item_tooltip_unset"

external item_tooltip_style_set : Elm_object.item -> string -> unit =
  "ml_elm_genlist_item_tooltip_style_set"

external item_tooltip_style_get : Elm_object.item -> string =
  "ml_elm_genlist_item_tooltip_style_get"

external item_tooltip_window_mode_set : Elm_object.item -> bool -> unit =
  "ml_elm_genlist_item_tooltip_window_mode_set"

external item_tooltip_window_mode_get : Elm_object.item -> bool =
  "ml_elm_genlist_item_tooltip_window_mode_get"

external item_cursor_set : Elm_object.item -> string -> unit =
  "ml_elm_genlist_item_cursor_set"

external item_cursor_get : Elm_object.item -> string option =
  "ml_elm_genlist_item_cursor_get"

external item_cursor_unset : Elm_object.item -> unit =
  "ml_elm_genlist_item_cursor_unset"

external item_cursor_style_set : Elm_object.item -> string -> unit =
  "ml_elm_genlist_item_cursor_style_set"

external item_cursor_style_get : Elm_object.item -> string option =
  "ml_elm_genlist_item_cursor_style_get"

external item_cursor_engine_only_set : Elm_object.item -> bool -> unit =
  "ml_elm_genlist_item_cursor_engine_only_set"

external item_cursor_engine_only_get : Elm_object.item -> bool =
  "ml_elm_genlist_item_cursor_engine_only_get"

external homogeneous_set : Evas.obj -> bool -> unit =
  "ml_elm_genlist_homogeneous_set"

external homogeneous_get : Evas.obj -> bool =
  "elm_genlist_homogeneous_get"

external block_count_set : Evas.obj -> int -> unit =
  "ml_elm_genlist_block_count_set"

external block_count_get : Evas.obj -> int = "ml_elm_genlist_block_count_get"

external longpress_timeout_set : Evas.obj -> float -> unit =
  "ml_elm_genlist_longpress_timeout_set"

external longpress_timeout_get : Evas.obj -> float =
  "ml_elm_genlist_longpress_timeout_get"

external at_xy_item_get :
  Evas.obj -> int -> int -> (Elm_object.item * int) option =
    "elm_genlist_at_xy_item_get"

external item_parent_get : Elm_object.item -> Elm_object.item option =
  "ml_elm_genlist_item_parent_get"

external item_subitems_clear : Elm_object.item -> unit =
  "ml_elm_genlist_item_subitems_clear"

external item_expanded_set : Elm_object.item -> bool -> unit =
  "ml_elm_genlist_item_expanded_set"

external item_expanded_get : Elm_object.item -> bool =
  "ml_elm_genlist_item_expanded_get"

external item_expanded_depth_get : Elm_object.item -> int =
  "ml_elm_genlist_item_expanded_depth_get"

external item_all_contents_unset : Elm_object.item -> Elm_object.item list =
   "ml_elm_genlist_item_all_contents_unset"

external item_promote : Elm_object.item -> unit = "ml_elm_genlist_item_promote"

external item_demote : Elm_object.item -> unit = "ml_elm_genlist_item_demote"

external item_fields_update :
  Elm_object.item -> string -> item_field_type -> unit =
    "ml_elm_genlist_item_fields_update"

external item_decorate_mode_set : Elm_object.item -> string -> bool -> unit =
  "ml_elm_genlist_item_decorate_mode_set"

external item_decorate_mode_get : Elm_object.item -> string =
  "ml_elm_genlist_item_decorate_mode_get"

external decorated_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_genlist_decorated_item_get"

external reorder_mode_set : Evas.obj -> bool -> unit =
  "ml_elm_genlist_reorder_mode_set"

external reorder_mode_get : Evas.obj -> bool = "ml_elm_genlist_reorder_mode_get"

external item_type_get : Elm_object.item -> item_type =
  "ml_elm_genlist_item_type_get"

external decorate_mode_set : Evas.obj -> bool -> unit =
  "ml_elm_genlist_decorate_mode_set"

external decorate_mode_get : Evas.obj -> bool =
  "ml_elm_genlist_decorate_mode_get"

external item_flip_set : Elm_object.item -> bool -> unit =
  "ml_elm_genlist_item_flip_set"

external item_flip_get : Elm_object.item -> bool =
  "ml_elm_genlist_item_flip_get"

external tree_effect_enabled_set : Evas.obj -> bool -> unit =
  "ml_elm_genlist_tree_effect_enabled_set"

external tree_effect_enabled_get : Evas.obj -> bool =
  "ml_elm_genlist_tree_effect_enabled_get"

external select_mode_set : Evas.obj -> Elm_object.select_mode -> unit =
  "ml_elm_genlist_select_mode_set"

external select_mode_get : Evas.obj -> Elm_object.select_mode =
  "ml_elm_genlist_select_mode_get"

external highlight_mode_set : Evas.obj -> bool -> unit =
  "ml_elm_genlist_highlight_mode_set"

external highlight_mode_get : Evas.obj -> bool =
  "ml_elm_genlist_highlight_mode_get"

external item_select_mode_set :
  Elm_object.item -> Elm_object.select_mode -> unit =
    "ml_elm_genlist_item_select_mode_set"

external item_select_mode_get : Elm_object.item -> Elm_object.select_mode =
  "ml_elm_genlist_item_select_mode_get"

module E = struct
  type 'a v = 'a Evas.Event_type.v
  type u = Evas.Event_type.u
  let f = Evas.Event_type.create_unit
  let g x = Evas.Event_type.create x Elm_object.item_of_ptr
  let activated = g "activated"
  let pressed = g "pressed"
  let released = g "released"
  let clicked_double = g "clicked_double"
  let selected = g "selected"
  let unselected = g "unselected"
  let expanded = g "expanded"
  let contracted = g "contracted"
  let expand_request = g "expand,request"
  let contract_request = g "contract,request"
  let realized = g "realized"
  let unrealized = f "unrealized"
  let drag_start_up = f "drag,start,up"
  let drag_start_down = f "drag,start,down"
  let drag_start_right = f "drag,start,right"
  let drag_start_left = f "drag,start,left"
  let drag_stop = f "drag_stop"
  let drag = f "drag"
  let longpressed = f "longpressed"
  let scroll_anim_start = f "scroll,anim,start"
  let scroll_anim_stop = f "scroll,anim,stop"
  let scroll_drag_start = f "scroll,drag,start"
  let scroll_drag_stop = f "scroll,drag,stop"
  let edge_top = f "edge,top"
  let edge_bottom = f "edge,bottom"
  let edge_left = f "edge,left"
  let edge_right = f "edge,right"
  let multi_swipe_left = f "multi,swipe,left"
  let multi_swipe_right = f "multi,swipe,right"
  let multi_swipe_up = f "multi,swipe,up"
  let multi_swipe_down = f "multi,swipe,down"
  let multi_pinch_out = f "multi,pinch,out"
  let multi_pinch_in = f "multi,pinch,in"
  let swipe = f "swipe"
  let moved = f "moved"
  let moved_after = g "moved,after"
  let moved_before = g "moved,before"
  let index_update = f "index,update"
  let language_changed = f "language,changed"
  let tree_effect_finished = f "tree,effect,finished"
  let highlighted = g "highlighted"
  let unhighlighted = g "unhighlighted"
  let focused = f "focused"
  let unfocused = f "unfocused"
end

