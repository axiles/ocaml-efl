(** elm_hoversel_* *)

val add : Evas.obj -> Evas.obj

val horizontal_set : Evas.obj -> bool -> unit

val horizontal_get : Evas.obj -> bool

val hover_parent_set : Evas.obj -> Evas.obj -> unit

val hover_parent_get : Evas.obj -> Evas.obj

val hover_begin : Evas.obj -> unit

val hover_end : Evas.obj -> unit

val expanded_get : Evas.obj -> bool

val clear : Evas.obj -> unit

val items_get : Evas.obj -> Elm_object.item list

val item_add :
  Evas.obj -> ?label:string -> ?icon:(string * Elm_icon.ty) ->
    ?func:Evas.smart_cb -> unit -> Elm_object.item
    
val item_icon_set :
  Elm_object.item -> string -> ?g:string -> Elm_icon.ty -> unit

val item_icon_get : Elm_object.item -> string * string option * Elm_icon.ty

module E : sig
  type u = Evas.Event_type.u
  val clicked : u
  val selected : u
  val dismissed : u
end

