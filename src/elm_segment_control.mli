val add : Evas.obj -> Evas.obj

val item_add :
  Evas.obj -> ?icon:Evas.obj -> ?label:string -> unit -> Elm_object.item

val item_insert_at :
  Evas.obj -> ?icon:Evas.obj -> ?label:string -> int -> Elm_object.item

val item_del_at : Evas.obj -> int -> unit

