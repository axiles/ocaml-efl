type zoom_mode = [`manual | `auto_fit | `auto_fill | `auto_fit_in | `last]

type progress = {now : float; total : float}

type error = {status : int; open_error : bool}

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

external image_region_get : Evas.obj -> int * int * int * int =
  "ml_elm_photocam_image_region_get"

external image_region_show : Evas.obj -> int -> int -> int -> int -> unit =
  "ml_elm_photocam_image_region_show"

external image_region_bring_in : Evas.obj -> int -> int -> int -> int -> unit =
  "ml_elm_photocam_image_region_bring_in"

external paused_set : Evas.obj -> bool -> unit = "ml_elm_photocam_paused_set"

external paused_get : Evas.obj -> bool = "ml_elm_photocam_paused_get"

external internal_image_get : Evas.obj -> Evas.obj option =
  "ml_elm_photocam_internal_image_get"

external gesture_enabled_set : Evas.obj -> bool -> unit =
  "ml_elm_photocam_gesture_enabled_set"

external gesture_enabled_get : Evas.obj -> bool =
  "ml_elm_photocam_gesture_enabled_get"

external progress_of_ptr : Evas.ptr -> progress =
  "ml_Elm_Photocam_Progress_of_ptr"

external error_of_ptr : Evas.ptr -> error = "ml_Elm_Photocam_Error_of_ptr"


