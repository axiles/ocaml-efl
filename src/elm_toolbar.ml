external add : Evas.obj -> Evas.obj = "ml_elm_toolbar_add"

external icon_size_set : Evas.obj -> int -> unit =
  "ml_elm_toolbar_icon_size_set"

external icon_size_get : Evas.obj -> int = "ml_elm_toolbar_icon_size_get"

external icon_order_lookup_set : Evas.obj -> Elm_icon.lookup_order -> unit =
  "ml_elm_toolbar_icon_order_lookup_set"

external icon_order_lookup_get : Evas.obj -> Elm_icon.lookup_order =
  "ml_elm_toolbar_icon_order_lookup_get"

external item_append :
  Evas.obj -> ?icon:string -> ?label:string ->
    ?func:Evas.smart_cb -> unit -> Elm_object.item =
  "ml_elm_toolbar_item_append"

external item_prepend :
  Evas.obj -> ?icon:string -> ?label:string ->
    ?func:Evas.smart_cb -> unit -> Elm_object.item =
  "ml_elm_toolbar_item_prepend"

external item_insert_before :
  Evas.obj -> Elm_object.item -> ?icon:string -> ?label:string ->
    ?func:Evas.smart_cb -> unit -> Elm_object.item =
  "ml_elm_toolbar_item_insert_before_byte"
  "ml_elm_toolbar_item_insert_before_native"

external item_insert_after :
  Evas.obj -> Elm_object.item -> ?icon:string -> ?label:string ->
    ?func:Evas.smart_cb -> unit -> Elm_object.item =
  "ml_elm_toolbar_item_insert_after_byte"
  "ml_elm_toolbar_item_insert_after_native"

external first_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_toolbar_first_item_get"

external last_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_toolbar_last_item_get"

external item_next_get : Elm_object.item -> Elm_object.item option =
  "ml_elm_toolbar_item_next_get"

external item_prev_get : Elm_object.item -> Elm_object.item option =
  "ml_elm_toolbar_item_prev_get"

external item_priority_set : Elm_object.item -> int -> unit =
  "ml_elm_toolbar_item_priority_set"

external item_priority_get : Elm_object.item -> int =
  "ml_elm_toolbar_item_priority_get"

