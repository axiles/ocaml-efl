type item

(* Cursors *)

external cursor_set : Evas.obj -> string -> unit = "ml_elm_object_cursor_set"

external cursor_get : Evas.obj -> string = "ml_elm_object_cursor_get"

external cursor_unset : Evas.obj -> unit = "ml_elm_object_cursor_unset"

external cursor_style_set : Evas.obj -> string -> unit =
  "ml_elm_object_cursor_style_set"

external cursor_style_get : Evas.obj -> string =
  "ml_elm_object_cursor_style_get"

external cursor_theme_search_enabled_set : Evas.obj -> bool -> unit =
  "ml_elm_object_cursor_theme_search_enabled_set"

external cursor_theme_search_enabled_get : Evas.obj -> bool =
  "ml_elm_object_cursor_theme_search_enabled_get"

(* Debug *)

external tree_dump : Evas.obj -> unit = "ml_elm_object_tree_dump"

external tree_dot_dump : Evas.obj -> string -> unit =
  "ml_elm_object_tree_dot_dump"

(* Focus *)

external focus_get : Evas.obj -> bool = "ml_elm_object_focus_get"

external focus_set : Evas.obj -> bool -> unit = "ml_elm_object_focus_set"

external focus_allow_set : Evas.obj -> bool -> unit =
  "ml_elm_object_focus_allow_set"

external focus_allow_get : Evas.obj -> bool = "ml_elm_object_focus_allow_get"

external focus_custom_chain_set : Evas.obj -> Evas.obj list -> unit =
  "ml_elm_object_focus_custom_chain_set"

external focus_custom_chain_unset : Evas.obj -> unit =
  "ml_elm_object_focus_custom_chain_unset"

external focus_custom_chain_get : Evas.obj -> Evas.obj list =
  "ml_elm_object_focus_custom_chain_get"

external focus_custom_chain_append :
  Evas.obj -> Evas.obj -> Evas.obj option -> unit =
    "ml_elm_object_focus_custom_chain_append"

external focus_custom_chain_prepend :
  Evas.obj -> Evas.obj -> Evas.obj option -> unit =
    "ml_elm_object_focus_custom_chain_prepend"

external focus_next : Evas.obj -> Elm.focus_direction -> unit =
  "ml_elm_object_focus_next"

external focus_next_object_get :
  Evas.obj -> Elm.focus_direction -> Evas.obj option =
    "ml_elm_object_focus_next_object_get"

external focus_next_object_set :
  Evas.obj -> Evas.obj option -> Elm.focus_direction -> unit =
    "ml_elm_object_focus_next_object_set"

external focused_object_get : Evas.obj -> Evas.obj option =
  "ml_elm_object_focused_object_get"

external tree_focus_allow_get : Evas.obj -> bool =
  "ml_elm_object_tree_focus_allow_get"

external tree_focus_allow_set : Evas.obj -> bool -> unit =
  "ml_elm_object_tree_focus_allow_set"

external focus_highlight_style_set : Evas.obj -> string -> bool =
  "ml_elm_object_focus_highlight_style_set"

external focus_highlight_style_get : Evas.obj -> string =
  "ml_elm_object_focus_highlight_style_get"

external focused_item_get : Evas.obj -> item option =
  "ml_elm_object_focused_item_get"

external item_focus_set : item -> bool -> unit = "ml_elm_object_item_focus_set"

external item_focus_get : item -> bool = "ml_elm_object_item_focus_get"

(* General *)

type select_mode = [`default | `always | `none | `display_only]

type item_signal_cb = item -> string -> string -> unit

external item_of_ptr : Evas.ptr -> item = "%identity"

external domain_translatable_part_text_set :
  Evas.obj -> ?part:string -> ?domain:string -> ?text:string -> unit -> unit =
    "ml_elm_object_domain_translatable_part_text_set"

external translatable_part_text_get : Evas.obj -> ?p:string -> unit -> string =
  "ml_elm_object_translatable_part_text_get"

external domain_part_text_translatable_set :
  Evas.obj -> ?part:string -> ?domain:string -> bool -> unit =
    "ml_elm_object_domain_part_text_translatable_set"

external text_set : Evas.obj -> string -> unit = "ml_elm_object_text_set"

external part_text_set : Evas.obj -> ?p:string -> string -> unit =
  "ml_elm_object_part_text_set"

