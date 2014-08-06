include Henums.Elm_panel

module AF = Autofun.Elm_panel.F (struct
  type evas_object = Evas.obj
  type elm_panel_orient = orient
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_panel_add"

let addx = Elm_object.create_addx add

