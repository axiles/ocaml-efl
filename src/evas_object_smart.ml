external callback_add_ : Evas.obj -> string -> Evas.smart_cb -> unit =
  "ml_evas_object_smart_callback_add"

let callback_add obj et f =
  callback_add_ obj (Evas.Event_type.get_name et) (Evas.Event_type.get_cb et f)

