module AF = Autofun.Elm_grid.F (struct
  type evas_object = Evas.obj
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_grid_add"

let addx = Elm_object.create_addx add

external size_get : Evas.obj -> int * int = "ml_elm_grid_size_get"

external pack_get : Evas.obj -> int * int * int * int = "ml_elm_grid_pack_get"

external children_get : Evas.obj -> Evas.obj list = "ml_elm_grid_children_get"

