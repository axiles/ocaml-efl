type item_class = {
  item_style : string;
  func_text_get : Evas.obj -> string -> string;
  func_content_get : Evas.obj -> string -> Evas.obj option;
  func_state_get : Evas.obj -> string -> bool;
  func_del : Evas.obj -> unit;
}

external add : Evas.obj -> Evas.obj = "ml_elm_gengrid_add"

external item_append :
  Evas.obj -> item_class -> Evas.smart_cb -> Elm_object.item =
  "ml_elm_gengrid_item_append"

external item_size_set : Evas.obj -> int -> int -> unit =
  "ml_elm_gengrid_item_size_set"