external text_get : Evas.obj -> string = "ml_elm_object_text_get"

external part_text_get : Evas.obj -> ?p:string -> unit -> string =
  "ml_elm_object_part_text_get"

external content_set : Evas.obj -> Evas.obj -> unit =
  "ml_elm_object_content_set"

external part_content_set : Evas.obj -> ?p:string -> Evas.obj -> unit =
  "ml_elm_object_part_content_set"

external part_content_set_null : Evas.obj -> ?p:string -> unit -> unit =
  "ml_elm_object_part_content_set_NULL"

external part_content_get : Evas.obj -> ?p:string -> unit -> Evas.obj =
  "ml_elm_object_part_content_get"

external content_unset : Evas.obj -> Evas.obj =
  "ml_elm_object_content_unset"

external part_content_unset : Evas.obj -> ?p:string -> unit -> Evas.obj =
  "ml_elm_object_part_content_unset"

external access_info_set : Evas.obj -> string -> unit =
  "ml_elm_object_access_info_set"

external name_find : Evas.obj -> string -> int -> Evas.obj option =
  "ml_elm_object_name_find"

external signal_emit : Evas.obj -> string -> string -> unit =
  "ml_elm_object_signal_emit"

external signal_callback_add :
  Evas.obj -> string -> string -> Edje.signal_cb -> unit =
  "ml_elm_object_signal_callback_add"

external event_callback_add : Evas.obj -> Elm.event_cb -> unit =
  "ml_elm_object_event_callback_add"

external orientation_mode_disabled_set : Evas.obj -> bool -> unit =
  "ml_elm_object_orientation_mode_disabled_set"

external orientation_mode_disabled_get : Evas.obj -> bool =
  "ml_elm_object_orientation_mode_disabled_get"

external item_widget_get : item -> Evas.obj = "ml_elm_object_item_widget_get"

external item_content_set : item -> Evas.obj -> unit =
  "ml_elm_object_item_content_set"

external item_part_content_set : item -> ?p:string -> Evas.obj -> unit =
  "ml_elm_object_item_part_content_set"

external item_part_content_get : item -> ?p:string -> unit -> Evas.obj =
  "ml_elm_object_item_part_content_get"

external item_part_content_unset : item -> ?p:string -> unit -> Evas.obj =
  "ml_elm_object_item_part_content_unset"

external item_part_text_set : item -> ?p:string -> string -> unit =
  "ml_elm_object_item_part_text_set"

let item_text_set obj text = item_part_text_set obj text

external item_text_get : item -> string = "ml_elm_object_item_text_get"

external item_part_text_get : item -> ?p:string -> unit -> string =
  "ml_elm_object_item_part_text_get"

external item_domain_translatable_part_text_set :
  item -> ?p:string -> ?d:string -> ?t:string -> unit -> unit =
    "ml_elm_object_item_domain_translatable_part_text_set"

external item_translatable_part_text_get : item -> ?p:string -> unit -> string =
  "ml_elm_object_item_translatable_part_text_get"

external item_domain_part_text_translatable_set :
  item -> ?p:string -> ?d:string -> bool -> unit =
    "ml_elm_object_item_domain_part_text_translatable_set"

external item_access_info_set : item -> string -> unit =
  "ml_elm_object_item_access_info_set"

external item_access_register : item -> Evas.obj =
  "ml_elm_object_item_access_register"

external item_access_unregister : item -> unit =
  "ml_elm_object_item_access_unregister"

external item_access_object_get : item -> Evas.obj =
  "ml_elm_object_item_access_object_get"

external item_access_order_set : item -> Evas.obj list -> unit =
  "ml_elm_object_item_access_order_set"

external item_access_order_get : item -> Evas.obj list =
  "ml_elm_object_item_access_order_get"

external item_access_order_unset : item -> unit =
  "ml_elm_object_item_access_order_unset"

external item_signal_emit : item -> string -> string -> unit =
  "ml_elm_object_item_signal_emit"

external item_signal_callback_add :
  item -> string -> string -> item_signal_cb -> unit =
    "ml_elm_object_item_signal_callback_add"

external item_del : item -> unit = "ml_elm_object_item_del"

external item_tooltip_text_set : item -> string -> unit =
  "ml_elm_object_item_tooltip_text_set"

type tooltip_item_content_cb = Evas.obj -> Evas.obj -> Evas.obj option

