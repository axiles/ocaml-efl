(** Panel *)

type orient = [`top | `bottom | `left | `right]

val add : Evas.obj -> Evas.obj

val addx : Elm_object.t_addx

val orient_set : Evas.obj -> orient -> unit

val orient_get : Evas.obj -> orient

val hidden_set : Evas.obj -> bool -> unit

val hidden_get : Evas.obj -> bool

val toggle : Evas.obj -> unit

