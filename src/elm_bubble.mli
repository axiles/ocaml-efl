(** Bubble *)

type pos = [`invalid | `top_left | `top_right | `bottom_left | `bottom_right]

val add : Evas.obj -> Evas.obj

val addx : Elm_object.t_addx

val pos_set : Evas.obj -> pos -> unit

val pos_get : Evas.obj -> pos

