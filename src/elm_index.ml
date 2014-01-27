external add : Evas.obj -> Evas.obj = "ml_elm_index_add"

external autohide_disabled_set : Evas.obj -> bool -> unit =
  "ml_elm_index_autohide_disabled_set"

external autohide_disabled_get : Evas.obj -> bool =
  "ml_elm_index_autohide_disabled_get"

external item_level_set : Evas.obj -> int -> unit =
  "ml_elm_index_item_level_set"

external item_level_get : Evas.obj -> int = "ml_elm_index_item_level_get"

external item_selected_set : Elm_object.item -> bool -> unit =
  "ml_elm_index_item_selected_set"

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

