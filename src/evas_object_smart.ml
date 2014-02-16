external callback_add_ : Evas.obj -> string -> Evas.smart_cb -> unit =
  "ml_evas_object_smart_callback_add"

let callback_add obj et f =
  Evas.Signal.(callback_add_ obj (get_name et) (get_cb et f))

