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

