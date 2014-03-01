(** File Selector *)

type mode = [`list | `grid | `last]

type sort = [
  | `filename_asc
  | `filename_desc
  | `type_asc
  | `type_desc
  | `size_asc
  | `size_desc
  | `modified_asc
  | `modified_desc
  | `last
]

type filter_func = string -> bool -> bool

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

val mime_types_filter_append :
  Evas.obj -> string -> ?filter_name:string -> unit -> bool

val custom_filter_append :
  Evas.obj -> filter_func -> ?filter_name:string -> unit -> bool

val filters_clear : Evas.obj -> unit

val hidden_visible_set : Evas.obj -> bool -> unit

val hidden_visible_get : Evas.obj -> bool

val thumbnail_size_set : Evas.obj -> int -> int -> unit

val thumbnail_size_get : Evas.obj -> int * int

val sort_method_get : Evas.obj -> sort

val sort_method_set : Evas.obj -> sort -> unit

val mode_set : Evas.obj -> mode -> unit

val mode_get : Evas.obj -> mode

val multi_select_set : Evas.obj -> bool -> unit

val multi_select_get : Evas.obj -> bool

val selected_paths_get : Evas.obj -> string list

