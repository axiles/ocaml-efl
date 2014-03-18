type field_type = [`year | `month | `date | `hour | `minute | `ampm]

external add : Evas.obj -> Evas.obj = "ml_elm_datetime_add"

let addx = Elm_object.create_addx add

external format_get : Evas.obj -> string = "ml_elm_datetime_format_get"

external format_set : Evas.obj -> string -> unit = "ml_elm_datetime_format_set"

external value_max_get : Evas.obj -> Unix.tm option =
  "ml_elm_datetime_value_max_get"

external value_max_set : Evas.obj -> Unix.tm -> bool =
  "ml_elm_datetime_value_max_set"

external value_min_get : Evas.obj -> Unix.tm option =
  "ml_elm_datetime_value_min_get"

external value_min_set : Evas.obj -> Unix.tm -> bool =
  "ml_elm_datetime_value_min_set"

external field_limit_get : Evas.obj -> field_type -> int * int =
  "ml_elm_datetime_field_limit_get"

external field_limit_set : Evas.obj -> field_type -> int -> int -> unit =
  "ml_elm_datetime_field_limit_set"

external value_get : Evas.obj -> Unix.tm option = "ml_elm_datetime_value_get"

external value_set : Evas.obj -> Unix.tm -> bool = "ml_elm_datetime_value_set"

external field_visible_get : Evas.obj -> field_type -> bool =
  "ml_elm_datetime_field_visible_get"

external field_visible_set : Evas.obj -> field_type -> bool -> unit =
  "ml_elm_datetime_field_visible_set"

