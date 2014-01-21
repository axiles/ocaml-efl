(** elm_object_* Elm_Object_* *)

(** {2 Cursors} *)

val cursor_set : Evas.obj -> string -> unit

val cursor_get : Evas.obj -> string

val cursor_unset : Evas.obj -> unit

val cursor_style_set : Evas.obj -> string -> unit

val cursor_style_get : Evas.obj -> string

val cursor_theme_search_enabled_set : Evas.obj -> bool -> unit

val cursor_theme_search_enabled_get : Evas.obj -> bool

(** {2 Debug} *)

val tree_dump : Evas.obj -> unit

val tree_dot_dump : Evas.obj -> string -> unit

(** {2 Focus} *)

val focus_get : Evas.obj -> bool

val focus_set : Evas.obj -> bool -> unit

val focus_allow_set : Evas.obj -> bool -> unit

val focus_allow_get : Evas.obj -> bool

val focus_custom_chain_set : Evas.obj -> Evas.obj list -> unit

val focus_custom_chain_unset : Evas.obj -> unit

val focus_custom_chain_get : Evas.obj -> Evas.obj list

val focus_custom_chain_append : Evas.obj -> Evas.obj -> Evas.obj option -> unit

val focus_custom_chain_prepend : Evas.obj -> Evas.obj -> Evas.obj option -> unit

val focus_next : Evas.obj -> Elm.focus_direction -> unit

val focus_next_object_get : Evas.obj -> Elm.focus_direction -> Evas.obj option

val focus_next_object_set :
  Evas.obj -> Evas.obj option -> Elm.focus_direction -> unit

val focused_object_get : Evas.obj -> Evas.obj option

val tree_focus_allow_get : Evas.obj -> bool

val tree_focus_allow_set : Evas.obj -> bool -> unit

(** {2 General} *)

type item

type select_mode = [`default | `always | `none | `display_only]

type item_signal_cb = item -> string -> string -> unit

val item_of_ptr : Evas.ptr -> item

val domain_translatable_part_text_set :
  Evas.obj -> ?part:string -> ?domain:string -> ?text:string -> unit -> unit

val translatable_part_text_get : Evas.obj -> ?p:string -> unit -> string

val domain_part_text_translatable_set :
  Evas.obj -> ?part:string -> ?domain:string -> bool -> unit

val text_set : Evas.obj -> string -> unit

val part_text_set : Evas.obj -> ?p:string -> string -> unit

val text_get : Evas.obj -> string

val part_text_get : Evas.obj -> ?p:string -> unit -> string

val content_set : Evas.obj -> Evas.obj -> unit

val part_content_set : Evas.obj -> ?p:string -> Evas.obj -> unit 

val part_content_set_null : Evas.obj -> ?p:string -> unit -> unit

val part_content_get : Evas.obj -> ?p:string -> unit -> Evas.obj

val content_unset : Evas.obj -> Evas.obj

val part_content_unset : Evas.obj -> ?p:string -> unit -> Evas.obj

val access_info_set : Evas.obj -> string -> unit

val name_find : Evas.obj -> string -> int -> Evas.obj option

val signal_emit : Evas.obj -> string -> string -> unit

val signal_callback_add : Evas.obj -> string -> string -> Edje.signal_cb -> unit

val signal_callback_del : Evas.obj -> string -> string -> Edje.signal_cb -> unit

val event_callback_add : Evas.obj -> Elm.event_cb -> unit

val orientation_mode_disabled_set : Evas.obj -> bool -> unit

val orientation_mode_disabled_get : Evas.obj -> bool

val item_widget_get : item -> Evas.obj

val item_content_set : item -> Evas.obj -> unit

val item_part_content_set : item -> ?p:string -> Evas.obj -> unit

val item_part_content_get : item -> ?p:string -> unit -> Evas.obj

val item_part_content_unset : item -> ?p:string -> unit -> Evas.obj

val item_text_set : item -> string -> unit

val item_part_text_set : item -> ?p:string -> string -> unit

val item_text_get : item -> string

val item_part_text_get : item -> ?p:string -> unit -> string

val item_domain_translatable_part_text_set :
  item -> ?p:string -> ?d:string -> ?t:string -> unit -> unit

val item_translatable_part_text_get : item -> ?p:string -> unit -> string

val item_domain_part_text_translatable_set :
  item -> ?p:string -> ?d:string -> bool -> unit

val item_access_info_set : item -> string -> unit

val item_access_register : item -> Evas.obj

val item_access_unregister : item -> unit

val item_access_object_get : item -> Evas.obj

val item_access_order_set : item -> Evas.obj list -> unit

val item_access_order_get : item -> Evas.obj list

val item_access_order_unset : item -> unit

val item_signal_emit : item -> string -> string -> unit

val item_signal_callback_add :
  item -> string -> string -> item_signal_cb -> unit

val item_del : item -> unit

val item_tooltip_text_set : item -> string -> unit

type tooltip_item_content_cb = Evas.obj -> Evas.obj -> Evas.obj option

val item_tooltip_content_cb_set : item -> tooltip_item_content_cb -> unit

val item_tooltip_unset : item -> unit

val item_tooltip_style_set : item -> string -> unit

val item_tooltip_style_get : item -> string

val item_cursor_set : Evas.obj -> string -> unit

val item_cursor_unset : Evas.obj -> unit

val item_cursor_style_set : item -> string -> unit

val item_cursor_style_get : item -> string

val item_cursor_engine_only_set : item -> bool -> unit

val item_cursor_engine_only_get : item -> bool

val item_track : item -> Evas.obj

val item_untrack : item -> unit

val item_track_get : item -> int

(** {2 Scrollhints} *)

val scroll_hold_push : Evas.obj -> unit

val scroll_hold_pop : Evas.obj -> unit

val scroll_hold_get : Evas.obj -> int

val scroll_freeze_push : Evas.obj -> unit

val scroll_freeze_pop : Evas.obj -> unit

val scroll_freeze_get : Evas.obj -> int

val scroll_lock_x_set : Evas.obj -> bool -> unit

val scroll_lock_y_set : Evas.obj -> bool -> unit

val scroll_lock_x_get : Evas.obj -> bool

val scroll_lock_y_get : Evas.obj -> bool

(** {2 Mirroring} *)

val mirrored_get : Evas.obj -> bool

val mirrored_set : Evas.obj -> bool -> unit

val mirrored_automatic_get : Evas.obj -> bool

val mirrored_automatic_set : Evas.obj -> bool -> unit

(** {2 Widget Scaling} *)

val scale_set : Evas.obj -> float -> unit

val scale_get : Evas.obj -> float

(** {2 Styles} *)

val style_set : Evas.obj -> string -> bool

val style_get : Evas.obj -> string

val disabled_set : Evas.obj -> bool -> unit

val disabled_get : Evas.obj -> bool

val item_disabled_set : item -> bool -> unit

val item_disabled_get : item -> bool

(** {2 Theme} *)

val theme_set : Evas.obj -> Elm.theme option -> unit

val theme_get : Evas.obj -> Elm.theme option

(** {2 Widget Tree Navigation} *)

val widget_check : Evas.obj -> bool

val parent_widget_get : Evas.obj -> Evas.obj option

val top_widget_get : Evas.obj -> Evas.obj option

val widget_type_get : Evas.obj -> string option

(** {2 Tooltips} *)

val tooltip_show : Evas.obj -> unit

val tooltip_hide : Evas.obj -> unit

