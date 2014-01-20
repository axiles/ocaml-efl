external add : Evas.obj -> Evas.obj = "ml_elm_flipselector_add"

external flip_next : Evas.obj -> unit = "ml_elm_flipselector_flip_next"

external flip_prev : Evas.obj -> unit = "ml_elm_flipselector_flip_prev"

external item_append :
  Evas.obj -> ?label:string -> ?func:Evas.smart_cb -> unit -> Elm_object.item =
      "ml_elm_flipselector_item_append"

external item_prepend :
  Evas.obj -> ?label:string -> ?func:Evas.smart_cb -> unit -> Elm_object.item =
      "ml_elm_flipselector_item_prepend"

