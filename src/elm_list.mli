(** elm_list_* Elm_List_* *)

(** The following function is not interfaced:

elm_list_item_sorted_insert

*)

type mode = [`compress | `scroll | `limit | `expand | `last]

val add : Evas.obj -> Evas.obj

val go : Evas.obj -> unit

val multi_select_set : Evas.obj -> bool -> unit 

val multi_select_get : Evas.obj -> bool

val mode_set : Evas.obj -> mode -> unit

val mode_get : Evas.obj -> mode

val horizontal_set : Evas.obj -> bool -> unit

val horizontal_get : Evas.obj -> bool

val select_mode_set : Evas.obj -> Elm_object.select_mode -> unit

val select_mode_get : Evas.obj -> Elm_object.select_mode

val item_append :
  Evas.obj -> ?label:string -> ?icon:Evas.obj -> ?iend:Evas.obj ->
    ?func:Evas.smart_cb -> unit -> Elm_object.item

val item_prepend :
  Evas.obj -> ?label:string -> ?icon:Evas.obj -> ?iend:Evas.obj ->
    ?func:Evas.smart_cb -> unit -> Elm_object.item

val item_insert_before :
  Evas.obj -> Elm_object.item -> ?label:string -> ?icon:Evas.obj ->
    ?iend:Evas.obj -> ?func:Evas.smart_cb -> unit -> Elm_object.item

val item_insert_after :
  Evas.obj -> Elm_object.item -> ?label:string -> ?icon:Evas.obj ->
    ?iend:Evas.obj -> ?func:Evas.smart_cb -> unit -> Elm_object.item

val clear : Evas.obj -> unit

val items_get : Evas.obj -> Elm_object.item list

val selected_item_get : Evas.obj -> Elm_object.item option

val selected_items_get : Evas.obj -> Elm_object.item list

val item_selected_set : Elm_object.item -> bool -> unit

val item_separator_set : Elm_object.item -> bool -> unit

val item_separator_get : Elm_object.item -> bool

val item_show : Elm_object.item -> unit

val item_bring_in : Elm_object.item -> unit

val item_object_get : Elm_object.item -> Evas.obj

val item_prev : Elm_object.item -> Elm_object.item option

val item_next : Elm_object.item -> Elm_object.item option

val first_item_get : Evas.obj -> Elm_object.item option

val last_item_get : Evas.obj -> Elm_object.item option

module E : sig
  type 'a v = 'a Evas.Event_type.v
  type u = Evas.Event_type.u
  val activated : Elm_object.item v
  val clicked_double : Elm_object.item v
  val selected : u
  val unselected : u
  val longpressed : u
  val edge_top : u
  val edge_bottom : u
  val edge_left : u
  val edge_right : u
  val highlighted : u
  val unhighlighted : u
  val language_changed : u
  val focused : u
  val unfocused : u
end

