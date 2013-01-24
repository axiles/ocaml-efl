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

external parent_set : Evas.obj -> Evas.obj -> unit = "ml_elm_notify_parent_set"

external parent_get : Evas.obj -> Evas.obj = "ml_elm_notify_parent_get"

external orient_set : Evas.obj -> orient -> unit = "ml_elm_notify_orient_set"

external orient_get : Evas.obj -> orient = "ml_elm_notify_orient_get"

external timeout_set : Evas.obj -> float -> unit = "ml_elm_notify_timeout_set"

external timeout_get : Evas.obj -> float = "ml_elm_notify_timeout_get"

external allow_events_set : Evas.obj -> bool -> unit =
  "ml_elm_notify_allow_events_set"

