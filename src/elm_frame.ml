module AF = Autofun.Elm_frame.F (struct
  type evas_object = Evas.obj
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_frame_add"

let addx = Elm_object.create_addx add

