(** elm_notify_* Elm_Notify_* *)

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

val orient_get : Evas.obj -> orient

val timeout_set : Evas.obj -> float -> unit

val timeout_get : Evas.obj -> float

val allow_events_set : Evas.obj -> bool -> unit

val allow_events_get : Evas.obj -> bool

