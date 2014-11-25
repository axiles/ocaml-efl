module AF = Autofun.Elm_index.F (struct
  type evas_object = Evas.obj
  type elm_object_item = Elm_object.item
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_index_add"

let addx = Elm_object.create_addx add

external selected_item_get : Evas.obj -> int -> Elm_object.item option =
  "ml_elm_index_selected_item_get"

external item_append : Evas.obj -> string -> Evas.smart_cb -> Elm_object.item =
  "ml_elm_index_item_append"

external item_prepend : Evas.obj -> string -> Evas.smart_cb -> Elm_object.item =
  "ml_elm_index_item_prepend"

external item_insert_after :
  Evas.obj -> Elm_object.item -> string -> Evas.smart_cb -> Elm_object.item =
    "ml_elm_index_item_insert_after"

external item_insert_before :
  Evas.obj -> Elm_object.item -> string -> Evas.smart_cb -> Elm_object.item =
    "ml_elm_index_item_insert_before"

