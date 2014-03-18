(** SegmentControl *)

val add : Evas.obj -> Evas.obj

val addx : Elm_object.t_addx

val item_add :
  Evas.obj -> ?icon:Evas.obj -> ?label:string -> unit -> Elm_object.item

val item_insert_at :
  Evas.obj -> ?icon:Evas.obj -> ?label:string -> int -> Elm_object.item

val item_del_at : Evas.obj -> int -> unit

val item_count_get : Evas.obj -> int

val item_get : Evas.obj -> int -> Elm_object.item option

val item_label_get : Evas.obj -> int -> string option

val item_icon_get : Evas.obj -> int -> Evas.obj option

val item_index_get : Elm_object.item -> int

val item_object_get : Elm_object.item -> Evas.obj

val item_selected_get : Evas.obj -> Elm_object.item option

val item_selected_set : Elm_object.item -> bool -> unit

