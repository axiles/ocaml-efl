include Henums.Elm_hover

module AF = Autofun.Elm_hover.F (struct
  type evas_object = Evas.obj
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_hover_add"

let addx = Elm_object.create_addx add

external target_get : Evas.obj -> Evas.obj = "ml_elm_hover_target_get"

external parent_get : Evas.obj -> Evas.obj = "ml_elm_hover_parent_get"

external best_content_location_get : Evas.obj -> axis -> string option =
  "ml_elm_hover_best_content_location_get"

