(** elm_thumb_* *)

type animation_setting = [`start | `loop | `stop | `last]

val add : Evas.obj -> Evas.obj

val reload : Evas.obj -> unit

val file_set : Evas.obj -> string -> string -> unit

val file_get : Evas.obj -> string * string

val path_get : Evas.obj -> string * string

val aspect_set : Evas.obj -> Ethumb.thumb_aspect -> unit

val aspect_get : Evas.obj -> Ethumb.thumb_aspect

val animate_set : Evas.obj -> animation_setting -> unit

val animate_get : Evas.obj -> animation_setting

val ethumb_client_connected_get : unit -> bool

val editable_set : Evas.obj -> bool -> unit

val editable_get : Evas.obj -> bool

