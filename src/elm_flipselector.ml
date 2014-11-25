module AF = Autofun.Elm_flipselector.F (struct
  type evas_object = Evas.obj
  type elm_object_item = Elm_object.item
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_flipselector_add"

let addx = Elm_object.create_addx add

external item_append :
  Evas.obj -> ?label:string -> ?func:Evas.smart_cb -> unit -> Elm_object.item =
      "ml_elm_flipselector_item_append"

external item_prepend :
  Evas.obj -> ?label:string -> ?func:Evas.smart_cb -> unit -> Elm_object.item =
      "ml_elm_flipselector_item_prepend"

external items_get : Evas.obj -> Elm_object.item list =
  "ml_elm_flipselector_items_get"

external first_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_flipselector_first_item_get"

external last_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_flipselector_last_item_get"

external selected_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_flipselector_selected_item_get"

external item_prev_get : Elm_object.item -> Elm_object.item option =
  "ml_elm_flipselector_item_prev_get"

external item_next_get : Elm_object.item -> Elm_object.item option =
  "ml_elm_flipselector_item_next_get"

