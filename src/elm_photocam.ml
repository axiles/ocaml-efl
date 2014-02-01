external add : Evas.obj -> Evas.obj = "ml_elm_photocam_add"

external file_set : Evas.obj -> string -> Evas.load_error =
  "ml_elm_photocam_file_set"

external file_get : Evas.obj -> string = "ml_elm_photocam_file_get"

external zoom_set : Evas.obj -> float -> unit = "ml_elm_photocam_zoom_set"

external zoom_get : Evas.obj -> float = "ml_elm_photocam_zoom_get"

