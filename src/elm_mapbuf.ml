module AF = Autofun.Elm_mapbuf.F (struct
  type evas_object = Evas.obj
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_mapbuf_add"

let addx = Elm_object.create_addx add

external point_color_get : Evas.obj -> int -> int * int * int * int =
  "ml_elm_mapbuf_point_color_get"

