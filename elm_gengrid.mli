type item_class = {
  item_style : string;
  func_text_get : Evas.obj -> string -> string;
  func_content_get : Evas.obj -> string -> Evas.obj option;
  func_state_get : Evas.obj -> string -> bool;
  func_content_del : Evas.obj -> unit;
}

val add : Evas.obj -> Evas.obj

val item_append : Evas.obj -> item_class -> Evas.smart_cb -> Elm_object.item

val item_size_set : Evas.obj -> int -> int -> unit

