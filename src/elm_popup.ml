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

let addx = Elm_object.create_addx add

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

external timeout_set : Evas.obj -> float -> unit = "ml_elm_popup_timeout_set"

external timeout_get : Evas.obj -> float = "ml_elm_popup_timeout_get"

external allow_events_set : Evas.obj -> bool -> unit =
  "ml_elm_popup_allow_events_set"

external allow_events_get : Evas.obj -> bool = "ml_elm_popup_allow_events_get"

