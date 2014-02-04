type field_type = [`year | `month | `date | `hour | `minute | `ampm]

val add : Evas.obj -> Evas.obj

val format_get : Evas.obj -> string

val format_set : Evas.obj -> string -> unit

val field_limit_get : Evas.obj -> field_type -> int * int

val field_limit_set : Evas.obj -> field_type -> int -> int -> unit

