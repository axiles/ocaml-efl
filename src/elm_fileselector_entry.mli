(** File Selector Entry *)

val add : Evas.obj -> Evas.obj

val window_title_set : Evas.obj -> string -> unit

val window_title_get : Evas.obj -> string

val window_size_set : Evas.obj -> int -> int -> unit

val window_size_get : Evas.obj -> int * int

val path_set : Evas.obj -> string -> unit

val path_get : Evas.obj -> string

val expandable_set : Evas.obj -> bool -> unit

val expandable_get : Evas.obj -> bool

val folder_only_set : Evas.obj -> bool -> unit

val folder_only_get : Evas.obj -> bool

val is_save_set : Evas.obj -> bool -> unit

val is_save_get : Evas.obj -> bool

val inwin_mode_set : Evas.obj -> bool -> unit

val inwin_mode_get : Evas.obj -> bool

