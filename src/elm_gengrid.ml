type item_class = Elm_gen.item_class = {
  item_style : string;
  func_text_get : Evas.obj -> string -> string;
  func_content_get : Evas.obj -> string -> Evas.obj option;
  func_state_get : Evas.obj -> string -> bool;
  func_del : Evas.obj -> unit;
}

type item_scrollto_type = [`none | `_in | `top | `middle]

external add : Evas.obj -> Evas.obj = "ml_elm_gengrid_add"

external clear : Evas.obj -> unit = "ml_elm_gengrid_clear"

external multi_select_set : Evas.obj -> bool -> unit =
  "ml_elm_gengrid_multi_select_set"

external multi_select_get : Evas.obj -> bool = "ml_elm_gengrid_multi_select_get"

external multi_select_mode_set : Evas.obj -> bool -> unit =
  "ml_elm_gengrid_multi_select_mode_set"

external multi_select_mode_get : Evas.obj -> bool =
  "ml_elm_gengrid_multi_select_mode_get"

external horizontal_set : Evas.obj -> bool -> unit =
  "ml_elm_gengrid_horizontal_set"

external horizontal_get : Evas.obj -> bool = "ml_elm_gengrid_horizontal_get"

external item_append :
  Evas.obj -> item_class -> Evas.smart_cb -> Elm_object.item =
  "ml_elm_gengrid_item_append"

external item_prepend :
  Evas.obj -> item_class -> Evas.smart_cb -> Elm_object.item =
  "ml_elm_gengrid_item_prepend"

external item_insert_before :
  Evas.obj -> item_class -> Elm_object.item -> Evas.smart_cb ->
    Elm_object.item =
      "ml_elm_gengrid_item_insert_before"

external item_insert_after :
  Evas.obj -> item_class -> Elm_object.item -> Evas.smart_cb ->
    Elm_object.item =
      "ml_elm_gengrid_item_insert_after"

external selected_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_gengrid_selected_item_get"

external selected_items_get : Evas.obj -> Elm_object.item list =
  "ml_elm_gengrid_selected_items_get"

external realized_items_get : Evas.obj -> Elm_object.item list =
  "ml_elm_gengrid_realized_items_get"

external first_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_gengrid_first_item_get"

external last_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_gengrid_last_item_get"

external item_next_get : Elm_object.item -> Elm_object.item option =
  "ml_elm_gengrid_item_next_get"

external item_prev_get : Elm_object.item -> Elm_object.item option =
  "ml_elm_gengrid_item_prev_get"

external item_selected_set : Elm_object.item -> bool -> unit =
  "ml_elm_gengrid_item_selected_set"

external item_selected_get : Elm_object.item -> bool =
  "ml_elm_gengrid_item_selected_get"

external item_show : Elm_object.item -> item_scrollto_type -> unit =
  "ml_elm_gengrid_item_show"

external item_bring_in : Elm_object.item -> item_scrollto_type -> unit =
  "ml_elm_gengrid_item_bring_in"

external item_update : Elm_object.item -> unit = "ml_elm_gengrid_item_update"

external item_index_get : Elm_object.item -> int =
  "ml_elm_gengrid_item_index_get"

external items_count : Evas.obj -> int = "ml_elm_gengrid_items_count"

external item_tooltip_text_set : Elm_object.item -> string -> unit =
  "ml_elm_gengrid_item_tooltip_text_set"

external item_tooltip_content_cb_set :
  Elm_object.item -> Elm_object.item Elm.tooltip_item_content_cb ->
    Evas.smart_cb -> unit =
      "ml_elm_gengrid_item_tooltip_content_cb_set"

(*let item_tooltip_content_cb_set it func del_cb =
  let func1 obj tooltip = func obj tooltip it in
  let del_cb1 obj ptr = del_cb obj in
  item_tooltip_content_cb_set_aux it func1 del_cb1*)

external item_tooltip_unset : Elm_object.item -> unit =
  "ml_elm_gengrid_item_tooltip_unset"

external item_tooltip_style_set : Elm_object.item -> string -> unit =
  "ml_elm_gengrid_item_tooltip_style_set"

external item_tooltip_style_get : Elm_object.item -> string =
  "ml_elm_gengrid_item_tooltip_style_get"

external item_tooltip_window_mode_set : Elm_object.item -> bool -> unit =
  "ml_elm_gengrid_item_tooltip_window_mode_set"

external item_tooltip_window_mode_get : Elm_object.item -> bool =
  "ml_elm_gengrid_item_tooltip_window_mode_get"

external item_cursor_set : Elm_object.item -> string -> unit =
  "ml_elm_gengrid_item_cursor_set"

external item_cursor_get : Elm_object.item -> string option =
  "ml_elm_gengrid_item_cursor_get"

external item_cursor_unset : Elm_object.item -> unit =
  "ml_elm_gengrid_item_cursor_unset"

external item_cursor_style_set : Elm_object.item -> string -> unit =
  "ml_elm_gengrid_item_cursor_style_set"

external item_cursor_style_get : Elm_object.item -> string option =
  "ml_elm_gengrid_item_cursor_style_get"

external item_cursor_engine_only_set : Elm_object.item -> bool -> unit =
  "ml_elm_gengrid_item_cursor_engine_only_set"

external item_cursor_engine_only_get : Elm_object.item -> bool =
  "ml_elm_gengrid_item_cursor_engine_only_get"

external item_size_set : Evas.obj -> int -> int -> unit =
  "ml_elm_gengrid_item_size_set"

external item_size_get : Evas.obj -> int * int = "ml_elm_gengrid_item_size_get"

external group_item_size_set : Evas.obj -> int -> int -> unit =
  "ml_elm_gengrid_group_item_size_set"

external group_item_size_get : Evas.obj -> int * int =
  "ml_elm_gengrid_group_item_size_get"

external align_set : Evas.obj -> float -> float -> unit =
  "ml_elm_gengrid_align_set"

external align_get : Evas.obj -> float * float = "ml_elm_gengrid_align_get"

external reorder_mode_set : Evas.obj -> bool -> unit =
  "ml_elm_gengrid_reorder_mode_set"

external reorder_mode_get : Evas.obj -> bool = "ml_elm_gengrid_reorder_mode_get"

external page_show : Evas.obj -> int -> int -> unit =
  "ml_elm_gengrid_page_show"

external item_pos_get : Elm_object.item -> int * int =
  "ml_elm_gengrid_item_pos_get"

external filled_set : Evas.obj -> bool -> unit = "ml_elm_gengrid_filled_set"

external filled_get : Evas.obj -> bool = "ml_elm_gengrid_filled_get"

external select_mode_set : Evas.obj -> Elm_object.select_mode -> unit =
  "ml_elm_gengrid_select_mode_set"

external select_mode_get : Evas.obj -> Elm_object.select_mode =
  "ml_elm_gengrid_select_mode_get"

external highlight_mode_set : Evas.obj -> bool -> unit =
  "ml_elm_gengrid_highlight_mode_set"

external highlight_mode_get : Evas.obj -> bool =
  "ml_elm_gengrid_highlight_mode_get"

external nth_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_gengrid_nth_item_get"

external item_select_mode_set :
  Elm_object.item -> Elm_object.select_mode -> unit =
    "ml_elm_gengrid_item_select_mode_set"

external item_select_mode_get : Elm_object.item -> Elm_object.select_mode =
  "ml_elm_gengrid_item_select_mode_get"

