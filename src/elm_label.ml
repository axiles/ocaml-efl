external add : Evas.obj -> Evas.obj = "ml_elm_label_add"

let addx = Elm_object.create_addx add

external line_wrap_set : Evas.obj -> Elm.wrap_type -> unit =
  "ml_elm_label_line_wrap_set"

external line_wrap_get : Evas.obj -> Elm.wrap_type =
  "ml_elm_label_line_wrap_get"

external wrap_width_set : Evas.obj -> int -> unit =
  "ml_elm_label_wrap_width_set"

external wrap_width_get : Evas.obj -> int =
  "ml_elm_label_wrap_width_get"

external ellipsis_set : Evas.obj -> bool -> unit =
  "ml_elm_label_ellipsis_set"

external ellipsis_get : Evas.obj -> bool =
  "ml_elm_label_ellipsis_get"

external slide_mode_set : Evas.obj -> bool -> unit =
  "ml_elm_label_slide_mode_set"

external slide_mode_get : Evas.obj -> bool =
  "ml_elm_label_slide_mode_get"

external slide_duration_set : Evas.obj -> float -> unit =
  "ml_elm_label_slide_duration_set"

external slide_duration_get : Evas.obj -> float =
  "ml_elm_label_slide_duration_get"

external slide_speed_set : Evas.obj -> float -> unit =
  "ml_elm_label_slide_speed_set"

external slide_speed_get : Evas.obj -> float = "ml_elm_label_slide_speed_get"

external slide_go : Evas.obj -> unit = "ml_elm_label_slide_go"

