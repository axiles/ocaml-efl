(** Thumbnail *)

type animation_setting = [`start | `loop | `stop | `last]

val add : Evas.obj -> Evas.obj

val reload : Evas.obj -> unit

val file_set : Evas.obj -> string -> string -> unit

val file_get : Evas.obj -> string * string

val path_get : Evas.obj -> string * string

val aspect_set : Evas.obj -> Ethumb.thumb_aspect -> unit

val aspect_get : Evas.obj -> Ethumb.thumb_aspect

val fdo_size_set : Evas.obj -> Ethumb.thumb_fdo_size -> unit

val fdo_size_get : Evas.obj -> Ethumb.thumb_fdo_size

val format_set : Evas.obj -> Ethumb.thumb_format -> unit

val format_get : Evas.obj -> Ethumb.thumb_format

val orientation_set : Evas.obj -> Ethumb.thumb_orientation -> unit

val orientation_get : Evas.obj -> Ethumb.thumb_orientation

val size_set : Evas.obj -> int -> int -> unit

val size_get : Evas.obj -> int * int

val crop_align_set : Evas.obj -> float -> float -> unit

val crop_align_get : Evas.obj -> float * float

val compress_set : Evas.obj -> int -> unit

val compress_get : Evas.obj -> int

val quality_set : Evas.obj -> int -> unit

val quality_get : Evas.obj -> int

val animate_set : Evas.obj -> animation_setting -> unit

val animate_get : Evas.obj -> animation_setting

val ethumb_client_connected_get : unit -> bool

val editable_set : Evas.obj -> bool -> unit

val editable_get : Evas.obj -> bool

