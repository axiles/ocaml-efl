external add : Evas.obj -> Evas.obj = "ml_elm_popup_add"

external item_append :
  Evas.obj -> ?label:string -> ?icon:Evas.obj -> ?func:Evas.smart_cb -> unit ->
      Elm_object.item =
      "ml_elm_popup_item_append"

