(** elm_bubble_* Elm_Bubble_* ELM_BUBBLE_* *)

type pos = [`invalid | `top_left | `top_right | `bottom_left | `bottom_right]

val add : Evas.obj -> Evas.obj

val pos_set : Evas.obj -> pos -> unit

val pos_get : Evas.obj -> pos

