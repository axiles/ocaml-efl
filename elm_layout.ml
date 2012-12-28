external add : Evas.obj -> Evas.obj =
  "ml_elm_layout_add"

external box_append_with_bool : Evas.obj -> string -> Evas.obj -> bool =
  "ml_elm_layout_box_append_with_bool"

let box_append obj part child =
  if not (box_append_with_bool obj part child) then
    failwith "elm_layout_box_append"

external box_insert_at_with_bool :
  Evas.obj -> string -> Evas.obj -> int -> bool =
  "ml_elm_layout_box_insert_at_with_bool"

let box_insert_at obj part child pos =
  if not (box_insert_at_with_bool obj part child pos) then
    failwith "elm_layout_box_insert_at"

external box_insert_before_with_bool :
  Evas.obj -> string -> Evas.obj -> Evas.obj -> bool =
  "ml_elm_layout_box_insert_before_with_bool"

let box_insert_before obj part child ref =
  if not (box_insert_before_with_bool obj part child ref) then
    failwith "elm_layout_box_insert_before"

external box_prepend_with_bool : Evas.obj -> string -> Evas.obj -> bool =
  "ml_elm_layout_box_prepend_with_bool"

let box_prepend obj part child =
  if not (box_prepend_with_bool obj part child) then
    failwith "elm_layout_box_prepend"

