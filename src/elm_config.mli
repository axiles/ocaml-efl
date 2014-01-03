
(** Cache *)

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

(** Cursors *)

val cursor_engine_only_get : unit -> bool

val cursor_engine_only_set : bool -> unit

