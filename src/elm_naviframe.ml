external add : Evas.obj -> Evas.obj = "ml_elm_naviframe_add"

external item_push :
  Evas.obj -> ?title_label:string -> ?prev_btn:Evas.obj -> ?next_btn:Evas.obj ->
    Evas.obj -> ?item_style:string -> unit -> Elm_object.item
  =
    "ml_elm_naviframe_item_push_byte"
    "ml_elm_naviframe_item_push_native"

external item_insert_before :
  Evas.obj -> Elm_object.item -> ?title_label:string -> ?prev_btn:Evas.obj ->
    ?next_btn:Evas.obj -> Evas.obj -> ?item_style:string -> unit ->
    Elm_object.item
  =
    "ml_elm_naviframe_item_insert_before_byte"
    "ml_elm_naviframe_item_insert_before_native"

external item_insert_after :
  Evas.obj -> Elm_object.item -> ?title_label:string -> ?prev_btn:Evas.obj ->
    ?next_btn:Evas.obj -> Evas.obj -> ?item_style:string -> unit ->
    Elm_object.item
  =
    "ml_elm_naviframe_item_insert_after_byte"
    "ml_elm_naviframe_item_insert_after_native"

external item_pop : Evas.obj -> Evas.obj option = "ml_elm_naviframe_item_pop"

external item_pop_to : Elm_object.item -> unit = "ml_elm_naviframe_item_pop_to"

external item_promote : Elm_object.item -> unit =
  "ml_elm_naviframe_item_promote"

external content_preserve_on_pop_set : Evas.obj -> bool -> unit =
  "ml_elm_naviframe_content_preserve_on_pop_set"

external content_preserve_on_pop_get : Evas.obj -> bool =
  "ml_elm_naviframe_content_preserve_on_pop_get"

external top_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_naviframe_top_item_get"

external bottom_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_naviframe_bottom_item_get"

external item_style_set : Elm_object.item -> string option -> unit =
  "ml_elm_naviframe_item_style_set"

external item_style_get : Elm_object.item -> string =
  "ml_elm_naviframe_item_style_get"

external item_title_visible_set : Elm_object.item -> bool -> unit =
  "ml_elm_naviframe_item_title_visible_set"

external item_title_visible_get : Elm_object.item -> bool =
  "ml_elm_naviframe_item_title_visible_get"

external prev_btn_auto_pushed_set : Evas.obj -> bool -> unit =
  "ml_elm_naviframe_prev_btn_auto_pushed_set"

external prev_btn_auto_pushed_get : Evas.obj -> bool =
  "ml_elm_naviframe_prev_btn_auto_pushed_get"

external items_get : Evas.obj -> Elm_object.item list =
  "ml_elm_naviframe_items_get"

external event_enabled_set : Evas.obj -> bool -> unit =
  "ml_elm_naviframe_event_enabled_set"

external event_enabled_get : Evas.obj -> bool =
  "ml_elm_naviframe_event_enabled_get"

external item_simple_promote : Evas.obj -> Evas.obj -> unit =
  "ml_elm_naviframe_item_simple_promote"

let item_simple_push obj content =
  let it = item_push obj content () in
  item_title_visible_set it false;
  it

module E = struct
  type u = Evas.Event_type.u
  let f = Evas.Event_type.create_unit
  let transition_finished = f "transition,finished"
  let focused = f "focused"
  let unfocused = f "unfocused"
end

