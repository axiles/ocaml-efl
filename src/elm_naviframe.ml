external add : Evas.obj -> Evas.obj = "ml_elm_naviframe_add"

external item_push :
  Evas.obj -> ?title_label:string -> ?prev_btn:Evas.obj -> ?next_btn:Evas.obj ->
    Evas.obj -> ?item_style:string -> unit -> Elm_object.item
  =
    "ml_elm_naviframe_item_push_byte"
    "ml_elm_naviframe_item_push_native"

external item_title_visible_set : Elm_object.item -> bool -> unit =
  "ml_elm_naviframe_item_title_visible_set"

let item_simple_push obj content =
  let it = item_push obj content () in
  item_title_visible_set it false;
  it

external item_insert_before :
  Evas.obj -> Elm_object.item -> ?title_label:string -> ?prev_btn:Evas.obj ->
    ?next_btn:Evas.obj -> Evas.obj -> ?item_style:string -> unit ->
    Elm_object.item
  =
    "ml_elm_naviframe_item_insert_before_byte"
    "ml_elm_naviframe_item_insert_before_native"

external item_simple_promote : Evas.obj -> Evas.obj -> unit =
  "ml_elm_naviframe_item_simple_promote"

