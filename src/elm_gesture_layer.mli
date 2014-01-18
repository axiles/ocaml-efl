(** elm_gesture_layer_* *)

val line_min_length_set : Evas.obj -> int -> unit

val line_min_length_get : Evas.obj -> int

val zoom_distance_tolerance_set : Evas.obj -> int -> unit

val zoom_distance_tolerance_get : Evas.obj -> int

val cb_set :
  Evas.obj -> Elm.gesture_type -> Elm.gesture_state -> Elm.gesture_event_cb ->
    unit

val hold_events_get : Evas.obj -> bool

val hold_events_set : Evas.obj -> bool -> unit

val zoom_step_set : Evas.obj -> float -> unit

val zoom_step_get : Evas.obj -> float

val rotate_step_set : Evas.obj -> float -> unit

val rotate_step_get : Evas.obj -> float

val attach : Evas.obj -> Evas.obj -> bool

val add : Evas.obj -> Evas.obj

