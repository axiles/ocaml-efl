type item_class = {
  func_get : Evas.obj -> Evas.obj option;
  func_del : Evas.obj -> unit
}

external add : Evas.obj -> Evas.obj = "ml_elm_slideshow_add"

external item_add : Evas.obj -> item_class -> Elm_object.item =
  "ml_elm_slideshow_item_add"

external item_show : Elm_object.item -> unit = "ml_elm_slideshow_item_show"

external next : Evas.obj -> unit = "ml_elm_slideshow_next"

external previous : Evas.obj -> unit = "ml_elm_slideshow_previous"

external transitions_get : Evas.obj -> string list =
  "ml_elm_slideshow_transitions_get"

external transition_set : Evas.obj -> string -> unit =
  "ml_elm_slideshow_transition_set"

external transition_get : Evas.obj -> string = "ml_elm_slideshow_transition_get"

external timeout_set : Evas.obj -> float -> unit =
  "ml_elm_slideshow_timeout_set"

external timeout_get : Evas.obj -> float = "ml_elm_slideshow_timeout_get"

external loop_set : Evas.obj -> bool -> unit = "ml_elm_slideshow_loop_set"

external loop_get : Evas.obj -> bool = "ml_elm_slideshow_loop_get"

external clear : Evas.obj -> unit = "ml_elm_slideshow_clear"

external items_get : Evas.obj -> Elm_object.item list =
  "ml_elm_slideshow_items_get"

external item_current_get : Evas.obj -> Elm_object.item option =
  "ml_elm_slideshow_item_current_get"

external item_object_get : Elm_object.item -> Evas.obj option =
  "ml_elm_slideshow_item_object_get"

