include Henums.Elm_bubble
module AF = Autofun.Elm_bubble.F (struct
  type evas_object = Evas.obj
  type elm_bubble_pos = pos
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_bubble_add"

let addx = Elm_object.create_addx add

