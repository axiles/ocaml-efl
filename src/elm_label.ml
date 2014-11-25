module AF = Autofun.Elm_label.F (struct
  type evas_object = Evas.obj
  type elm_wrap_type = Elm.wrap_type
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_label_add"

let addx = Elm_object.create_addx add

