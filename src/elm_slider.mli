(** elm_slider_* *)

val add : Evas.obj -> Evas.obj

val span_size_set : Evas.obj -> int -> unit

val span_size_get : Evas.obj -> int

val unit_format_set : Evas.obj -> (float -> string, unit, string) format -> unit

val indicator_format_set :
  Evas.obj -> (float -> string, unit, string) format -> unit

val indicator_format_function_set : Evas.obj -> (float -> string) -> unit

val unit_format_function_set : Evas.obj -> (float -> string) -> unit

val horizontal_set : Evas.obj -> bool -> unit

val horizontal_get : Evas.obj -> bool

val min_max_set : Evas.obj -> float -> float -> unit

val min_max_get : Evas.obj -> float * float

val value_set : Evas.obj -> float -> unit

val value_get : Evas.obj -> float

val inverted_set : Evas.obj -> bool -> unit

val inverted_get : Evas.obj -> bool

val indicator_show_set : Evas.obj -> bool -> unit

val indicator_show_get : Evas.obj -> bool

module E : sig
  type u = Evas.Event_type.u
  val changed : u
  val slider_drag_start : u
  val slider_drag_stop : u
  val delay_changed : u
  val focused : u
  val unfocused : u
end

