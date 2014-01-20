type direction = [
  | `down
  | `right
  | `left
  | `up
  | `unknown]

external add : Evas.obj -> Evas.obj = "ml_elm_ctxpopup_add"

external hover_parent_set : Evas.obj -> Evas.obj -> unit =
  "ml_elm_ctxpopup_hover_parent_set"

external hover_parent_get : Evas.obj -> Evas.obj =
  "ml_elm_ctxpopup_hover_parent_get"

external clear : Evas.obj -> unit = "ml_elm_ctxpopup_clear"

external horizontal_set : Evas.obj -> bool -> unit =
  "ml_elm_ctxpopup_horizontal_set"

external horizontal_get : Evas.obj -> bool = "ml_elm_ctxpopup_horizontal_get"

external item_append :
  Evas.obj -> ?label:string -> ?icon:Evas.obj -> ?func:Evas.smart_cb -> unit ->
      Elm_object.item =
      "ml_elm_ctxpopup_item_append"

external direction_priority_set :
  Evas.obj -> direction -> direction -> direction -> direction -> unit =
    "ml_elm_ctxpopup_direction_priority_set"

external direction_priority_get :
  Evas.obj -> direction * direction * direction * direction =
    "ml_elm_ctxpopup_direction_priority_get"

external direction_get : Evas.obj -> direction = "ml_elm_ctxpopup_direction_get"

external dismiss : Evas.obj -> unit = "ml_elm_ctxpopup_dismiss"

