(** Multibuttonentry *)

val add : Evas.obj -> Evas.obj

val entry_get : Evas.obj -> Evas.obj option

val expanded_get : Evas.obj -> bool

val expanded_set : Evas.obj -> bool -> unit

val item_prepend :
  Evas.obj -> ?label:string -> ?func:Evas.smart_cb -> unit -> Elm_object.item

val item_append :
  Evas.obj -> ?label:string -> ?func:Evas.smart_cb -> unit -> Elm_object.item

val item_insert_before :
  Evas.obj -> Elm_object.item -> ?label:string -> ?func:Evas.smart_cb -> unit ->
    Elm_object.item

val item_insert_after :
  Evas.obj -> Elm_object.item -> ?label:string -> ?func:Evas.smart_cb -> unit ->
    Elm_object.item

val items_get : Evas.obj -> Elm_object.item list

val first_item_get : Evas.obj -> Elm_object.item option

val last_item_get : Evas.obj -> Elm_object.item option

val selected_item_get : Evas.obj -> Elm_object.item option

