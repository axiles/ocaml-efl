external add : Evas.obj -> Evas.obj = "ml_elm_icon_add"

external standard_set_with_bool : Evas.obj -> string -> bool =
  "ml_elm_icon_standard_set_with_bool"

let standard_set i s =
  if not (standard_set_with_bool i s) then failwith "elm_icon_standard_set"

