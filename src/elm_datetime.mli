(** Datetime *)

type field_type = [`year | `month | `date | `hour | `minute | `ampm]

val add : Evas.obj -> Evas.obj

val addx : Elm_object.t_addx

val format_get : Evas.obj -> string

val format_set : Evas.obj -> string -> unit

val value_max_get : Evas.obj -> Unix.tm option

val value_max_set : Evas.obj -> Unix.tm -> bool

val value_min_get : Evas.obj -> Unix.tm option

val value_min_set : Evas.obj -> Unix.tm -> bool

val field_limit_get : Evas.obj -> field_type -> int * int

val field_limit_set : Evas.obj -> field_type -> int -> int -> unit

val value_get : Evas.obj -> Unix.tm option

val value_set : Evas.obj -> Unix.tm -> bool

val field_visible_get : Evas.obj -> field_type -> bool

val field_visible_set : Evas.obj -> field_type -> bool -> unit

