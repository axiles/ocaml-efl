(** Popup *)

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

val add : Evas.obj -> Evas.obj

val addx : Elm_object.t_addx

val item_append :
  Evas.obj -> ?label:string -> ?icon:Evas.obj -> ?func:Evas.smart_cb -> unit ->
    Elm_object.item

val align_set : Evas.obj -> float -> float -> unit

val align_get : Evas.obj -> float * float

val content_text_wrap_type_set : Evas.obj -> Elm.wrap_type -> unit

val content_text_wrap_type_get : Evas.obj -> Elm.wrap_type

val orient_set : Evas.obj -> orient -> unit

val orient_get : Evas.obj -> orient

val timeout_set : Evas.obj -> float -> unit

val timeout_get : Evas.obj -> float

val allow_events_set : Evas.obj -> bool -> unit

val allow_events_get : Evas.obj -> bool

