include Henums.Elm_icon

module AF = Autofun.Elm_icon.F (struct
  type evas_object = Evas.obj
  type elm_icon_lookup_order = lookup_order
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_icon_add"

let addx = Elm_object.create_addx add

external thumb_set : Evas.obj -> string -> string -> ?g:string -> unit -> unit =
  "ml_elm_icon_thumb_set"

external standard_get : Evas.obj -> string option =
  "ml_elm_icon_standard_get"

