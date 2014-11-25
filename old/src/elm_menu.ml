module AF = Autofun.Elm_menu.F (struct
  type evas_object = Evas.obj
  type elm_object_item = Elm_object.item
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_menu_add"

let addx = Elm_object.create_addx add

external items_get : Evas.obj -> Elm_object.item list = "ml_elm_menu_items_get"

external item_add :
  Evas.obj -> ?parent:Elm_object.item -> ?icon:string -> ?label:string ->
    ?func:Evas.smart_cb -> unit -> Elm_object.item
  =
    "ml_elm_menu_item_add_byte"
    "ml_elm_menu_item_add_native"

external item_icon_name_get : Elm_object.item -> string option =
  "ml_elm_menu_item_icon_name_get"

external item_separator_add : Evas.obj -> Elm_object.item -> Elm_object.item =
  "ml_elm_menu_item_separator_add"

external item_subitems_get : Elm_object.item -> Elm_object.item list =
  "ml_elm_menu_item_subitems_get"

external selected_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_menu_selected_item_get"

external last_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_menu_last_item_get"

external first_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_menu_first_item_get"

external item_next_get : Elm_object.item -> Elm_object.item option =
  "ml_elm_menu_item_next_get"

external item_prev_get : Elm_object.item -> Elm_object.item option =
  "ml_elm_menu_item_prev_get"

