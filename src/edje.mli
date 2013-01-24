type signal_cb = Evas.obj -> string -> string -> unit

val file_collection_list : string -> string list

val object_add : Evas.t -> Evas.obj

val object_file_set : Evas.obj -> string -> ?g:string -> unit -> bool

