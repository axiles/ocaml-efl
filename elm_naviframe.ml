external add : Evas.obj -> Evas.obj = "ml_elm_naviframe_add"

external item_push :
  Evas.obj -> ?title_label:string -> ?prev_btn:Evas.obj -> ?next_btn:Evas.obj ->
    Evas.obj -> ?item_style:string -> unit -> Elm_object.item
  =
    "ml_elm_naviframe_item_push_byte"
    "ml_elm_naviframe_item_push_native"

let item_simple_push obj content = item_push obj content ()

