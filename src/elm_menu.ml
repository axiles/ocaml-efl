external add : Evas.obj -> Evas.obj = "ml_elm_menu_add"

external parent_set : Evas.obj -> Evas.obj -> unit = "ml_elm_menu_parent_set"

external parent_get : Evas.obj -> Evas.obj = "ml_elm_menu_parent_get"

external move : Evas.obj -> int -> int -> unit = "ml_elm_menu_move"

external close : Evas.obj -> unit = "ml_elm_menu_close"

external items_get : Evas.obj -> Elm_object.item list = "ml_elm_menu_items_get"

external item_object_get : Elm_object.item -> Evas.obj =
  "ml_elm_menu_item_object_get"

