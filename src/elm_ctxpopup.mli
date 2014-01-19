val add : Evas.obj -> Evas.obj

val hover_parent_set : Evas.obj -> Evas.obj -> unit

val hover_parent_get : Evas.obj -> Evas.obj

val clear : Evas.obj -> unit

val horizontal_set : Evas.obj -> bool -> unit

val horizontal_get : Evas.obj -> bool

val item_append :
  Evas.obj -> ?label:string -> ?icon:Evas.obj -> ?func:Evas.smart_cb -> unit ->
    Elm_object.item

