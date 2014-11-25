include Henums.Elm_datetime
module AF = Autofun.Elm_datetime.F (struct
  type evas_object = Evas.obj
  type elm_datetime_field_type = field_type
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_datetime_add"

let addx = Elm_object.create_addx add

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

external value_get : Evas.obj -> Unix.tm option = "ml_elm_datetime_value_get"

external value_set : Evas.obj -> Unix.tm -> bool = "ml_elm_datetime_value_set"

