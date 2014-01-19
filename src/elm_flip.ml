type mode = [
  | `rotate_y_center_axis
  | `rotate_x_center_axis
  | `rotate_xz_center_axis
  | `rotate_yz_center_axis
  | `cube_left
  | `cube_right
  | `cube_up
  | `cube_down
  | `page_up
  | `page_down
  | `page_left
  | `page_right]

external add : Evas.obj -> Evas.obj = "ml_elm_flip_add"

external front_visible_get : Evas.obj -> bool = "ml_elm_flip_front_visible_get"

external perspective_set : Evas.obj -> int -> int -> int -> unit =
  "ml_elm_flip_perspective_set"

external go : Evas.obj -> mode -> unit = "ml_elm_flip_go"

external go_to : Evas.obj -> bool -> mode -> unit = "ml_elm_flip_go_to"

