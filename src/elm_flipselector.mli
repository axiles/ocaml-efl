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

