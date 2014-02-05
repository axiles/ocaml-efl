(** Hover *)

type axis = [`none | `horizontal | `vertical | `both]

val add : Evas.obj -> Evas.obj

val target_set : Evas.obj -> Evas.obj -> unit

val target_get : Evas.obj -> Evas.obj

val parent_set : Evas.obj -> Evas.obj -> unit

val parent_get : Evas.obj -> Evas.obj

val best_content_location_get : Evas.obj -> axis -> string option

val dismiss : Evas.obj -> unit

