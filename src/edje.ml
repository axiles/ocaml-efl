type signal_cb = Evas.obj -> string -> string -> unit

external file_collection_list : string -> string list =
  "ml_edje_file_collection_list"

