(** Elementary Configuration *)

(** {2 Cache} *)

val cache_flush_interval_get : unit -> int

val cache_flush_interval_set : int -> unit

val cache_flush_enabled_get : unit -> bool

val cache_flush_enabled_set : bool -> unit

val cache_font_cache_size_get : unit -> int

val cache_font_cache_size_set : int -> unit

val cache_image_cache_size_get : unit -> int

val cache_image_cache_size_set : int -> unit

val cache_edje_file_cache_size_get : unit -> int

val cache_edje_file_cache_size_set : int -> unit

val cache_edje_collection_cache_size_get : unit -> int

val cache_edje_collection_cache_size_set : int -> unit

(** {2 Cursors} *)

val cursor_engine_only_get : unit -> bool

val cursor_engine_only_set : bool -> unit

(** {2 Elementary Config} *)

val save : unit -> bool

val reload : unit -> unit

val all_flush : unit -> unit

(** {2 Elementary Engine} *)

val engine_get : unit -> string

val engine_set : string -> unit

val preferred_engine_get : unit -> string

val preferred_engine_set : string -> unit

val accel_preference_get : unit -> string

val accel_preference_set : string -> unit

val access_get : unit -> bool

val access_set : bool -> unit

val selection_unfocused_clear_get : unit -> bool

val selection_unfocused_clear_set : bool -> unit

val mirrored_get : unit -> bool

val mirrored_set : bool -> unit

val clouseau_enabled_get : unit -> bool

val clouseau_enabled_set : bool -> unit

val indicator_service_get : int -> string

val glayer_long_tap_start_timeout_get : unit -> float

val glayer_long_tap_start_timeout_set : float -> unit

val glayer_double_tap_timeout_get : unit -> float

val glayer_double_tap_timeout_set : float -> unit

val atspi_mode_get : unit -> bool

val atspi_mode_set : bool -> unit

(** {2 Elementary Fonts} *)

type text_class = {
  name : string;
  desc : string;
}

val text_classes_list_get : unit -> text_class list

val font_overlay_list_get : unit -> Elm_font.overlay list

val font_overlay_set : string -> string -> int -> unit

val font_overlay_unset : string -> unit

val font_overlay_apply : unit -> unit

(** {2 Elementary Profile} *)

val profile_get : unit -> string

val profile_dir_get : string -> bool -> string

val profile_list_get : unit -> string list

val profile_set : string -> unit

(** {2 Fingers} *)

val finger_size_get : unit -> int

val finger_size_set : int -> unit

(** {2 Focus} *)

val focus_autoscroll_mode_get : unit -> Elm.focus_autoscroll_mode

val focus_autoscroll_mode_set : Elm.focus_autoscroll_mode -> unit

val focus_highlight_enabled_get : unit -> bool

val focus_highlight_enabled_set : bool -> unit

val focus_highlight_animate_get : unit -> bool

val focus_highlight_animate_set : bool -> unit

val focus_highlight_clip_disabled_get : unit -> bool

val focus_highlight_clip_disabled_set : bool -> unit

val focus_move_policy_get : unit -> Elm.focus_move_policy

val focus_move_policy_set : Elm.focus_move_policy -> unit

val item_select_on_focus_disabled_get : unit -> bool

val item_select_on_focus_disabled_set : bool -> unit

(** {2 Colors} *)

val color_classes_list_get : unit -> Elm.color_class list

val color_overlay_list_get : unit -> Elm.color_overlay list

(** {2 Password show last} *)

val password_show_last_get : unit -> bool

val password_show_last_set : bool -> unit

val password_show_last_timeout_get : unit -> float

val password_show_last_timeout_set : float -> unit

(** {2 Elementary Scrolling} *)

val scroll_bounce_enabled_get : unit -> bool

val scroll_bounce_enabled_set : bool -> unit

val scroll_bounce_friction_get : unit -> float

val scroll_bounce_friction_set : float -> unit

val scroll_page_scroll_friction_get : unit -> float

val scroll_page_scroll_friction_set : float -> unit

val scroll_bring_in_scroll_friction_get : unit -> float

val scroll_bring_in_scroll_friction_set : float -> unit

val scroll_zoom_friction_get : unit -> float

val scroll_zoom_friction_set : float -> unit

val scroll_thumbscroll_enabled_get : unit -> bool

val scroll_thumbscroll_enabled_set : bool -> unit

val scroll_thumbscroll_threshold_get : unit -> int

val scroll_thumbscroll_threshold_set : int -> unit

val scroll_thumbscroll_momentum_threshold_get : unit -> float

val scroll_thumbscroll_momentum_threshold_set : float -> unit

val scroll_thumbscroll_friction_get : unit -> float

val scroll_thumbscroll_friction_set : float -> unit

val scroll_thumbscroll_border_friction_get : unit -> float

val scroll_thumbscroll_border_friction_set : float -> unit

val scroll_thumbscroll_sensitivity_friction_get : unit -> float

val scroll_thumbscroll_sensitivity_friction_set : float -> unit

(** {2 Widget Scaling} *)

val scale_get : unit -> float

val scale_set : float -> unit

