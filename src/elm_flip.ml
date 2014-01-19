(** elm_flip_* *)

external add : Evas.obj -> Evas.obj = "ml_elm_flip_add"

external front_visible_get : Evas.obj -> bool = "ml_elm_flip_front_visible_get"

external perspective_set : Evas.obj -> int -> int -> int -> unit =
  "ml_elm_flip_perspective_set"

