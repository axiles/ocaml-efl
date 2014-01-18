val add : Evas.obj -> Evas.obj

val label_format_function_set : Evas.obj -> (float -> string) -> unit

val label_format_set :
  Evas.obj -> (float -> string, unit, string) format -> unit

val min_max_set : Evas.obj -> float -> float -> unit

val min_max_get : Evas.obj -> float * float

val editable_set : Evas.obj -> bool -> unit

val special_value_add : Evas.obj -> float -> string -> unit

val value_get : Evas.obj -> float

