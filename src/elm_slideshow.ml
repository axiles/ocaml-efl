type item_class = {
  func_get : Evas.obj -> Evas.obj option;
  func_del : Evas.obj -> unit
}

external add : Evas.obj -> Evas.obj = "ml_elm_slideshow_add"

external item_add : Evas.obj -> item_class -> Elm_object.item =
  "ml_elm_slideshow_item_add"

external item_show : Elm_object.item -> unit = "ml_elm_slideshow_item_show"

