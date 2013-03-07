type item_class = Elm_gen.item_class = {
  item_style : string;
  func_text_get : Evas.obj -> string -> string;
  func_content_get : Evas.obj -> string -> Evas.obj option;
  func_state_get : Evas.obj -> string -> bool;
  func_del : Evas.obj -> unit;
}

external add : Evas.obj -> Evas.obj = "ml_elm_genlist_add"

external clear : Evas.obj -> unit = "ml_elm_genlist_clear"

external multi_select_set : Evas.obj -> bool -> unit =
  "ml_elm_genlist_multi_select_set"

external multi_select_get : Evas.obj -> bool = "ml_elm_genlist_multi_select_get"

external mode_set : Evas.obj -> Elm_list.mode -> unit =
  "ml_elm_genlist_mode_set"

external mode_get : Evas.obj -> Elm_list.mode = "ml_elm_genlist_mode_get"

