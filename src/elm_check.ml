module AF = Autofun.Elm_check.F (struct type evas_object = Evas.obj end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_check_add"

let addx = Elm_object.create_addx add

(*external state_set : Evas.obj -> bool -> unit = "ml_elm_check_state_set"

external state_get : Evas.obj -> bool = "ml_elm_check_state_get"*)

