(* Cursors *)

external cursor_set : Evas.obj -> string -> unit = "ml_elm_object_cursor_set"

external cursor_get : Evas.obj -> string = "ml_elm_object_cursor_get"

external cursor_unset : Evas.obj -> unit = "ml_elm_object_cursor_unset"

external cursor_style_set : Evas.obj -> string -> unit =
  "ml_elm_object_cursor_set"

external cursor_style_get : Evas.obj -> string = "ml_elm_object_cursor_get"

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

external domain_translatable_part_text_set :
  Evas.obj -> ?part:string -> ?domain:string -> ?text:string -> unit -> unit =
    "ml_elm_object_domain_translatable_part_text_set"

external translatable_part_text_get : Evas.obj -> ?p:string -> unit -> string =
  "ml_elm_object_translatable_part_text_get"

external part_text_set : Evas.obj -> ?p:string -> string -> unit =
  "ml_elm_object_part_text_set"

external part_text_get : Evas.obj -> ?p:string -> unit -> string =
  "ml_elm_object_part_text_get"

external part_content_set : Evas.obj -> ?p:string -> Evas.obj -> unit =
  "ml_elm_object_part_content_set"

external part_content_set_null : Evas.obj -> ?p:string -> unit -> unit =
  "ml_elm_object_part_content_set_NULL"

external part_content_get : Evas.obj -> ?p:string -> unit -> Evas.obj =
  "ml_elm_object_part_content_get"

external part_content_unset : Evas.obj -> ?p:string -> unit -> Evas.obj =
  "ml_elm_object_part_content_unset"

external access_info_set : Evas.obj -> string -> unit =
  "ml_elm_object_access_info_set"

external name_find : Evas.obj -> string -> int -> Evas.obj option =
  "ml_elm_object_name_find"

(* Other *)

external signal_emit : Evas.obj -> string -> string -> unit =
  "ml_elm_object_signal_emit"

external signal_callback_add :
  Evas.obj -> string -> string -> Edje.signal_cb -> unit =
  "ml_elm_object_signal_callback_add"

external signal_callback_del :
  Evas.obj -> string -> string -> Edje.signal_cb -> unit =
  "ml_elm_object_signal_callback_del"

external text_set : Evas.obj -> string -> unit = "ml_elm_object_text_set"

external style_set : Evas.obj -> string -> bool = "ml_elm_object_style_set"

external content_set : Evas.obj -> Evas.obj -> unit =
  "ml_elm_object_content_set"

external text_get : Evas.obj -> string = "ml_elm_object_text_get"

external content_unset : Evas.obj -> Evas.obj =
  "ml_elm_object_content_unset"

external disabled_set : Evas.obj -> bool -> unit = "ml_elm_object_disabled_set"

external disabled_get : Evas.obj -> bool = "ml_elm_object_disabled_get"

external parent_widget_get : Evas.obj -> Evas.obj option =
  "ml_elm_object_parent_widget_get"

external top_widget_get : Evas.obj -> Evas.obj option =
  "ml_elm_object_top_widget_get"

external item_of_ptr : Evas.ptr -> item = "%identity"

external item_del : item -> unit = "ml_elm_object_item_del"

external item_disabled_set : item -> bool -> unit =
  "ml_elm_object_item_disabled_set"

external item_text_get : item -> string = "ml_elm_object_item_text_get"

external item_content_set : item -> Evas.obj -> unit =
  "ml_elm_object_item_content_set"

external item_widget_get : item -> Evas.obj = "ml_elm_object_item_widget_get"

