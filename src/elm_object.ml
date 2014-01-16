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

external tree_focus_allow_get : Evas.obj -> bool =
  "ml_elm_object_tree_focus_allow_get"

external tree_focus_allow_set : Evas.obj -> bool -> unit =
  "ml_elm_object_tree_focus_allow_set"

(* General *)

type item

type select_mode = [`default | `always | `none | `display_only]

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

external signal_callback_del :
  Evas.obj -> string -> string -> Edje.signal_cb -> unit =
  "ml_elm_object_signal_callback_del"

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

external item_signal_emit : item -> string -> string -> unit =
  "ml_elm_object_item_signal_emit"

external item_del : item -> unit = "ml_elm_object_item_del"

external item_tooltip_text_set : item -> string -> unit =
  "ml_elm_object_item_tooltip_text_set"

type tooltip_item_content_cb = Evas.obj -> Evas.obj -> Evas.obj option

external item_tooltip_content_cb_set :
  item -> tooltip_item_content_cb -> unit =
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

external style_set : Evas.obj -> string -> bool = "ml_elm_object_style_set"

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

