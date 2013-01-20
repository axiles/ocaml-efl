type orient = [
  | `top
  | `center
  | `bottom
  | `left
  | `right
  | `top_left
  | `top_right
  | `bottom_left
  | `bottom_right
  | `last]

external add : Evas.obj -> Evas.obj = "ml_elm_notify_add"

external orient_set : Evas.obj -> orient -> unit = "ml_elm_notify_orient_set"