external item_tooltip_content_cb_set :
  item -> item Elm.tooltip_item_content_cb -> unit =
    "ml_elm_object_item_tooltip_content_cb_set"

external item_tooltip_unset : item -> unit = "ml_elm_object_item_tooltip_unset"

external item_tooltip_style_set : item -> string -> unit =
  "ml_elm_object_item_tooltip_style_set"

external item_tooltip_style_get : item -> string =
  "ml_elm_object_item_tooltip_style_get"

external item_cursor_set : Evas.obj -> string -> unit =
  "ml_elm_object_item_cursor_set"

external item_cursor_unset : Evas.obj -> unit =
  "ml_elm_object_item_cursor_unset"

external item_cursor_style_set : item -> string -> unit =
  "ml_elm_object_item_cursor_style_set"

external item_cursor_style_get : item -> string =
  "ml_elm_object_item_cursor_style_get"

external item_cursor_engine_only_set : item -> bool -> unit =
  "ml_elm_object_item_cursor_engine_only_set"

external item_cursor_engine_only_get : item -> bool =
  "ml_elm_object_item_cursor_engine_only_get"

external item_track : item -> Evas.obj = "ml_elm_object_item_track"

external item_untrack : item -> unit = "ml_elm_object_item_untrack"

external item_track_get : item -> int = "ml_elm_object_item_track_get"

external item_style_set : item -> string -> unit =                               
  "ml_elm_object_item_style_set"                                                 
                                                                                           
external item_style_get : item -> string = "ml_elm_object_item_style_get"

type t_addx =
  ?size_hint:Evas_object.size_hint list ->
  ?size:(int * int) ->
  ?pos:(int * int) ->
  ?win:Evas.obj ->
  ?inwin:Evas.obj ->
  ?box:Evas.obj ->
  ?content_of:Evas.obj ->
  ?packing:(Evas.obj -> unit) ->
  ?text:string ->
  ?content:Evas.obj ->
  ?style:string ->
  ?color:(int * int * int * int) ->
  ?part_text:(string * string) list ->
  ?part_content:(string * Evas.obj) list ->
  ?cb:Evas_object_smart.sig_with_cb list ->
  ?show:bool -> Evas.obj -> Evas.obj

external elm_win_resize_object_add : Evas.obj -> Evas.obj -> unit =
  "ml_elm_win_resize_object_add"

external elm_inwin_content_set : Evas.obj -> Evas.obj -> unit =
  "ml_elm_win_inwin_content_set"
  
external elm_box_pack_end : Evas.obj -> Evas.obj -> unit = "ml_elm_box_pack_end"

external style_set : Evas.obj -> string -> bool = "ml_elm_object_style_set"

let create_addx add
  ?(size_hint = [`expand; `fill])
  ?size ?pos ?win ?inwin ?box ?content_of ?packing ?text ?content ?style ?color
  ?(part_text = []) ?(part_content = []) ?(cb = []) ?(show = true) parent =
    let obj = add parent in
    Evas_object.size_hint_set obj size_hint;
    (match size with Some (w, h) -> Evas_object.resize obj w h | None -> ());
    (match pos with Some(x, y) -> Evas_object.move obj x y | None -> ());
    (match win with Some w -> elm_win_resize_object_add w obj
    | None -> (match inwin with Some w -> elm_inwin_content_set w obj
    | None -> (match box with Some b -> elm_box_pack_end b obj
    | None -> (match content_of with Some x -> content_set x obj
    | None -> (match packing with Some f -> f obj
    | None -> ())))));
    (match text with Some t -> text_set obj t| None -> ());
    (match content with Some c -> content_set obj c | None -> ());
    (match style with Some s -> ignore (style_set obj s) | None -> ());
    (match color with
    | Some (r, g, b, a) -> Evas_object.color_set obj r g b a
    | None -> ());
    List.iter (fun (p, t) -> part_text_set obj ~p t) part_text;
    List.iter (fun (p, c) -> part_content_set obj ~p c) part_content;
    if show then Evas_object.show obj;
    List.iter (fun s -> Evas_object_smart.connect s obj) cb;
    obj

(* Scrollhints *)

external scroll_hold_push : Evas.obj -> unit = "ml_elm_object_scroll_hold_push"

external scroll_hold_pop : Evas.obj -> unit = "ml_elm_object_scroll_hold_pop"

