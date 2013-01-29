type mode = [`list | `grid | `last]

val add : Evas.obj -> Evas.obj

val is_save_set : Evas.obj -> bool -> unit

val is_save_get : Evas.obj -> bool

val folder_only_set : Evas.obj -> bool -> unit

val folder_only_get : Evas.obj -> bool

val buttons_ok_cancel_set : Evas.obj -> bool -> unit

val buttons_ok_cancel_get : Evas.obj -> bool

val expandable_set : Evas.obj -> bool -> unit

val expandable_get : Evas.obj  -> bool

val path_set : Evas.obj -> string -> unit

val path_get : Evas.obj -> string

val selected_set : Evas.obj -> string -> bool

val selected_get : Evas.obj -> string

