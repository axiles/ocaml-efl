
val add : Evas.obj -> Evas.obj

val icon_size_set : Evas.obj -> int -> unit

val icon_size_get : Evas.obj -> int

val icon_order_lookup_set : Evas.obj -> Elm_icon.lookup_order -> unit

val icon_order_lookup_get : Evas.obj -> Elm_icon.lookup_order

val item_append :
  Evas.obj -> ?icon:string -> ?label:string -> ?func:Evas.smart_cb -> unit ->
    Elm_object.item

val item_prepend :
  Evas.obj -> ?icon:string -> ?label:string -> ?func:Evas.smart_cb ->
    unit -> Elm_object.item

val item_insert_before :
  Evas.obj -> Elm_object.item -> ?icon:string -> ?label:string ->
    ?func:Evas.smart_cb -> unit -> Elm_object.item

val item_insert_after :
  Evas.obj -> Elm_object.item -> ?icon:string -> ?label:string ->
    ?func:Evas.smart_cb -> unit -> Elm_object.item

val first_item_get : Evas.obj -> Elm_object.item option

val last_item_get : Evas.obj -> Elm_object.item option

val item_next_get : Elm_object.item -> Elm_object.item option

val item_prev_get : Elm_object.item -> Elm_object.item option

val item_priority_set : Elm_object.item -> int -> unit

val item_priority_get : Elm_object.item -> int

val item_find_by_label : Evas.obj -> string -> Elm_object.item option

