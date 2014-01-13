(** elm_gesture_layer_* *)

val cb_set :
  Evas.obj -> Elm.gesture_type -> Elm.gesture_state -> Elm.gesture_event_cb ->
    unit

val hold_events_get : Evas.obj -> bool

val hold_events_set : Evas.obj -> bool -> unit

val zoom_step_set : Evas.obj -> float -> unit

val zoom_step_get : Evas.obj -> float

val rotate_step_set : Evas.obj -> float -> unit

val rotate_step_get : Evas.obj -> float

