module HE = Henums.Elm_icon

type ty = HE.ty

type lookup_order = HE.lookup_order

external add : Evas.obj -> Evas.obj = "ml_elm_icon_add"

let addx = Elm_object.create_addx add

external thumb_set : Evas.obj -> string -> string -> ?g:string -> unit -> unit =
  "ml_elm_icon_thumb_set"

external standard_set : Evas.obj -> string -> bool =
  "ml_elm_icon_standard_set"

external standard_get : Evas.obj -> string option =
  "ml_elm_icon_standard_get"

external order_lookup_set : Evas.obj -> lookup_order -> unit =
  "ml_elm_icon_order_lookup_set"

external order_lookup_get : Evas.obj -> lookup_order =
  "ml_elm_icon_order_lookup_get"

