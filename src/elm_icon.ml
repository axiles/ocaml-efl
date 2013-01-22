type ty = [`none | `file | `standard]

external add : Evas.obj -> Evas.obj = "ml_elm_icon_add"

external thumb_set : Evas.obj -> string -> string -> ?g:string -> unit -> unit =
  "ml_elm_icon_thumb_set"

external standard_set_with_bool : Evas.obj -> string -> bool =
  "ml_elm_icon_standard_set_with_bool"

let standard_set i s =
  if not (standard_set_with_bool i s) then failwith "elm_icon_standard_set"

external standard_get : Evas.obj -> string option =
  "ml_elm_icon_standard_get"

