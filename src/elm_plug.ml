external add : Evas.obj -> Evas.obj = "ml_elm_plug_add"

let addx = Elm_object.create_addx add

external connect : Evas.obj -> string -> int -> bool -> bool =
  "ml_elm_plug_connect"

external image_object_get : Evas.obj -> Evas.obj =
  "ml_elm_plug_image_object_get"

