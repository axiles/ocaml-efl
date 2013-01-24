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

val add : Evas.obj -> Evas.obj

val parent_set : Evas.obj -> Evas.obj -> unit

val parent_get : Evas.obj -> Evas.obj

val orient_set : Evas.obj -> orient -> unit

val allow_events_set : Evas.obj -> bool -> unit

