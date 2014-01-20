external add : Evas.obj -> Evas.obj = "ml_elm_flipselector_add"

external flip_next : Evas.obj -> unit = "ml_elm_flipselector_flip_next"

external flip_prev : Evas.obj -> unit = "ml_elm_flipselector_flip_prev"

external item_append :
  Evas.obj -> ?label:string -> ?func:Evas.smart_cb -> unit -> Elm_object.item =
      "ml_elm_flipselector_item_append"

external item_prepend :
  Evas.obj -> ?label:string -> ?func:Evas.smart_cb -> unit -> Elm_object.item =
      "ml_elm_flipselector_item_prepend"

external items_get : Evas.obj -> Elm_object.item list =
  "ml_elm_flipselector_items_get"

external first_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_flipselector_first_item_get"

external last_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_flipselector_last_item_get"

external selected_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_flipselector_selected_item_get"

external item_selected_set : Elm_object.item -> bool -> unit =
  "ml_elm_flipselector_item_selected_set"

external item_selected_get : Elm_object.item -> bool =
  "ml_elm_flipselector_item_selected_get"

external item_prev_get : Elm_object.item -> Elm_object.item option =
  "ml_elm_flipselector_item_prev_get"

external item_next_get : Elm_object.item -> Elm_object.item option =
  "ml_elm_flipselector_item_next_get"

external first_interval_set : Evas.obj -> float -> unit =
  "ml_elm_flipselector_first_interval_set"

external first_interval_get : Evas.obj -> float =
  "ml_elm_flipselector_first_interval_get"

