include Henums.Elm_thumb

module AF = Autofun.Elm_thumb.F (struct
  type evas_object = Evas.obj
  type ethumb_thumb_aspect = Ethumb.thumb_aspect
  type ethumb_thumb_fdo_size = Ethumb.thumb_fdo_size
  type ethumb_thumb_format = Ethumb.thumb_format
  type ethumb_thumb_orientation = Ethumb.thumb_orientation
  type elm_thumb_animation_setting = animation_setting
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_thumb_add"

let addx = Elm_object.create_addx add

external file_get : Evas.obj -> string * string = "ml_elm_thumb_file_get"

external path_get : Evas.obj -> string * string = "ml_elm_thumb_path_get"

external size_get : Evas.obj -> int * int = "ml_elm_thumb_size_get"

external crop_align_get : Evas.obj -> float * float =
  "ml_elm_thumb_crop_align_get"

external compress_get : Evas.obj -> int = "ml_elm_thumb_compress_get"

external quality_get : Evas.obj -> int = "ml_elm_thumb_quality_get"

external animate_set : Evas.obj -> animation_setting -> unit =
  "ml_elm_thumb_animate_set"

