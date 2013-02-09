val add : Evas.obj -> Evas.obj

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

val item_title_visible_set : Elm_object.item -> bool -> unit

val item_simple_promote : Evas.obj -> Evas.obj -> unit

val item_simple_push : Evas.obj -> Evas.obj -> Elm_object.item

