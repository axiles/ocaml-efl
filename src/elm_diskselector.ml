module AF = Autofun.Elm_diskselector.F (struct
  type evas_object = Evas.obj
  type elm_object_item = Elm_object.item
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_diskselector_add"

let addx = Elm_object.create_addx add

external items_get : Evas.obj -> Elm_object.item list =
  "ml_elm_diskselector_items_get"

external item_append :
  Evas.obj -> ?label:string -> ?icon:Evas.obj -> ?func:Evas.smart_cb -> unit ->
      Elm_object.item =
      "ml_elm_diskselector_item_append"

external selected_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_diskselector_selected_item_get"

external first_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_diskselector_first_item_get"

external last_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_diskselector_last_item_get"

external item_prev_get : Elm_object.item -> Elm_object.item option =
  "ml_elm_diskselector_item_prev_get"

external item_next_get : Elm_object.item -> Elm_object.item option =
  "ml_elm_diskselector_item_next_get"

