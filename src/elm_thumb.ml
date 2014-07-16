include Henums.Elm_thumb

external add : Evas.obj -> Evas.obj = "ml_elm_thumb_add"

let addx = Elm_object.create_addx add

external reload : Evas.obj -> unit = "ml_elm_thumb_reload"

external file_set : Evas.obj -> string -> string -> unit =
  "ml_elm_thumb_file_set"

external file_get : Evas.obj -> string * string = "ml_elm_thumb_file_get"

external path_get : Evas.obj -> string * string = "ml_elm_thumb_path_get"

external aspect_set : Evas.obj -> Ethumb.thumb_aspect -> unit =
  "ml_elm_thumb_aspect_set"

external aspect_get : Evas.obj -> Ethumb.thumb_aspect =
  "ml_elm_thumb_aspect_get"

external fdo_size_set : Evas.obj -> Ethumb.thumb_fdo_size -> unit =
  "ml_elm_thumb_fdo_size_set"

external fdo_size_get : Evas.obj -> Ethumb.thumb_fdo_size =
  "ml_elm_thumb_fdo_size_get"

external format_set : Evas.obj -> Ethumb.thumb_format -> unit =
  "ml_elm_thumb_format_set"

external format_get : Evas.obj -> Ethumb.thumb_format =
  "ml_elm_thumb_format_get"

external orientation_set : Evas.obj -> Ethumb.thumb_orientation -> unit =
  "ml_elm_thumb_orientation_set"

external orientation_get : Evas.obj -> Ethumb.thumb_orientation =
  "ml_elm_thumb_orientation_get"

external size_set : Evas.obj -> int -> int -> unit = "ml_elm_thumb_size_set"

external size_get : Evas.obj -> int * int = "ml_elm_thumb_size_get"

external crop_align_set : Evas.obj -> float -> float -> unit =
  "ml_elm_thumb_crop_align_set"

external crop_align_get : Evas.obj -> float * float =
  "ml_elm_thumb_crop_align_get"

external compress_set : Evas.obj -> int -> unit = "ml_elm_thumb_compress_set"

external compress_get : Evas.obj -> int = "ml_elm_thumb_compress_get"

external quality_set : Evas.obj -> int -> unit = "ml_elm_thumb_quality_set"

external quality_get : Evas.obj -> int = "ml_elm_thumb_quality_get"

external animate_set : Evas.obj -> animation_setting -> unit =
  "ml_elm_thumb_animate_set"

external animate_get : Evas.obj -> animation_setting =
  "ml_elm_thumb_animate_get"

external ethumb_client_connected_get : unit -> bool =
  "ml_elm_thumb_ethumb_client_connected_get"

external editable_set : Evas.obj -> bool -> unit = "ml_elm_thumb_editable_set"

external editable_get : Evas.obj -> bool = "ml_elm_thumb_editable_get"

