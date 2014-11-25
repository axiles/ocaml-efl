include Henums.Elm_flip

module AF = Autofun.Elm_flip.F (struct
  type evas_object = Evas.obj
  type elm_flip_mode = mode
  type elm_flip_interaction = interaction
  type elm_flip_direction = direction
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_flip_add"

let addx = Elm_object.create_addx add

