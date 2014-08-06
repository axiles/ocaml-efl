module AF = Autofun.Elm_radio.F (struct
  type evas_object = Evas.obj
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_radio_add"

let addx = Elm_object.create_addx add

external selected_object_get : Evas.obj -> Evas.obj =
  "ml_elm_radio_selected_object_get"

