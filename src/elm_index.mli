val add : Evas.obj -> Evas.obj

val autohide_disabled_set : Evas.obj -> bool -> unit

val autohide_disabled_get : Evas.obj -> bool

val item_level_set : Evas.obj -> int -> unit

val item_level_get : Evas.obj -> int

val item_selected_set : Elm_object.item -> bool -> unit

val selected_item_get : Evas.obj -> int -> Elm_object.item option

val item_append : Evas.obj -> string -> Evas.smart_cb -> Elm_object.item

val item_prepend : Evas.obj -> string -> Evas.smart_cb -> Elm_object.item

val item_insert_after :
  Evas.obj -> Elm_object.item -> string -> Evas.smart_cb -> Elm_object.item

val item_insert_before :
  Evas.obj -> Elm_object.item -> string -> Evas.smart_cb -> Elm_object.item

val item_clear : Evas.obj -> unit

val level_go : Evas.obj -> int -> unit

val item_letter_get : Elm_object.item -> string

val indicator_disabled_set : Evas.obj -> bool -> unit

val indicator_disabled_get : Evas.obj -> bool

