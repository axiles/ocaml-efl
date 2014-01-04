(* Cache *)

external cache_flush_interval_get : unit -> int =
  "ml_elm_config_cache_flush_interval_get"

external cache_flush_interval_set : int -> unit =
  "ml_elm_config_cache_flush_interval_set"

external cache_flush_enabled_get : unit -> bool =
  "ml_elm_config_cache_flush_enabled_get"

external cache_flush_enabled_set : bool -> unit =
  "ml_elm_config_cache_flush_enabled_set"

external cache_font_cache_size_get : unit -> int =
  "ml_elm_config_cache_font_cache_size_get"

external cache_font_cache_size_set : int -> unit =
  "ml_elm_config_cache_font_cache_size_set"

external cache_image_cache_size_get : unit -> int =
  "ml_elm_config_cache_image_cache_size_get"

external cache_image_cache_size_set : int -> unit =
  "ml_elm_config_cache_image_cache_size_set"

external cache_edje_file_cache_size_get : unit -> int =
  "ml_elm_config_cache_edje_file_cache_size_get"

external cache_edje_file_cache_size_set : int -> unit =
  "ml_elm_config_cache_edje_file_cache_size_set"

external cache_edje_collection_cache_size_get : unit -> int =
  "ml_elm_config_cache_edje_collection_cache_size_get"

external cache_edje_collection_cache_size_set : int -> unit =
  "ml_elm_config_cache_edje_collection_cache_size_set"

(* Cursors *)

external cursor_engine_only_get : unit -> bool =
  "elm_config_cursor_engine_only_get"

external cursor_engine_only_set : bool -> unit =
  "elm_config_cursor_engine_only_set"

(* Elementary Config *)

external save : unit -> bool = "ml_elm_config_save"

external reload : unit -> unit = "ml_elm_config_reload"

external all_flush : unit -> unit = "ml_elm_config_all_flush"

(* Elementary Engine *)

external engine_get : unit -> string = "ml_elm_config_engine_get"

external engine_set : string -> unit = "ml_elm_config_engine_set"

external preferred_engine_get : unit -> string =
  "ml_elm_config_preferred_engine_get"

external preferred_engine_set : string -> unit =
  "ml_elm_config_preferred_engine_set"

external access_get : unit -> bool = "ml_elm_config_access_get"

external access_set : bool -> unit = "ml_elm_config_access_set"

external mirrored_get : unit -> bool = "ml_elm_config_mirrored_get"

external mirrored_set : bool -> unit = "ml_elm_config_mirrored_set"

(* Elementary fonts *)

type text_class = {
  name : string;
  desc : string;
}

external text_classes_list_get : unit -> text_class list =
  "ml_elm_config_text_classes_list_get"

external font_overlay_list_get : unit -> Elm_font.overlay list =
  "ml_elm_config_font_overlay_list_get"

external font_overlay_set : string -> string -> int -> unit =
  "ml_elm_config_font_overlay_set"

external font_overlay_unset : string -> unit =
  "ml_elm_config_font_overlay_unset"

external font_overlay_apply : unit -> unit = "ml_elm_config_font_overlay_apply"

(* Elementary Profile *)

external profile_get : unit -> string = "ml_elm_config_profile_get"

external profile_dir_get : string -> bool -> string =
  "ml_elm_config_profile_dir_get"

external profile_list_get : unit -> string list =
  "ml_elm_config_profile_list_get"

external profile_set : string -> unit = "ml_elm_config_profile_set"

(* Fingers *)

external finger_size_get : unit -> int = "ml_elm_config_finger_size_get"

external finger_size_set : int -> unit = "ml_elm_config_finger_size_set"

(* Focus *)

external focus_highlight_enabled_get : unit -> bool =
  "ml_elm_config_focus_highlight_enabled_get"

external focus_highlight_enabled_set : bool -> unit =
  "ml_elm_config_focus_highlight_enabled_set"

