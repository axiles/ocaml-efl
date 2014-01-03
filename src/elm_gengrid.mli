type item_class = Elm_gen.item_class = {
  item_style : string;
  func_text_get : Evas.obj -> string -> string;
  func_content_get : Evas.obj -> string -> Evas.obj option;
  func_state_get : Evas.obj -> string -> bool;
  func_del : Evas.obj -> unit;
}

type item_scrollto_type = [`none | `_in | `top | `middle]

val add : Evas.obj -> Evas.obj

val clear : Evas.obj -> unit

val multi_select_set : Evas.obj -> bool -> unit

val multi_select_get : Evas.obj -> bool

val multi_select_mode_set : Evas.obj -> bool -> unit

val multi_select_mode_get : Evas.obj -> bool

val horizontal_set : Evas.obj -> bool -> unit

val horizontal_get : Evas.obj -> bool

val item_append : Evas.obj -> item_class -> Evas.smart_cb -> Elm_object.item

val item_prepend : Evas.obj -> item_class -> Evas.smart_cb -> Elm_object.item

val item_insert_before :
  Evas.obj -> item_class -> Elm_object.item -> Evas.smart_cb -> Elm_object.item

val item_insert_after :
  Evas.obj -> item_class -> Elm_object.item -> Evas.smart_cb -> Elm_object.item

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

val item_size_set : Evas.obj -> int -> int -> unit

val item_size_get : Evas.obj -> int * int

val group_item_size_set : Evas.obj -> int -> int -> unit

val group_item_size_get : Evas.obj -> int * int

val align_set : Evas.obj -> float -> float -> unit

val align_get : Evas.obj -> float * float

val reorder_mode_set : Evas.obj -> bool -> unit

val reorder_mode_get : Evas.obj -> bool

val page_show : Evas.obj -> int -> int -> unit

val item_pos_get : Elm_object.item -> int * int

val filled_set : Evas.obj -> bool -> unit

val filled_get : Evas.obj -> bool

val select_mode_set : Evas.obj -> Elm_object.select_mode -> unit

val select_mode_get : Evas.obj -> Elm_object.select_mode

val highlight_mode_set : Evas.obj -> bool -> unit

val highlight_mode_get : Evas.obj -> bool

val nth_item_get : Evas.obj -> Elm_object.item option

val item_select_mode_set : Elm_object.item -> Elm_object.select_mode -> unit

val item_select_mode_get : Elm_object.item -> Elm_object.select_mode

module E : sig
  type 'a v = 'a Evas.Event_type.v
  type u = Evas.Event_type.u
  val activated : Elm_object.item v
  val pressed : Elm_object.item v
  val released : Elm_object.item v
  val clicked_double : Elm_object.item v
  val longpressed : u
  val selected : Elm_object.item v
  val unselected : Elm_object.item v
  val realized : Elm_object.item v
  val unrealized : u
  val changed : u
  val scroll_anim_start : u
  val scroll_anim_stop : u
  val drag_start_up : u
  val drag_start_down : u
  val drag_start_left : u
  val drag_start_right : u
  val drag_stop : u
  val drag : u
  val scroll : u
  val scroll_drag_start : u
  val scroll_drag_stop : u
  val scroll_page_changed : u
  val edge_top : u
  val edge_bottom : u
  val edge_left : u
  val edge_right : u
  val moved : u
  val index_update : u
  val highlighted : Elm_object.item v
  val unhighlighted : Elm_object.item v
  val language_changed : u
  val focused : u
  val unfocused : u
end

