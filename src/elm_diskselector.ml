external add : Evas.obj -> Evas.obj = "ml_elm_diskselector_add"

external round_enabled_set : Evas.obj -> bool -> unit =
  "ml_elm_diskselector_round_enabled_set"

external round_enabled_get : Evas.obj -> bool =
  "ml_elm_diskselector_round_enabled_get"

external side_text_max_length_get : Evas.obj -> int =
  "ml_elm_diskselector_side_text_max_length_get"

external side_text_max_length_set : Evas.obj -> int -> unit =
  "ml_elm_diskselector_side_text_max_length_set"

external display_item_num_set : Evas.obj -> int -> unit =
  "ml_elm_diskselector_display_item_num_set"

external display_item_num_get : Evas.obj -> int =
  "ml_elm_diskselector_display_item_num_get"

external clear : Evas.obj -> unit = "ml_elm_diskselector_clear"

external items_get : Evas.obj -> Elm_object.item list =
  "ml_elm_diskselector_items_get"

external item_append :
  Evas.obj -> ?label:string -> ?icon:Evas.obj -> ?func:Evas.smart_cb -> unit ->
      Elm_object.item =
      "ml_elm_diskselector_item_append"

external selected_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_diskselector_selected_item_get"

external item_selected_set : Elm_object.item -> bool -> unit =
  "ml_elm_diskselector_item_selected_set"

external item_selected_get : Elm_object.item -> bool =
  "ml_elm_diskselector_item_selected_get"

external first_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_diskselector_first_item_get"

external last_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_diskselector_last_item_get"

external item_prev_get : Elm_object.item -> Elm_object.item option =
  "ml_elm_diskselector_item_prev_get"

external item_next_get : Elm_object.item -> Elm_object.item option =
  "ml_elm_diskselector_item_next_get"
