type transition

module AF = Autofun.Elm_box.F (struct
  type evas_object = Evas.obj
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_box_add"

let addx = Elm_object.create_addx add

external children_get : Evas.obj -> Evas.obj list = "ml_elm_box_children_get"

external padding_get : Evas.obj -> int * int = "ml_elm_box_padding_get"

external align_get : Evas.obj -> float * float = "ml_elm_box_align_get"

external layout_set : Evas.obj -> Evas_object.box_layout -> Ecore.cb -> unit =
  "ml_elm_box_layout_set"

external layout_transition :
  transition -> Evas.obj -> Evas_object.box_data -> unit =
  "ml_elm_box_layout_transition"

external transition_new :
  float -> Evas_object.box_layout -> Ecore.cb -> Evas_object.box_layout ->
    Ecore.cb -> Ecore.cb -> transition =
  "ml_elm_box_transition_new_byte"
  "ml_elm_box_transition_new_native"

external transition_free : transition -> unit -> unit =
  "ml_elm_box_transition_free"

