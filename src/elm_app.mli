(** App *)

val info_set : string -> ?checkfile:string -> unit -> unit

val name_set : string -> unit

val desktop_entry_set : string -> unit

val compile_bin_dir_set : string -> unit

val compile_lib_dir_set : string -> unit

val compile_data_dir_set : string -> unit

val compile_locale_set : string -> unit

val name_get : unit -> string

val desktop_entry_get : unit -> string

val prefix_dir_get : unit -> string

val bin_dir_get : unit -> string

val lib_dir_get : unit -> string

val data_dir_get : unit -> string

val locale_dir_get : unit -> string

val base_scale_set : float -> unit

val base_scale_get : unit -> float

