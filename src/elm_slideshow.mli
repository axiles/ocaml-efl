type item_class = {
  func_get : Evas.obj -> Evas.obj option;
  func_del : Evas.obj -> unit
}

val add : Evas.obj -> Evas.obj

val item_add : Evas.obj -> item_class -> Elm_object.item

val item_show : Elm_object.item -> unit

val next : Evas.obj -> unit

val previous : Evas.obj -> unit

val transitions_get : Evas.obj -> string list

val transition_set : Evas.obj -> string -> unit

val transition_get : Evas.obj -> string

val timeout_set : Evas.obj -> float -> unit

val timeout_get : Evas.obj -> float

