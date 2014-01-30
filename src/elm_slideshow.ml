type item_class = {
  func_get : Evas.obj -> Evas.obj option;
  func_del : Evas.obj -> unit
}

external add : Evas.obj -> Evas.obj = "ml_elm_slideshow_add"

