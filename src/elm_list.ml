external add : Evas.obj -> Evas.obj = "ml_elm_list_add"

external go : Evas.obj -> unit = "ml_elm_list_go"

external multi_select_set : Evas.obj -> bool -> unit =
  "ml_elm_list_multi_select_set"

external multi_select_get : Evas.obj -> bool = "ml_elm_list_multi_select_get"

