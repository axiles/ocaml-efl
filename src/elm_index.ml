external add : Evas.obj -> Evas.obj = "ml_elm_index_add"

let addx = Elm_object.create_addx add

external autohide_disabled_set : Evas.obj -> bool -> unit =
  "ml_elm_index_autohide_disabled_set"

external autohide_disabled_get : Evas.obj -> bool =
  "ml_elm_index_autohide_disabled_get"

external item_level_set : Evas.obj -> int -> unit =
  "ml_elm_index_item_level_set"

external item_level_get : Evas.obj -> int = "ml_elm_index_item_level_get"

external item_selected_set : Elm_object.item -> bool -> unit =
  "ml_elm_index_item_selected_set"

external selected_item_get : Evas.obj -> int -> Elm_object.item option =
  "ml_elm_index_selected_item_get"

external item_append : Evas.obj -> string -> Evas.smart_cb -> Elm_object.item =
  "ml_elm_index_item_append"

external item_prepend : Evas.obj -> string -> Evas.smart_cb -> Elm_object.item =
  "ml_elm_index_item_prepend"

external item_insert_after :
  Evas.obj -> Elm_object.item -> string -> Evas.smart_cb -> Elm_object.item =
    "ml_elm_index_item_insert_after"

external item_insert_before :
  Evas.obj -> Elm_object.item -> string -> Evas.smart_cb -> Elm_object.item =
    "ml_elm_index_item_insert_before"

external item_clear : Evas.obj -> unit = "ml_elm_index_item_clear"

external level_go : Evas.obj -> int -> unit = "ml_elm_index_level_go"

external item_letter_get : Elm_object.item -> string =
  "ml_elm_index_item_letter_get"

external indicator_disabled_set : Evas.obj -> bool -> unit =
  "ml_elm_index_indicator_disabled_set"

external indicator_disabled_get : Evas.obj -> bool =
  "ml_elm_index_indicator_disabled_get"

external horizontal_set : Evas.obj -> bool -> unit =
  "ml_elm_index_horizontal_set"

external horizontal_get : Evas.obj -> bool = "ml_elm_index_horizontal_get"

external delay_change_time_set : Evas.obj -> float -> unit =
  "ml_elm_index_delay_change_time_set"

external delay_change_time_get : Evas.obj -> float =
  "ml_elm_index_delay_change_time_get"

external omit_enabled_set : Evas.obj -> bool -> unit =
  "ml_elm_index_omit_enabled_set"

external omit_enabled_get : Evas.obj -> bool = "ml_elm_index_omit_enabled_get"

