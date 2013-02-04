type item

type select_mode = [`default | `always | `none | `display_only]

external part_text_set : Evas.obj -> ?p:string -> string -> unit =
  "ml_elm_object_part_text_set"

external part_text_get : Evas.obj -> ?p:string -> unit -> string =
  "ml_elm_object_part_content_get"

external part_content_set : Evas.obj -> ?p:string -> Evas.obj -> unit =
  "ml_elm_object_part_content_set"

external part_content_set_null : Evas.obj -> ?p:string -> unit -> unit =
  "ml_elm_object_part_content_set_NULL"

external part_content_get : Evas.obj -> ?p:string -> unit -> Evas.obj =
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

external style_set : Evas.obj -> string -> bool = "ml_elm_object_style_set"

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

external top_widget_get : Evas.obj -> Evas.obj option =
  "ml_elm_object_top_widget_get"

external item_of_ptr : Evas.ptr -> item = "%identity"

external item_del : item -> unit = "ml_elm_object_item_del"

external item_disabled_set : item -> bool -> unit =
  "ml_elm_object_item_disabled_set"

external item_text_get : item -> string = "ml_elm_object_item_text_get"

