type format_cb = int -> string

external add : Evas.obj -> Evas.obj = "ml_elm_multibuttonentry_add"

external entry_get : Evas.obj -> Evas.obj option =
  "ml_elm_multibuttonentry_entry_get"

external expanded_get : Evas.obj -> bool =
  "ml_elm_multibuttonentry_expanded_get"

external expanded_set : Evas.obj -> bool -> unit =
  "ml_elm_multibuttonentry_expanded_set"

external item_prepend :
  Evas.obj -> ?label:string -> ?func:Evas.smart_cb -> unit -> Elm_object.item =
    "ml_elm_multibuttonentry_item_prepend"

external item_append :
  Evas.obj -> ?label:string -> ?func:Evas.smart_cb -> unit -> Elm_object.item =
    "ml_elm_multibuttonentry_item_append"

external item_insert_before :
  Evas.obj -> Elm_object.item -> ?label:string -> ?func:Evas.smart_cb -> unit ->
    Elm_object.item =
      "ml_elm_multibuttonentry_item_insert_before"

external item_insert_after :
  Evas.obj -> Elm_object.item -> ?label:string -> ?func:Evas.smart_cb -> unit ->
    Elm_object.item =
      "ml_elm_multibuttonentry_item_insert_after"

external items_get : Evas.obj -> Elm_object.item list =
  "ml_elm_multibuttonentry_items_get"

external first_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_multibuttonentry_first_item_get"

external last_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_multibuttonentry_last_item_get"

external selected_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_multibuttonentry_selected_item_get"

external item_selected_set : Elm_object.item -> bool -> unit =
  "ml_elm_multibuttonentry_item_selected_set"

external item_selected_get : Elm_object.item -> bool =
  "ml_elm_multibuttonentry_item_selected_get"

external clear : Evas.obj -> unit = "ml_elm_multibuttonentry_clear"

external item_prev_get : Elm_object.item -> Elm_object.item option =
  "ml_elm_multibuttonentry_item_prev_get"

external item_next_get : Elm_object.item -> Elm_object.item option =
  "ml_elm_multibuttonentry_item_next_get"

external editable_set : Evas.obj -> bool -> unit =
  "ml_elm_multibuttonentry_editable_set"

external editable_get : Evas.obj -> bool =
  "ml_elm_multibuttonentry_editable_get"

external format_function_set : Evas.obj -> format_cb -> unit =
  "ml_elm_multibuttonentry_format_function_set"

