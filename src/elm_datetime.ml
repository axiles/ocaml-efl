type field_type = [`year | `month | `date | `hour | `minute | `ampm]

external add : Evas.obj -> Evas.obj = "ml_elm_datetime_add"

external format_set : Evas.obj -> string -> unit = "ml_elm_datetime_format_set"

external format_get : Evas.obj -> string = "ml_elm_datetime_format_get"

external field_limit_get : Evas.obj -> field_type -> int * int =
  "ml_elm_datetime_field_limit_get"

external field_limit_set : Evas.obj -> field_type -> int -> int -> unit =
  "ml_elm_datetime_field_limit_set"

