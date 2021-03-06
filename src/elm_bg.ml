include Henums.Elm_bg
module AF = Autofun.Elm_bg.F (struct
  type evas_object = Evas.obj
  type elm_bg_option = opt
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_bg_add"

let addx = Elm_object.create_addx add

external file_set : Evas.obj -> string -> ?g:string -> unit -> unit =
  "ml_elm_bg_file_set"

external file_get : Evas.obj -> string * string option = "ml_elm_bg_file_get"

external color_get : Evas.obj -> int * int * int = "ml_elm_bg_color_get"

