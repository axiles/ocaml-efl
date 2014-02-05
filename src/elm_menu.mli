(** Menu *)

val add : Evas.obj -> Evas.obj

val parent_set : Evas.obj -> Evas.obj -> unit

val parent_get : Evas.obj -> Evas.obj

val move : Evas.obj -> int -> int -> unit

val close : Evas.obj -> unit

val items_get : Evas.obj -> Elm_object.item list

val item_object_get : Elm_object.item -> Evas.obj

val item_add :
  Evas.obj -> ?parent:Elm_object.item -> ?icon:string -> ?label:string ->
    ?func:Evas.smart_cb -> unit -> Elm_object.item

val item_icon_name_set : Elm_object.item -> string -> unit

val item_icon_name_get : Elm_object.item -> string option

val item_selected_set : Elm_object.item -> bool -> unit

val item_selected_get : Elm_object.item -> bool

val item_separator_add : Evas.obj -> Elm_object.item -> Elm_object.item

val item_is_separator : Elm_object.item -> bool

val item_subitems_get : Elm_object.item -> Elm_object.item list

val item_subitems_clear : Elm_object.item -> unit

val item_index_get : Elm_object.item -> int

val selected_item_get : Evas.obj -> Elm_object.item option

val last_item_get : Evas.obj -> Elm_object.item option

val first_item_get : Evas.obj -> Elm_object.item option

val item_next_get : Elm_object.item -> Elm_object.item option

val item_prev_get : Elm_object.item -> Elm_object.item option

