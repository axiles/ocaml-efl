external add : Evas.obj -> Evas.obj = "ml_elm_hoversel_add"

external horizontal_set : Evas.obj -> bool -> unit =
  "ml_elm_hoversel_horizontal_set"

external horizontal_get : Evas.obj -> bool = "ml_elm_hoversel_horizontal_get"

external hover_parent_set : Evas.obj -> Evas.obj -> unit =
  "ml_elm_hoversel_hover_parent_set"

external hover_parent_get : Evas.obj -> Evas.obj =
  "ml_elm_hoversel_hover_parent_get"

external hover_begin : Evas.obj -> unit = "ml_elm_hoversel_hover_begin"

external hover_end : Evas.obj -> unit = "ml_elm_hoversel_hover_end"

external expanded_get : Evas.obj -> bool = "ml_elm_hoversel_expanded_get"

external clear : Evas.obj -> unit = "ml_elm_hoversel_clear"

external items_get : Evas.obj -> Elm_object.item list =
  "ml_elm_hoversel_items_get"

external item_add :
  Evas.obj -> ?label:string -> ?icon:(string * Elm_icon.ty) ->
    ?func:Evas.smart_cb -> unit -> Elm_object.item =
      "ml_elm_hoversel_item_add"

