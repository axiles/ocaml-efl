val add : Evas.obj -> Evas.obj

val flip_next : Evas.obj -> unit

val flip_prev : Evas.obj -> unit

val item_append :
  Evas.obj -> ?label:string -> ?func:Evas.smart_cb -> unit -> Elm_object.item

val item_prepend :
  Evas.obj -> ?label:string -> ?func:Evas.smart_cb -> unit -> Elm_object.item

val items_get : Evas.obj -> Elm_object.item list

val first_item_get : Evas.obj -> Elm_object.item option

val last_item_get : Evas.obj -> Elm_object.item option

val selected_item_get : Evas.obj -> Elm_object.item option

val item_selected_set : Elm_object.item -> bool -> unit

val item_selected_get : Elm_object.item -> bool

val item_prev_get : Elm_object.item -> Elm_object.item option

val item_next_get : Elm_object.item -> Elm_object.item option

val first_interval_set : Evas.obj -> float -> unit

val first_interval_get : Evas.obj -> float

