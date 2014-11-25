module AF = Autofun.Elm_separator.F (struct
  type evas_object = Evas.obj
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_separator_add"

let addx = Elm_object.create_addx add

