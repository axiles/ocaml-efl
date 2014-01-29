external add : Evas.obj -> Evas.obj = "ml_elm_photo_add"

external file_set : Evas.obj -> string -> bool = "ml_elm_photo_file_set"

external file_set_none : Evas.obj -> bool = "ml_elm_photo_file_set_null"

external thumb_set : Evas.obj -> string -> ?g:string -> unit -> unit =
  "ml_elm_photo_thumb_set"

external thumb_set_none : Evas.obj -> ?g:string -> unit -> unit =
  "ml_elm_photo_thumb_set_null"

