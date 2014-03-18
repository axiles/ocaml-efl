(** Naviframe *)

type item_pop_cb = Elm_object.item -> bool

val add : Evas.obj -> Evas.obj

val addx : Elm_object.t_addx

val item_push :
  Evas.obj -> ?title_label:string -> ?prev_btn:Evas.obj -> ?next_btn:Evas.obj ->
    Evas.obj -> ?item_style:string -> unit -> Elm_object.item

val item_insert_before :
  Evas.obj -> Elm_object.item -> ?title_label:string -> ?prev_btn:Evas.obj ->
    ?next_btn:Evas.obj -> Evas.obj -> ?item_style:string -> unit ->
    Elm_object.item

val item_insert_after :
  Evas.obj -> Elm_object.item -> ?title_label:string -> ?prev_btn:Evas.obj ->
    ?next_btn:Evas.obj -> Evas.obj -> ?item_style:string -> unit ->
    Elm_object.item

val item_pop : Evas.obj -> Evas.obj option

val item_pop_to : Elm_object.item -> unit

val item_promote : Elm_object.item -> unit

val content_preserve_on_pop_set : Evas.obj -> bool -> unit

val content_preserve_on_pop_get : Evas.obj -> bool

val top_item_get : Evas.obj -> Elm_object.item option

val bottom_item_get : Evas.obj -> Elm_object.item option

val item_style_set : Elm_object.item -> string option -> unit

val item_style_get : Elm_object.item -> string

val item_title_visible_set : Elm_object.item -> bool -> unit

val item_title_visible_get : Elm_object.item -> bool

val item_pop_cb_set : Elm_object.item -> item_pop_cb -> unit

val prev_btn_auto_pushed_set : Evas.obj -> bool -> unit

val prev_btn_auto_pushed_get : Evas.obj -> bool

val items_get : Evas.obj -> Elm_object.item list

val event_enabled_set : Evas.obj -> bool -> unit

val event_enabled_get : Evas.obj -> bool

val item_simple_promote : Evas.obj -> Evas.obj -> unit

val item_simple_push : Evas.obj -> Evas.obj -> Elm_object.item

