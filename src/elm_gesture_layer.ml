external line_min_length_set : Evas.obj -> int -> unit =
  "ml_elm_gesture_layer_line_min_length_set"

external line_min_length_get : Evas.obj -> int =
  "ml_elm_gesture_layer_line_min_length_get"

external zoom_distance_tolerance_set : Evas.obj -> int -> unit =
  "ml_elm_gesture_layer_zoom_distance_tolerance_set"

external zoom_distance_tolerance_get : Evas.obj -> int =
  "ml_elm_gesture_layer_zoom_distance_tolerance_get"

external line_distance_tolerance_set : Evas.obj -> int -> unit =
  "ml_elm_gesture_layer_line_distance_tolerance_set"

external line_distance_tolerance_get : Evas.obj -> int =
  "ml_elm_gesture_layer_line_distance_tolerance_get"

external line_angular_tolerance_set : Evas.obj -> float -> unit =
  "ml_elm_gesture_layer_line_angular_tolerance_set"

external line_angular_tolerance_get : Evas.obj -> float =
  "ml_elm_gesture_layer_line_angular_tolerance_get"

external zoom_wheel_factor_set : Evas.obj -> float -> unit =
  "ml_elm_gesture_layer_zoom_wheel_factor_set"

external zoom_wheel_factor_get : Evas.obj -> float =
  "ml_elm_gesture_layer_zoom_wheel_factor_get"

external zoom_finger_factor_set : Evas.obj -> float -> unit =
  "ml_elm_gesture_layer_zoom_finger_factor_set"

external zoom_finger_factor_get : Evas.obj -> float =
  "ml_elm_gesture_layer_zoom_finger_factor_get"

external cb_set :
  Evas.obj -> Elm.gesture_type -> Elm.gesture_state -> Elm.gesture_event_cb ->
    unit =
     "ml_elm_gesture_layer_cb_set"

external hold_events_get : Evas.obj -> bool =
  "ml_elm_gesture_layer_hold_events_get"

external hold_events_set : Evas.obj -> bool -> unit =
  "ml_elm_gesture_layer_hold_events_set"

external zoom_step_set : Evas.obj -> float -> unit =
  "ml_elm_gesture_layer_zoom_step_set"

external zoom_step_get : Evas.obj -> float =
  "ml_elm_gesture_layer_zoom_step_get"

external rotate_step_set : Evas.obj -> float -> unit =
  "ml_elm_gesture_layer_rotate_step_set"

external rotate_step_get : Evas.obj -> float =
  "ml_elm_gesture_layer_rotate_step_get"

external attach : Evas.obj -> Evas.obj -> bool = "ml_elm_gesture_layer_attach"

external add : Evas.obj -> Evas.obj = "ml_elm_gesture_layer_add"

