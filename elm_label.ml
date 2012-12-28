external add : Evas.obj -> Evas.obj = "ml_elm_label_add"

external line_wrap_set : Evas.obj -> Elm.wrap_type -> unit =
  "ml_elm_label_line_wrap_set"

external line_wrap_get : Evas.obj -> Elm.wrap_type =
  "ml_elm_label_line_wrap_get"

external wrap_width_set : Evas.obj -> int -> unit =
  "ml_elm_label_wrap_width_set"

external wrap_width_get : Evas.obj -> int =
  "ml_elm_label_wrap_width_get"

external ellipsis_set : Evas.obj -> bool -> unit =
  "ml_elm_ellipsis_set"

external ellipsis_get : Evas.obj -> bool =
  "ml_elm_ellipsis_get"

