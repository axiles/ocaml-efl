val add : Evas.obj -> Evas.obj

val unit_format_set : Evas.obj -> (float -> string, unit, string) format -> unit

val indicator_format_set :
  Evas.obj -> (float -> string, unit, string) format -> unit

val indicator_format_function_set : Evas.obj -> (float -> string) -> unit

val unit_format_function_set : Evas.obj -> (float -> string) -> unit

val horizontal_set : Evas.obj -> bool -> unit

val horizontal_get : Evas.obj -> bool

val value_set : Evas.obj -> float -> unit

val value_get : Evas.obj -> float

