type item_class = {
  func_get : Evas.obj -> Evas.obj option;
  func_del : Evas.obj -> unit
}

val add : Evas.obj -> Evas.obj

val item_add : Evas.obj -> item_class -> Elm_object.item

val item_show : Elm_object.item -> unit

