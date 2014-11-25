include Henums.Elm_toolbar

type item_state

module AF = Autofun.Elm_toolbar.F (struct
  type evas_object = Evas.obj
  type elm_object_item = Elm_object.item
  type elm_toolbar_shrink_mode = shrink_mode
  type elm_toolbar_item_state = item_state
  type elm_object_select_mode = Elm_object.select_mode
  type elm_icon_lookup_order = Elm_icon.lookup_order
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_toolbar_add"

let addx = Elm_object.create_addx add

external item_append :
  Evas.obj -> ?icon:string -> ?label:string ->
    ?func:Evas.smart_cb -> unit -> Elm_object.item =
  "ml_elm_toolbar_item_append"

external item_prepend :
  Evas.obj -> ?icon:string -> ?label:string ->
    ?func:Evas.smart_cb -> unit -> Elm_object.item =
  "ml_elm_toolbar_item_prepend"

external item_insert_before :
  Evas.obj -> Elm_object.item -> ?icon:string -> ?label:string ->
    ?func:Evas.smart_cb -> unit -> Elm_object.item =
  "ml_elm_toolbar_item_insert_before_byte"
  "ml_elm_toolbar_item_insert_before_native"

external item_insert_after :
  Evas.obj -> Elm_object.item -> ?icon:string -> ?label:string ->
    ?func:Evas.smart_cb -> unit -> Elm_object.item =
  "ml_elm_toolbar_item_insert_after_byte"
  "ml_elm_toolbar_item_insert_after_native"

external first_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_toolbar_first_item_get"

external last_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_toolbar_last_item_get"

external item_next_get : Elm_object.item -> Elm_object.item option =
  "ml_elm_toolbar_item_next_get"

external item_prev_get : Elm_object.item -> Elm_object.item option =
  "ml_elm_toolbar_item_prev_get"

external item_show : Elm_object.item -> item_scrollto_type list -> unit =
  "ml_elm_toolbar_item_show"

external item_bring_in : Elm_object.item -> item_scrollto_type list -> unit =
  "ml_elm_toolbar_item_bring_in"

external item_find_by_label : Evas.obj -> string -> Elm_object.item option =
  "ml_elm_toolbar_item_find_by_label"

external selected_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_toolbar_selected_item_get"

external more_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_toolbar_more_item_get"

external item_icon_object_get : Elm_object.item -> Evas.obj =
  "ml_elm_toolbar_item_icon_object_get"

external item_icon_file_set :
  Elm_object.item -> string -> ?key:string -> unit -> bool =
    "ml_elm_toolbar_item_icon_file_set"

external menu_parent_get : Evas.obj -> Evas.obj =
  "ml_elm_toolbar_menu_parent_get"

external item_menu_get : Elm_object.item -> Evas.obj option =
  "ml_elm_toolbar_item_menu_get"

let item_menu_set_get it =
  item_menu_set it true;
  match item_menu_get it with
  | None -> failwith "Elm_toolbar.item_menu_set_get"
  | Some menu -> menu

external item_state_add :
  Elm_object.item -> ?icon:string -> ?label:string -> ?func:Evas.smart_cb ->
    unit -> item_state =
      "ml_elm_toolbar_item_state_add"

external item_state_set_null : Elm_object.item -> bool =
  "ml_elm_toolbar_item_state_set_null"

external item_state_get : Elm_object.item -> item_state option =
  "ml_elm_toolbar_item_state_get"

external item_state_next : Elm_object.item -> item_state option =
  "ml_elm_toolbar_item_state_next"

external item_state_prev : Elm_object.item -> item_state option =
  "ml_elm_toolbar_item_state_prev"

