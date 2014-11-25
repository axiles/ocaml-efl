type item_class = {
  func_get : Evas.obj -> Evas.obj option;
  func_del : Evas.obj -> unit
}

module AF = Autofun.Elm_slideshow.F (struct
  type evas_object = Evas.obj
  type elm_object_item = Elm_object.item
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_slideshow_add"

let addx = Elm_object.create_addx add

external item_add : Evas.obj -> item_class -> Elm_object.item =
  "ml_elm_slideshow_item_add"

external transitions_get : Evas.obj -> string list =
  "ml_elm_slideshow_transitions_get"

external items_get : Evas.obj -> Elm_object.item list =
  "ml_elm_slideshow_items_get"

external item_current_get : Evas.obj -> Elm_object.item option =
  "ml_elm_slideshow_item_current_get"

external item_object_get : Elm_object.item -> Evas.obj option =
  "ml_elm_slideshow_item_object_get"

external item_nth_get : Evas.obj -> int -> Elm_object.item option =
  "ml_elm_slideshow_item_nth_get"

external layouts_get : Evas.obj -> string list =
  "ml_elm_slideshow_layouts_get"

