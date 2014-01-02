type item_class = Elm_gen.item_class = {
  item_style : string;
  func_text_get : Evas.obj -> string -> string;
  func_content_get : Evas.obj -> string -> Evas.obj option;
  func_state_get : Evas.obj -> string -> bool;
  func_del : Evas.obj -> unit;
}

val add : Evas.obj -> Evas.obj

val clear : Evas.obj -> unit

val multi_select_set : Evas.obj -> bool -> unit

val multi_select_get : Evas.obj -> bool

val horizontal_set : Evas.obj -> bool -> unit

val horizontal_get : Evas.obj -> bool

val item_append : Evas.obj -> item_class -> Evas.smart_cb -> Elm_object.item

val item_size_set : Evas.obj -> int -> int -> unit

