module AF = Autofun.Elm_gesture_layer.F (struct
  type evas_object = Evas.obj
end)
include AF

external cb_set :
  Evas.obj -> Elm.gesture_type -> Elm.gesture_state -> Elm.gesture_event_cb ->
    unit =
     "ml_elm_gesture_layer_cb_set"

external tap_longpress_cb_add :
  Evas.obj -> Elm.gesture_state -> Elm.gesture_event_cb -> unit =
     "ml_elm_gesture_layer_tap_longpress_cb_add"

external add : Evas.obj -> Evas.obj = "ml_elm_gesture_layer_add"

let addx = Elm_object.create_addx add

