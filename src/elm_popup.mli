val add : Evas.obj -> Evas.obj

val item_append :
  Evas.obj -> ?label:string -> ?icon:Evas.obj -> ?func:Evas.smart_cb -> unit ->
    Elm_object.item

