type item_class = {
  item_style : string;
  func_text_get : Evas.obj -> string -> string;
  func_content_get : Evas.obj -> string -> Evas.obj;
  func_content_del : Evas.obj -> unit;
}

external add : Evas.obj -> Evas.obj = "ml_elm_gengrid_add"

