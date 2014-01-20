(** elm_flip_* *)

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

type interaction = [`none | `rotate | `cube | `page]

type direction = [
  | `up
  | `down
  | `left
  | `right]

val add : Evas.obj -> Evas.obj

val front_visible_get : Evas.obj -> bool

val perspective_set : Evas.obj -> int -> int -> int -> unit

val go : Evas.obj -> mode -> unit

val go_to : Evas.obj -> bool -> mode -> unit

val interaction_set : Evas.obj -> interaction -> unit

val interaction_get : Evas.obj -> interaction

