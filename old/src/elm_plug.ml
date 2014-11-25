module AF = Autofun.Elm_plug.F (struct
  type evas_object = Evas.obj
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_plug_add"

let addx = Elm_object.create_addx add

external image_object_get : Evas.obj -> Evas.obj =
  "ml_elm_plug_image_object_get"

