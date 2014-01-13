external cb_set :
  Evas.obj -> Elm.gesture_type -> Elm.gesture_state -> Elm.gesture_event_cb ->
    unit =
     "ml_elm_gesture_layer_cb_set"

external hold_events_get : Evas.obj -> bool =
  "ml_elm_gesture_layer_hold_events_get"

external hold_events_set : Evas.obj -> bool -> unit =
  "ml_elm_gesture_layer_hold_events_set"

