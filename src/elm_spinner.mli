(** Spinner *)

val add : Evas.obj -> Evas.obj

val addx : Elm_object.t_addx

val label_format_function_set : Evas.obj -> (float -> string) -> unit

val label_format_set :
  Evas.obj -> (float -> string, unit, string) format -> unit

val min_max_set : Evas.obj -> float -> float -> unit

val min_max_get : Evas.obj -> float * float

val step_set : Evas.obj -> float -> unit

val step_get : Evas.obj -> float

val value_set : Evas.obj -> float -> unit

val value_get : Evas.obj -> float

val wrap_set : Evas.obj -> bool -> unit

val wrap_get : Evas.obj -> bool

val editable_set : Evas.obj -> bool -> unit

val editable_get : Evas.obj -> bool

val special_value_add : Evas.obj -> float -> string -> unit

val interval_set : Evas.obj -> float -> unit

val interval_get : Evas.obj -> float

val base_set : Evas.obj -> float -> unit

val base_get : Evas.obj -> float

val round_set : Evas.obj -> int -> unit

val round_get : Evas.obj -> int

