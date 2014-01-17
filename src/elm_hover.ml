type axis = [`none | `horizontal | `vertical | `both]

external add : Evas.obj -> Evas.obj = "ml_elm_hover_add"

external target_set : Evas.obj -> Evas.obj -> unit = "ml_elm_hover_target_set"

external target_get : Evas.obj -> Evas.obj = "ml_elm_hover_target_get"

external parent_set : Evas.obj -> Evas.obj -> unit = "ml_elm_hover_parent_set"

external parent_get : Evas.obj -> Evas.obj = "ml_elm_hover_parent_get"

external best_content_location_get : Evas.obj -> axis -> string option =
  "ml_elm_hover_best_content_location_get"