external scroll_hold_get : Evas.obj -> int = "ml_elm_object_scroll_hold_get"

external scroll_freeze_push : Evas.obj -> unit =
  "ml_elm_object_scroll_freeze_push"

external scroll_freeze_pop : Evas.obj -> unit =
  "ml_elm_object_scroll_freeze_pop"

external scroll_freeze_get : Evas.obj -> int = "ml_elm_object_scroll_freeze_get"

external scroll_lock_x_set : Evas.obj -> bool -> unit =
  "ml_elm_object_scroll_lock_x_set"

external scroll_lock_y_set : Evas.obj -> bool -> unit =
  "ml_elm_object_scroll_lock_y_set"

external scroll_lock_x_get : Evas.obj -> bool =
  "ml_elm_object_scroll_lock_x_get"

external scroll_lock_y_get : Evas.obj -> bool =
  "ml_elm_object_scroll_lock_y_get"

(* Mirroring *)

external mirrored_get : Evas.obj -> bool = "ml_elm_object_mirrored_get"

external mirrored_set : Evas.obj -> bool -> unit = "ml_elm_object_mirrored_set"

external mirrored_automatic_get : Evas.obj -> bool =
  "ml_elm_object_mirrored_automatic_get"

external mirrored_automatic_set : Evas.obj -> bool -> unit =
  "ml_elm_object_mirrored_automatic_set"

(* Widget Scaling *)

external scale_set : Evas.obj -> float -> unit = "ml_elm_object_scale_set"

external scale_get : Evas.obj -> float = "ml_elm_object_scale_get"

(* Styles *)

external style_get : Evas.obj -> string = "ml_elm_object_style_get"

external disabled_set : Evas.obj -> bool -> unit = "ml_elm_object_disabled_set"

external disabled_get : Evas.obj -> bool = "ml_elm_object_disabled_get"

external item_disabled_set : item -> bool -> unit =
  "ml_elm_object_item_disabled_set"

external item_disabled_get : item -> bool = "ml_elm_object_item_disabled_get"

(* Theme *)

external theme_set : Evas.obj -> Elm.theme option -> unit =
  "ml_elm_object_theme_set"

external theme_get : Evas.obj -> Elm.theme option = "ml_elm_object_theme_get"

(* Widget Tree Navigation *)

external widget_check : Evas.obj -> bool = "ml_elm_object_widget_check"

external parent_widget_get : Evas.obj -> Evas.obj option =
  "ml_elm_object_parent_widget_get"

external top_widget_get : Evas.obj -> Evas.obj option =
  "ml_elm_object_top_widget_get"

external widget_type_get : Evas.obj -> string option =
  "ml_elm_object_widget_type_get"

(* Tooltips *)

external tooltip_move_freeze_push : Evas.obj -> unit =
  "ml_elm_object_tooltip_move_freeze_push"

external tooltip_move_freeze_pop : Evas.obj -> unit =
  "ml_elm_object_tooltip_move_freeze_pop"

external tooltip_move_freeze_get : Evas.obj -> int =
  "ml_elm_object_tooltip_move_freeze_get"

external tooltip_show : Evas.obj -> unit = "ml_elm_object_tooltip_show"

external tooltip_hide : Evas.obj -> unit = "ml_elm_object_tooltip_hide"

external tooltip_text_set : Evas.obj -> string -> unit =
  "ml_elm_object_tooltip_text_set"

external tooltip_content_cb_set :
  Evas.obj -> Elm.tooltip_content_cb -> unit =
    "ml_elm_object_tooltip_content_cb_set"

external tooltip_unset : Evas.obj -> unit = "ml_elm_object_tooltip_unset"

external tooltip_style_set : Evas.obj -> string -> unit =
  "ml_elm_object_tooltip_style_set"

external tooltip_style_get : Evas.obj -> string =
  "ml_elm_object_tooltip_style_get"

external tooltip_window_mode_set : Evas.obj -> bool -> bool =
  "ml_elm_object_tooltip_window_mode_set"

external tooltip_window_mode_get : Evas.obj -> bool =
  "ml_elm_object_tooltip_window_mode_get"

external tooltip_orient_set : Evas.obj -> Elm.tooltip_orient -> unit =
  "ml_elm_object_tooltip_orient_set"

external tooltip_orient_get : Evas.obj -> Elm.tooltip_orient =
  "ml_elm_object_tooltip_orient_get"

