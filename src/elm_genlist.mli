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

val add : Evas.obj -> Evas.obj

val clear : Evas.obj -> unit

val multi_select_set : Evas.obj -> bool -> unit

val multi_select_get : Evas.obj -> bool

val mode_set : Evas.obj -> Elm_list.mode -> unit

val mode_get : Evas.obj -> Elm_list.mode

val item_append :
  Evas.obj -> item_class -> Elm_object.item option -> item_type ->
    Evas.smart_cb -> Elm_object.item

val item_prepend :
  Evas.obj -> item_class -> Elm_object.item option -> item_type ->
    Evas.smart_cb -> Elm_object.item

val item_insert_before :
  Evas.obj -> item_class -> Elm_object.item option -> Elm_object.item ->
    item_type -> Evas.smart_cb -> Elm_object.item

val item_insert_after :
  Evas.obj -> item_class -> Elm_object.item option -> Elm_object.item ->
    item_type -> Evas.smart_cb -> Elm_object.item

val selected_item_get : Evas.obj -> Elm_object.item option

val selected_items_get : Evas.obj -> Elm_object.item list

val realized_items_get : Evas.obj -> Elm_object.item list

val first_item_get : Evas.obj -> Elm_object.item option

val last_item_get : Evas.obj -> Elm_object.item option

val item_next_get : Elm_object.item -> Elm_object.item option

val item_prev_get : Elm_object.item -> Elm_object.item option

val item_selected_set : Elm_object.item -> bool -> unit

val item_selected_get : Elm_object.item -> bool

val item_show : Elm_object.item -> item_scrollto_type -> unit

val item_bring_in : Elm_object.item -> item_scrollto_type -> unit

val item_update : Elm_object.item -> unit

val item_index_get : Elm_object.item -> int

val realized_items_update : Evas.obj -> unit

val items_count : Evas.obj -> int

val item_tooltip_text_set : Elm_object.item -> string -> unit

val item_tooltip_content_cb_set :
  Elm_object.item -> Elm_object.item Elm_tooltip.item_content_cb ->
    (Evas.obj -> unit) -> unit

val item_tooltip_unset : Elm_object.item -> unit

val item_tooltip_style_set : Elm_object.item -> string -> unit

val item_tooltip_style_get : Elm_object.item -> string

val item_tooltip_window_mode_set : Elm_object.item -> bool -> unit

val item_tooltip_window_mode_get : Elm_object.item -> bool

val item_cursor_set : Elm_object.item -> string -> unit

val item_cursor_get : Elm_object.item -> string option

val item_cursor_unset : Elm_object.item -> unit

val item_cursor_style_set : Elm_object.item -> string -> unit

val item_cursor_style_get : Elm_object.item -> string option

val item_cursor_engine_only_set : Elm_object.item -> bool -> unit

val item_cursor_engine_only_get : Elm_object.item -> bool

val homogeneous_set : Evas.obj -> bool -> unit

val homogeneous_get : Evas.obj -> bool

val block_count_set : Evas.obj -> int -> unit

val block_count_get : Evas.obj -> int

val longpress_timeout_set : Evas.obj -> float -> unit

val longpress_timeout_get : Evas.obj -> float

val at_xy_item_get : Evas.obj -> int -> int -> (Elm_object.item * int) option

val item_parent_get : Elm_object.item -> Elm_object.item option

val item_subitems_clear : Elm_object.item -> unit

val item_expanded_set : Elm_object.item -> bool -> unit

val item_expanded_get : Elm_object.item -> bool

val item_expanded_depth_get : Elm_object.item -> int

val item_all_contents_unset : Elm_object.item -> Elm_object.item list

val item_promote : Elm_object.item -> unit

val item_demote : Elm_object.item -> unit

val item_fields_update : Elm_object.item -> string -> item_field_type -> unit

val item_decorate_mode_set : Elm_object.item -> string -> bool -> unit

val item_decorate_mode_get : Elm_object.item -> string

val decorated_item_get : Evas.obj -> Elm_object.item option

val reorder_mode_set : Evas.obj -> bool -> unit

val reorder_mode_get : Evas.obj -> bool

val item_type_get : Elm_object.item -> item_type

val decorate_mode_set : Evas.obj -> bool -> unit

val decorate_mode_get : Evas.obj -> bool

val item_flip_set : Elm_object.item -> bool -> unit

val item_flip_get : Elm_object.item -> bool

val tree_effect_enabled_set : Evas.obj -> bool -> unit

val tree_effect_enabled_get : Evas.obj -> bool

val select_mode_set : Evas.obj -> Elm_object.select_mode -> unit

val select_mode_get : Evas.obj -> Elm_object.select_mode

val highlight_mode_set : Evas.obj -> bool -> unit

val highlight_mode_get : Evas.obj -> bool

val item_select_mode_set : Elm_object.item -> Elm_object.select_mode -> unit

val item_select_mode_get : Elm_object.item -> Elm_object.select_mode

module E : sig
  type 'a v = 'a Evas.Event_type.v
  type u = Evas.Event_type.u
  val activated : Elm_object.item v
  val pressed : Elm_object.item v
  val released : Elm_object.item v
  val clicked_double : Elm_object.item v
  val selected : Elm_object.item v
  val unselected : Elm_object.item v
  val expanded : Elm_object.item v
  val contracted : Elm_object.item v
  val expand_request : Elm_object.item v
  val contract_request : Elm_object.item v
  val realized : Elm_object.item v
  val unrealized : u
  val drag_start_up : u
  val drag_start_down : u
  val drag_start_left : u
  val drag_start_right : u
  val drag_stop : u
  val drag : u
  val longpressed : u
  val scroll_anim_start : u
  val scroll_anim_stop : u
  val scroll_drag_start : u
  val scroll_drag_stop : u
  val edge_top : u
  val edge_bottom : u
  val edge_left : u
  val edge_right : u
  val multi_swipe_left : u
  val multi_swipe_right : u
  val multi_swipe_up : u
  val multi_swipe_down : u
  val multi_pinch_out : u
  val multi_pinch_in : u
  val swipe : u
  val moved : u
  val moved_after : Elm_object.item v
  val moved_before : Elm_object.item v
  val index_update : u
  val language_changed : u
  val tree_effect_finished : u
  val highlighted : Elm_object.item v
  val unhighlighted : Elm_object.item v
  val focused : u
  val unfocused : u
end

