module AF = Autofun.Elm_button.F(struct
  type evas_object = Evas.obj
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_button_add"

let addx = Elm_object.create_addx add

