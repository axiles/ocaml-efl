type item_class = {
  item_style : string;
  func_text_get : Evas.obj -> string -> string;
  func_content_get : Evas.obj -> string -> Evas.obj;
  func_content_del : Evas.obj -> unit;
}

val add : Evas.obj -> Evas.obj

