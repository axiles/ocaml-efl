module AF = Autofun.Elm_video.F (struct
  type evas_object = Evas.obj
end)
include AF

let player_add = Elm.player_add

external add : Evas.obj -> Evas.obj = "ml_elm_video_add"

let addx = Elm_object.create_addx add

