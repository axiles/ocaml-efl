(*type pos = [`invalid | `top_left | `top_right | `bottom_left | `bottom_right]
 *)

type pos = Henums.Elm_bubble.pos

external add : Evas.obj -> Evas.obj = "ml_elm_bubble_add"

let addx = Elm_object.create_addx add

external pos_set : Evas.obj -> pos -> unit = "ml_elm_bubble_pos_set"

external pos_get : Evas.obj -> pos = "ml_elm_bubble_pos_get"

