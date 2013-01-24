type signal_cb = Evas.obj -> string -> string -> unit

external file_collection_list : string -> string list =
  "ml_edje_file_collection_list"

external object_add : Evas.t -> Evas.obj = "ml_edje_object_add"

external object_file_set : Evas.obj -> string -> ?g:string -> unit -> bool =
  "ml_edje_object_file_set"

