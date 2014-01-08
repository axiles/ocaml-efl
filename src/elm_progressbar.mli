(** elm_progressbar_* *)

(** The following function will not be interfaced:

elm_progressbar_unit_format_get

*)

val add : Evas.obj -> Evas.obj

val pulse_set : Evas.obj -> bool -> unit

val pulse_get : Evas.obj -> bool

val pulse : Evas.obj -> bool -> unit

val value_set : Evas.obj -> float -> unit

val value_get : Evas.obj -> float

val span_size_set : Evas.obj -> int -> unit

val span_size_get : Evas.obj -> int

val unit_format_set : Evas.obj -> (float -> string, unit, string) format -> unit

val unit_format_function_set : Evas.obj -> (float -> string) -> unit

val horizontal_set : Evas.obj -> bool -> unit

val horizontal_get : Evas.obj -> bool

val inverted_set : Evas.obj -> bool -> unit

val inverted_get : Evas.obj -> bool

module E : sig
  type u = Evas.Event_type.u
  val changed : u
end

