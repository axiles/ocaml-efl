external callback_add_ : Evas.obj -> string -> Evas.smart_cb -> unit =
  "ml_evas_object_smart_callback_add"

let callback_add obj et f =
  Evas.Signal.(callback_add_ obj (get_name et) (get_cb et f))

type sig_with_cb = Evas.obj -> unit

let create_sig_with_cb s cb obj = callback_add obj s cb

let connect scb obj = scb obj

