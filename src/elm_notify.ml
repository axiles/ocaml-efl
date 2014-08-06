module AF = Autofun.Elm_notify.F (struct
  type evas_object = Evas.obj
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_notify_add"

let addx = Elm_object.create_addx add

(*external parent_set : Evas.obj -> Evas.obj -> unit = "ml_elm_notify_parent_set"

external parent_get : Evas.obj -> Evas.obj = "ml_elm_notify_parent_get"

external align_set : Evas.obj -> float -> float -> unit =
  "ml_elm_notify_align_set"
*)
external align_get : Evas.obj -> float * float = "ml_elm_notify_align_get"

(*external timeout_set : Evas.obj -> float -> unit = "ml_elm_notify_timeout_set"

external timeout_get : Evas.obj -> float = "ml_elm_notify_timeout_get"

external allow_events_set : Evas.obj -> bool -> unit =
  "ml_elm_notify_allow_events_set"

external allow_events_get : Evas.obj -> bool = "ml_elm_notify_allow_events_get"
*)
