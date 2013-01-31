type mode = [`compress | `scroll | `limit | `expand | `last]

external add : Evas.obj -> Evas.obj = "ml_elm_list_add"

external go : Evas.obj -> unit = "ml_elm_list_go"

external multi_select_set : Evas.obj -> bool -> unit =
  "ml_elm_list_multi_select_set"

external multi_select_get : Evas.obj -> bool = "ml_elm_list_multi_select_get"

external mode_set : Evas.obj -> mode -> unit = "ml_elm_list_mode_set"

external mode_get : Evas.obj -> mode = "ml_elm_list_mode_get"

