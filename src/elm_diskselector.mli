val add : Evas.obj -> Evas.obj

val round_enabled_set : Evas.obj -> bool -> unit

val round_enabled_get : Evas.obj -> bool

val side_text_max_length_get : Evas.obj -> int

val side_text_max_length_set : Evas.obj -> int -> unit

val display_item_num_set : Evas.obj -> int -> unit

val display_item_num_get : Evas.obj -> int

val clear : Evas.obj -> unit

val items_get : Evas.obj -> Elm_object.item list

val item_append :
  Evas.obj -> ?label:string -> ?icon:Evas.obj -> ?func:Evas.smart_cb -> unit ->
    Elm_object.item

val selected_item_get : Evas.obj -> Elm_object.item option

val item_selected_set : Elm_object.item -> bool -> unit

val first_item_get : Evas.obj -> Elm_object.item option

val last_item_get : Evas.obj -> Elm_object.item option

