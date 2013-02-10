type format =
  | Hidden
  | Unit of (unit, unit, unit) Pervasives.format
  | Float of (float -> unit, unit, unit) Pervasives.format

val add : Evas.obj -> Evas.obj

val pulse_set : Evas.obj -> bool -> unit

val pulse_get : Evas.obj -> bool

val pulse : Evas.obj -> bool -> unit

val value_set : Evas.obj -> float -> unit

val value_get : Evas.obj -> float

val span_size_set : Evas.obj -> int -> unit

val span_size_get : Evas.obj -> int

val unit_format_set : Evas.obj -> format -> unit

