type zoom_mode = [`manual | `auto_fit | `auto_fill | `auto_fit_in | `last]

external add : Evas.obj -> Evas.obj = "ml_elm_photocam_add"

external file_set : Evas.obj -> string -> Evas.load_error =
  "ml_elm_photocam_file_set"

external file_get : Evas.obj -> string = "ml_elm_photocam_file_get"

external zoom_set : Evas.obj -> float -> unit = "ml_elm_photocam_zoom_set"

external zoom_get : Evas.obj -> float = "ml_elm_photocam_zoom_get"

external zoom_mode_set : Evas.obj -> zoom_mode -> unit =
  "ml_elm_photocam_zoom_mode_set"

external zoom_mode_get : Evas.obj -> zoom_mode = "ml_elm_photocam_zoom_mode_get"

external image_size_get : Evas.obj -> int * int =
  "ml_elm_photocam_image_size_get"

