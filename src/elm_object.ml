type item

external part_text_set : Evas.obj -> ?p:string -> string -> unit =
  "ml_elm_object_part_content_set"

external part_text_get : Evas.obj -> ?p:string -> unit -> string =
  "ml_elm_object_part_content_get"

external part_content_set : Evas.obj -> ?p:string -> Evas.obj -> unit =
  "ml_elm_object_part_content_set"

external part_content_get : Evas.obj -> ?p:string -> Evas.obj =
  "ml_elm_object_part_content_get"

external part_content_unset : Evas.obj -> ?p:string -> unit -> Evas.obj =
  "ml_elm_object_part_content_unset"

external signal_emit : Evas.obj -> string -> string -> unit =
  "ml_elm_object_signal_emit"

external signal_callback_add :
  Evas.obj -> string -> string -> Edje.signal_cb -> unit =
  "ml_elm_object_signal_callback_add"

external signal_callback_del :
  Evas.obj -> string -> string -> Edje.signal_cb -> unit =
  "ml_elm_object_signal_callback_del"

external text_set : Evas.obj -> string -> unit = "ml_elm_object_text_set"

external style_set_with_bool : Evas.obj -> string -> bool =
  "ml_elm_object_style_set_with_bool"

let style_set obj s =
  (*if not (style_set_with_bool obj s) then failwith "elm_object_style_set"*)
  ignore (style_set_with_bool obj s)

external content_set : Evas.obj -> Evas.obj -> unit =
  "ml_elm_object_content_set"

external text_get : Evas.obj -> string = "ml_elm_object_text_get"

external content_unset : Evas.obj -> Evas.obj =
  "ml_elm_object_content_unset"

external disabled_set : Evas.obj -> bool -> unit = "ml_elm_object_disabled_set"

external disabled_get : Evas.obj -> bool = "ml_elm_object_disabled_get"

external focus_set : Evas.obj -> bool -> unit = "ml_elm_object_focus_set"

external parent_widget_get : Evas.obj -> Evas.obj option =
  "ml_elm_object_parent_widget_get"

