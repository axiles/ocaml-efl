type shrink_mode = [
  | `none
  | `hide
  | `scroll
  | `menu
  | `expand
  | `last]

external add : Evas.obj -> Evas.obj = "ml_elm_toolbar_add"

external icon_size_set : Evas.obj -> int -> unit =
  "ml_elm_toolbar_icon_size_set"

external icon_size_get : Evas.obj -> int = "ml_elm_toolbar_icon_size_get"

external icon_order_lookup_set : Evas.obj -> Elm_icon.lookup_order -> unit =
  "ml_elm_toolbar_icon_order_lookup_set"

external icon_order_lookup_get : Evas.obj -> Elm_icon.lookup_order =
  "ml_elm_toolbar_icon_order_lookup_get"

external item_append :
  Evas.obj -> ?icon:string -> ?label:string ->
    ?func:Evas.smart_cb -> unit -> Elm_object.item =
  "ml_elm_toolbar_item_append"

external item_prepend :
  Evas.obj -> ?icon:string -> ?label:string ->
    ?func:Evas.smart_cb -> unit -> Elm_object.item =
  "ml_elm_toolbar_item_prepend"

external item_insert_before :
  Evas.obj -> Elm_object.item -> ?icon:string -> ?label:string ->
    ?func:Evas.smart_cb -> unit -> Elm_object.item =
  "ml_elm_toolbar_item_insert_before_byte"
  "ml_elm_toolbar_item_insert_before_native"

external item_insert_after :
  Evas.obj -> Elm_object.item -> ?icon:string -> ?label:string ->
    ?func:Evas.smart_cb -> unit -> Elm_object.item =
  "ml_elm_toolbar_item_insert_after_byte"
  "ml_elm_toolbar_item_insert_after_native"

external first_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_toolbar_first_item_get"

external last_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_toolbar_last_item_get"

external item_next_get : Elm_object.item -> Elm_object.item option =
  "ml_elm_toolbar_item_next_get"

external item_prev_get : Elm_object.item -> Elm_object.item option =
  "ml_elm_toolbar_item_prev_get"

external item_priority_set : Elm_object.item -> int -> unit =
  "ml_elm_toolbar_item_priority_set"

external item_priority_get : Elm_object.item -> int =
  "ml_elm_toolbar_item_priority_get"

external item_find_by_label : Evas.obj -> string -> Elm_object.item option =
  "ml_elm_toolbar_item_find_by_label"

external selected_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_toolbar_selected_item_get"

external more_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_toolbar_more_item_get"

external item_icon_set : Elm_object.item -> string -> unit =
  "ml_elm_toolbar_item_icon_set"

external item_icon_get : Elm_object.item -> string =
  "ml_elm_toolbar_item_icon_get"

external item_object_get : Elm_object.item -> Evas.obj =
  "ml_elm_toolbar_item_object_get"

external item_icon_object_get : Elm_object.item -> Evas.obj =
  "ml_elm_toolbar_item_icon_object_get"

external item_icon_file_set :
  Elm_object.item -> string -> ?key:string -> unit -> bool =
    "ml_elm_toolbar_item_icon_file_set"

external item_separator_set : Elm_object.item -> bool -> unit =
  "ml_elm_toolbar_item_separator_set"

external item_separator_get : Elm_object.item -> bool =
  "ml_elm_toolbar_item_separator_get"

external shrink_mode_set : Evas.obj -> shrink_mode -> unit =
  "ml_elm_toolbar_shrink_mode_set"

external shrink_mode_get : Evas.obj -> shrink_mode =
  "ml_elm_toolbar_shrink_mode_get"

external homogeneous_set : Evas.obj -> bool -> unit =
  "ml_elm_toolbar_homogeneous_set"

external homogeneous_get : Evas.obj -> bool =
  "ml_elm_toolbar_homogeneous_get"

external menu_parent_set : Evas.obj -> Evas.obj -> unit =
  "ml_elm_toolbar_menu_parent_set"

external menu_parent_get : Evas.obj -> Evas.obj =
  "ml_elm_toolbar_menu_parent_get"

external align_set : Evas.obj -> float -> unit = "ml_elm_toolbar_align_set"

external align_get : Evas.obj -> float = "ml_elm_toolbar_align_get"

