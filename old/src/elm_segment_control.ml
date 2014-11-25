module AF = Autofun.Elm_segment_control.F (struct
  type evas_object = Evas.obj
  type elm_object_item = Elm_object.item
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_segment_control_add"

let addx = Elm_object.create_addx add

external item_add :
  Evas.obj -> ?icon:Evas.obj -> ?label:string -> unit -> Elm_object.item =
    "ml_elm_segment_control_item_add"

external item_insert_at :
  Evas.obj -> ?icon:Evas.obj -> ?label:string -> int -> Elm_object.item =
    "ml_elm_segment_control_item_insert_at"

external item_get : Evas.obj -> int -> Elm_object.item option =
  "ml_elm_segment_control_item_get"

external item_label_get : Evas.obj -> int -> string option =
  "ml_elm_segment_control_item_label_get"

external item_icon_get : Evas.obj -> int -> Evas.obj option =
  "ml_elm_segment_control_item_icon_get"

external item_selected_get : Evas.obj -> Elm_object.item option =
  "ml_elm_segment_control_item_selected_get"

