val add : Evas.obj -> Evas.obj

val item_append :
  Evas.obj -> ?label:string -> ?icon:Evas.obj -> ?func:Evas.smart_cb -> unit ->
    Elm_object.item

val content_text_wrap_type_set : Evas.obj -> Elm.wrap_type -> unit

val content_text_wrap_type_get : Evas.obj -> Elm.wrap_type

