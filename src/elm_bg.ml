external add : Evas.obj -> Evas.obj = "ml_elm_bg_add"

external file_set : Evas.obj -> string -> ?g:string -> unit -> unit =
  "ml_elm_bg_file_set"

external file_get : Evas.obj -> string * string option = "ml_elm_bg_file_get"

external color_set : Evas.obj -> int -> int -> int -> unit =
  "ml_elm_bg_color_set"

