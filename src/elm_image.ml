type orient = [
  | `orient_none
  | `rotate_90
  | `rotate_180
  | `rotate_270
  | `flip_horizontal
  | `flip_vertical
  | `flip_transpose
  | `flip_transverse]

external add : Evas.obj -> Evas.obj = "ml_elm_image_add"

let addx = Elm_object.create_addx add

external file_set : Evas.obj -> string -> ?g:string -> unit -> bool =
  "ml_elm_image_file_set"

external file_get : Evas.obj -> string * string option = "ml_elm_image_file_get"

external smooth_set : Evas.obj -> bool -> unit = "ml_elm_image_smooth_set"

external smooth_get : Evas.obj -> bool = "ml_elm_image_smooth_get"

external object_size_get : Evas.obj -> int * int =
  "ml_elm_image_object_size_get"

external no_scale_set : Evas.obj -> bool -> unit = "ml_elm_image_no_scale_set"

external no_scale_get : Evas.obj -> bool = "ml_elm_image_no_scale_get"

external resizable_set : Evas.obj -> bool -> bool -> unit =
  "ml_elm_image_resizable_set"

external resizable_get : Evas.obj -> bool * bool = "ml_elm_image_resizable_get"

external fill_outside_set : Evas.obj -> bool -> unit =
  "ml_elm_image_fill_outside_set"

external fill_outside_get : Evas.obj -> bool = "ml_elm_image_fill_outside_get"

external preload_disabled_set : Evas.obj -> bool -> unit =
  "ml_elm_image_preload_disabled_set"

external prescale_set : Evas.obj -> int -> unit = "ml_elm_image_prescale_set"

external prescale_get : Evas.obj -> int = "ml_elm_image_prescale_get"

external orient_set : Evas.obj -> orient -> unit = "ml_elm_image_orient_set"

external orient_get : Evas.obj -> orient = "ml_elm_image_orient_get"

external editable_set : Evas.obj -> bool -> unit = "ml_elm_image_editable_set"

external editable_get : Evas.obj -> bool = "ml_elm_image_editable_get"

external object_get : Evas.obj -> Evas.obj option = "ml_elm_image_object_get"

external aspect_fixed_set : Evas.obj -> bool -> unit =
  "ml_elm_image_aspect_fixed_set"

external aspect_fixed_get : Evas.obj -> bool = "ml_elm_image_aspect_fixed_get"

external animated_available_get : Evas.obj -> bool =
  "ml_elm_image_animated_available_get"

external animated_set : Evas.obj -> bool -> unit = "ml_elm_image_animated_set"

external animated_get : Evas.obj -> bool = "ml_elm_image_animated_get"

external animated_play_set : Evas.obj -> bool -> unit =
  "ml_elm_image_animated_play_set"

external animated_play_get : Evas.obj -> bool = "ml_elm_image_animated_play_get"

