(** Slideshow *)

type item_class = {
  func_get : Evas.obj -> Evas.obj option;
  func_del : Evas.obj -> unit
}

val add : Evas.obj -> Evas.obj

val addx : Elm_object.t_addx

val item_add : Evas.obj -> item_class -> Elm_object.item

val item_show : Elm_object.item -> unit

val next : Evas.obj -> unit

val previous : Evas.obj -> unit

val transitions_get : Evas.obj -> string list

val transition_set : Evas.obj -> string -> unit

val transition_get : Evas.obj -> string

val timeout_set : Evas.obj -> float -> unit

val timeout_get : Evas.obj -> float

val loop_set : Evas.obj -> bool -> unit

val loop_get : Evas.obj -> bool

val clear : Evas.obj -> unit

val items_get : Evas.obj -> Elm_object.item list

val item_current_get : Evas.obj -> Elm_object.item option

val item_object_get : Elm_object.item -> Evas.obj option

val item_nth_get : Evas.obj -> int -> Elm_object.item option

val layout_set : Evas.obj -> string -> unit

val layout_get : Evas.obj -> string

val layouts_get : Evas.obj -> string list

val cache_before_set : Evas.obj -> int -> unit

val cache_before_get : Evas.obj -> int

val cache_after_set : Evas.obj -> int -> unit

val cache_after_get : Evas.obj -> int

val count_get : Evas.obj -> int

