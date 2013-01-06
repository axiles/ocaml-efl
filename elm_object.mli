val text_set : Evas.obj -> string -> unit

val style_set_with_bool : Evas.obj -> string -> bool

val style_set : Evas.obj -> string -> unit

val content_set : Evas.obj -> Evas.obj -> unit

val part_content_set : Evas.obj -> ?p:string -> Evas.obj -> unit 

val text_get : Evas.obj -> string

val part_content_get : Evas.obj -> ?p:string -> Evas.obj

val content_unset : Evas.obj -> Evas.obj

val part_text_set : Evas.obj -> ?p:string -> string -> unit

val part_text_get : Evas.obj -> ?p:string -> unit -> string

val part_content_unset : Evas.obj -> ?p:string -> unit -> Evas.obj

val signal_emit : Evas.obj -> string -> string -> unit

val signal_callback_add : Evas.obj -> string -> string -> Edje.signal_cb -> unit

val signal_callback_del : Evas.obj -> string -> string -> Edje.signal_cb -> unit

val disabled_set : Evas.obj -> bool -> unit

