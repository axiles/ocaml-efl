external add : Evas.obj -> Evas.obj = "ml_elm_toolbar_add"

external icon_size_set : Evas.obj -> int -> unit =
  "ml_elm_toolbar_icon_size_set"

external icon_size_get : Evas.obj -> int = "ml_elm_toolbar_icon_size_get"

external icon_order_lookup_set : Evas.obj -> Elm_icon.lookup_order -> unit =
  "ml_elm_toolbar_icon_order_lookup_set"

external icon_order_lookup_get : Evas.obj -> Elm_icon.lookup_order =
  "ml_elm_toolbar_icon_order_lookup_get"

