include Henums.Elm_list

module AF = Autofun.Elm_list.F (struct
  type evas_object = Evas.obj
  type elm_object_item = Elm_object.item
  type elm_object_select_mode = Elm_object.select_mode
  type elm_list_mode = mode
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_list_add"

let addx = Elm_object.create_addx add

external item_append :
  Evas.obj -> ?label:string -> ?icon:Evas.obj -> ?iend:Evas.obj ->
    ?func:Evas.smart_cb -> unit -> Elm_object.item =
  "ml_elm_list_item_append_byte"
  "ml_elm_list_item_append_native"

external item_prepend :
  Evas.obj -> ?label:string -> ?icon:Evas.obj -> ?iend:Evas.obj ->
    ?func:Evas.smart_cb -> unit -> Elm_object.item =
  "ml_elm_list_item_prepend_byte"
  "ml_elm_list_item_prepend_native"

external item_insert_before :
  Evas.obj -> Elm_object.item -> ?label:string -> ?icon:Evas.obj ->
    ?iend:Evas.obj -> ?func:Evas.smart_cb -> unit -> Elm_object.item =
  "ml_elm_list_item_insert_before_byte"
  "ml_elm_list_item_insert_before_native"

external item_insert_after :
  Evas.obj -> Elm_object.item -> ?label:string -> ?icon:Evas.obj ->
    ?iend:Evas.obj -> ?func:Evas.smart_cb -> unit -> Elm_object.item =
  "ml_elm_list_item_insert_after_byte"
  "ml_elm_list_item_insert_after_native"

external items_get : Evas.obj -> Elm_object.item list = "ml_elm_list_items_get"

external selected_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_list_selected_item_get"

external selected_items_get : Evas.obj -> Elm_object.item list =
  "ml_elm_list_selected_items_get"

external item_prev : Elm_object.item -> Elm_object.item option =
  "ml_elm_list_item_prev"

external item_next : Elm_object.item -> Elm_object.item option =
  "ml_elm_list_item_next"

external first_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_list_first_item_get"

external last_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_list_last_item_get"

