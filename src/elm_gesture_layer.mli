(** elm_gesture_layer_* *)

val line_min_length_set : Evas.obj -> int -> unit

val line_min_length_get : Evas.obj -> int

val zoom_distance_tolerance_set : Evas.obj -> int -> unit

val zoom_distance_tolerance_get : Evas.obj -> int

val line_distance_tolerance_set : Evas.obj -> int -> unit

val line_distance_tolerance_get : Evas.obj -> int

val line_angular_tolerance_set : Evas.obj -> float -> unit

val line_angular_tolerance_get : Evas.obj -> float

val zoom_wheel_factor_set : Evas.obj -> float -> unit

val zoom_wheel_factor_get : Evas.obj -> float

val zoom_finger_factor_set : Evas.obj -> float -> unit

val zoom_finger_factor_get : Evas.obj -> float

val rotate_angular_tolerance_set : Evas.obj -> float -> unit

val rotate_angular_tolerance_get : Evas.obj -> float

val flick_time_limit_ms_set : Evas.obj -> int -> unit

val flick_time_limit_ms_get : Evas.obj -> int

val long_tap_start_timeout_set : Evas.obj -> float -> unit

val long_tap_start_timeout_get : Evas.obj -> float

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

