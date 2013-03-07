type item_class = Elm_gen.item_class = {
  item_style : string;
  func_text_get : Evas.obj -> string -> string;
  func_content_get : Evas.obj -> string -> Evas.obj option;
  func_state_get : Evas.obj -> string -> bool;
  func_del : Evas.obj -> unit;
}

type item_type = [`none | `tree | `group]

external add : Evas.obj -> Evas.obj = "ml_elm_genlist_add"

external clear : Evas.obj -> unit = "ml_elm_genlist_clear"

external multi_select_set : Evas.obj -> bool -> unit =
  "ml_elm_genlist_multi_select_set"

external multi_select_get : Evas.obj -> bool = "ml_elm_genlist_multi_select_get"

external mode_set : Evas.obj -> Elm_list.mode -> unit =
  "ml_elm_genlist_mode_set"

external mode_get : Evas.obj -> Elm_list.mode = "ml_elm_genlist_mode_get"

external item_append :
  Evas.obj -> item_class -> Elm_object.item option -> item_type ->
    Evas.smart_cb -> Elm_object.item =
  "ml_elm_genlist_item_append"

external item_prepend :
  Evas.obj -> item_class -> Elm_object.item option -> item_type ->
    Evas.smart_cb -> Elm_object.item =
  "ml_elm_genlist_item_prepend"

external item_insert_before :
  Evas.obj -> item_class -> Elm_object.item option -> Elm_object.item ->
    item_type -> Evas.smart_cb -> Elm_object.item =
  "ml_elm_genlist_item_insert_before_byte"
  "ml_elm_genlist_item_insert_before_native"

