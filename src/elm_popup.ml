type orient = [
  | `top
  | `centre
  | `bottom
  | `left
  | `right
  | `top_left
  | `top_right
  | `bottom_left
  | `bottom_right
  | `last]

external add : Evas.obj -> Evas.obj = "ml_elm_popup_add"

external item_append :
  Evas.obj -> ?label:string -> ?icon:Evas.obj -> ?func:Evas.smart_cb -> unit ->
      Elm_object.item =
      "ml_elm_popup_item_append"

external content_text_wrap_type_set : Evas.obj -> Elm.wrap_type -> unit =
  "ml_elm_popup_content_text_wrap_type_set"

external content_text_wrap_type_get : Evas.obj -> Elm.wrap_type =
  "ml_elm_popup_content_text_wrap_type_get"

external orient_set : Evas.obj -> orient -> unit = "ml_elm_popup_orient_set"

external orient_get : Evas.obj -> orient = "ml_elm_popup_orient_get"

