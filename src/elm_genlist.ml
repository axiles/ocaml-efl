type item_class = Elm_gen.item_class = {
  item_style : string;
  func_text_get : Evas.obj -> string -> string;
  func_content_get : Evas.obj -> string -> Evas.obj option;
  func_state_get : Evas.obj -> string -> bool;
  func_del : Evas.obj -> unit;
}

type item_type = [`none | `tree | `group]

type item_scrollto_type = [`none | `_in | `top | `middle]

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

external item_insert_after :
  Evas.obj -> item_class -> Elm_object.item option -> Elm_object.item ->
    item_type -> Evas.smart_cb -> Elm_object.item =
  "ml_elm_genlist_item_insert_after_byte"
  "ml_elm_genlist_item_insert_after_native"

external selected_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_genlist_selected_item_get"

external selected_items_get : Evas.obj -> Elm_object.item list =
  "ml_elm_genlist_selected_items_get"

external realized_items_get : Evas.obj -> Elm_object.item list =
  "ml_elm_genlist_realized_items_get"

external first_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_genlist_first_item_get"

external last_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_genlist_last_item_get"

external item_next_get : Elm_object.item -> Elm_object.item option =
  "ml_elm_genlist_item_next_get"

external item_prev_get : Elm_object.item -> Elm_object.item option =
  "ml_elm_genlist_item_prev_get"

external item_selected_set : Elm_object.item -> bool -> unit =
  "ml_elm_genlist_item_selected_set"

external item_selected_get : Elm_object.item -> bool =
  "ml_elm_genlist_item_selected_get"

external item_show : Elm_object.item -> item_scrollto_type -> unit =
  "ml_elm_genlist_item_show"

external item_bring_in : Elm_object.item -> item_scrollto_type -> unit =
  "ml_elm_genlist_item_bring_in"

external item_update : Elm_object.item -> unit = "ml_elm_genlist_item_update"

external item_index_get : Elm_object.item -> int =
  "ml_elm_genlist_item_index_get"

external realized_items_update : Evas.obj -> unit =
  "ml_elm_genlist_realized_items_update"

external items_count : Evas.obj -> int = "ml_elm_genlist_items_count"

