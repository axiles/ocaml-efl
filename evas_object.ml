external show : Evas.obj -> unit = "ml_evas_object_show"

external size_hint_weight_set : Evas.obj -> float -> float -> unit =
  "ml_evas_object_size_hint_weight_set"

external size_hint_align_set : Evas.obj -> float -> float -> unit =
  "ml_evas_object_size_hint_align_set"

external resize : Evas.obj -> int -> int -> unit =
  "ml_evas_object_resize"

external move : Evas.obj -> int -> int -> unit =
  "ml_evas_object_move"

external size_hint_align_get : Evas.obj -> float * float =
  "ml_evas_object_size_hint_align_get"

external hide : Evas.obj -> unit = "ml_evas_object_hide"

external color_set : Evas.obj -> int -> int -> int -> int -> unit =
  "ml_evas_object_color_set"

external del : Evas.obj -> unit = "ml_evas_object_del"

external evas_get : Evas.obj -> Evas.t = "ml_evas_object_evas_get"

