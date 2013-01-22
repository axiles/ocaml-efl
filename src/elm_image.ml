external add : Evas.obj -> Evas.obj = "ml_elm_image_add"

external file_set : Evas.obj -> string -> ?g:string -> unit -> bool =
  "ml_elm_image_file_set"

external file_get : Evas.obj -> string * string option = "ml_elm_image_file_get"

external smooth_set : Evas.obj -> bool -> unit = "ml_elm_image_smooth_set"

external no_scale_set : Evas.obj -> bool -> unit = "ml_elm_image_no_scale_set"

external resizable_set : Evas.obj -> bool -> bool -> unit =
  "ml_elm_image_resizable_set"

