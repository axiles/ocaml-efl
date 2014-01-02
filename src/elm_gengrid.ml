type item_class = Elm_gen.item_class = {
  item_style : string;
  func_text_get : Evas.obj -> string -> string;
  func_content_get : Evas.obj -> string -> Evas.obj option;
  func_state_get : Evas.obj -> string -> bool;
  func_del : Evas.obj -> unit;
}

type item_scrollto_type = [`none | `_in | `top | `middle]

external add : Evas.obj -> Evas.obj = "ml_elm_gengrid_add"

external clear : Evas.obj -> unit = "ml_elm_gengrid_clear"

external multi_select_set : Evas.obj -> bool -> unit =
  "ml_elm_gengrid_multi_select_set"

external multi_select_get : Evas.obj -> bool = "ml_elm_gengrid_multi_select_get"

external horizontal_set : Evas.obj -> bool -> unit =
  "ml_elm_gengrid_horizontal_set"

external horizontal_get : Evas.obj -> bool = "ml_elm_gengrid_horizontal_get"

external item_append :
  Evas.obj -> item_class -> Evas.smart_cb -> Elm_object.item =
  "ml_elm_gengrid_item_append"

external item_prepend :
  Evas.obj -> item_class -> Evas.smart_cb -> Elm_object.item =
  "ml_elm_gengrid_item_prepend"

external item_insert_before :
  Evas.obj -> item_class -> Elm_object.item -> Evas.smart_cb ->
    Elm_object.item =
      "ml_elm_gengrid_item_insert_before"

external item_insert_after :
  Evas.obj -> item_class -> Elm_object.item -> Evas.smart_cb ->
    Elm_object.item =
      "ml_elm_gengrid_item_insert_after"

external selected_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_gengrid_selected_item_get"

external selected_items_get : Evas.obj -> Elm_object.item list =
  "ml_elm_gengrid_selected_items_get"

external realized_items_get : Evas.obj -> Elm_object.item list =
  "ml_elm_gengrid_realized_items_get"

external first_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_gengrid_first_item_get"

external last_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_gengrid_last_item_get"

external item_next_get : Elm_object.item -> Elm_object.item option =
  "ml_elm_gengrid_item_next_get"

external item_prev_get : Elm_object.item -> Elm_object.item option =
  "ml_elm_gengrid_item_prev_get"

external item_selected_set : Elm_object.item -> bool -> unit =
  "ml_elm_gengrid_item_selected_set"

external item_selected_get : Elm_object.item -> bool =
  "ml_elm_gengrid_item_selected_get"

external item_show : Elm_object.item -> item_scrollto_type -> unit =
  "ml_elm_gengrid_item_show"

external item_bring_in : Elm_object.item -> item_scrollto_type -> unit =
  "ml_elm_gengrid_item_bring_in"

external item_update : Elm_object.item -> unit = "ml_elm_gengrid_item_update"

external item_index_get : Elm_object.item -> int =
  "ml_elm_gengrid_item_index_get"

external item_size_set : Evas.obj -> int -> int -> unit =
  "ml_elm_gengrid_item_size_set"

