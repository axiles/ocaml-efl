
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

(** {2 Elementary Engine *)

val engine_get : unit -> string

val engine_set : string -> unit

val preferred_engine_get : unit -> string

val preferred_engine_set : string -> unit

val access_get : unit -> bool

val access_set : bool -> unit

val mirrored_get : unit -> bool

val mirrored_set : bool -> unit

(** {2 Elementary fonts} *)

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

