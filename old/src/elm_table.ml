module AF = Autofun.Elm_table.F (struct
  type evas_object = Evas.obj
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_table_add"

let addx = Elm_object.create_addx add

external padding_get : Evas.obj -> int * int = "ml_elm_table_padding_get"

external pack_get : Evas.obj -> int * int * int * int = "ml_elm_table_pack_get"

external child_get : Evas.obj -> int -> int -> Evas.obj option =
  "ml_elm_table_child_get"

