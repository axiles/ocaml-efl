external add : Evas.obj -> Evas.obj = "ml_elm_menu_add"

external parent_set : Evas.obj -> Evas.obj -> unit = "ml_elm_menu_parent_set"

external parent_get : Evas.obj -> Evas.obj = "ml_elm_menu_parent_get"

external move : Evas.obj -> int -> int -> unit = "ml_elm_menu_move"

external close : Evas.obj -> unit = "ml_elm_menu_close"

external items_get : Evas.obj -> Elm_object.item list = "ml_elm_menu_items_get"

external item_object_get : Elm_object.item -> Evas.obj =
  "ml_elm_menu_item_object_get"

external item_add :
  Evas.obj -> ?parent:Elm_object.item -> ?icon:string -> ?label:string ->
    ?func:Evas.smart_cb -> unit -> Elm_object.item
  =
    "ml_elm_menu_item_add_byte"
    "ml_elm_menu_item_add_native"

external item_icon_name_set : Elm_object.item -> string -> unit =
  "ml_elm_menu_item_icon_name_set"

external item_icon_name_get : Elm_object.item -> string option =
  "ml_elm_menu_item_icon_name_get"

external item_selected_set : Elm_object.item -> bool -> unit =
  "ml_elm_menu_item_selected_set"

