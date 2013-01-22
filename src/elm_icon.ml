type ty = [`none | `file | `standard]

type lookup_order = [`fdo_theme | `theme_fdo | `fdo | `theme]

external add : Evas.obj -> Evas.obj = "ml_elm_icon_add"

external thumb_set : Evas.obj -> string -> string -> ?g:string -> unit -> unit =
  "ml_elm_icon_thumb_set"

external standard_set_with_bool : Evas.obj -> string -> bool =
  "ml_elm_icon_standard_set_with_bool"

let standard_set i s =
  if not (standard_set_with_bool i s) then failwith "elm_icon_standard_set"

external standard_get : Evas.obj -> string option =
  "ml_elm_icon_standard_get"

external order_lookup_set : Evas.obj -> lookup_order -> unit =
  "ml_elm_icon_order_lookup_set"

external order_lookup_get : Evas.obj -> lookup_order =
  "ml_elm_icon_order_lookup_get"

