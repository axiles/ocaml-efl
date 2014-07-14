module HE = Henums.Elm_flip

type mode = HE.mode

type interaction = HE.interaction

type direction = HE.direction

external add : Evas.obj -> Evas.obj = "ml_elm_flip_add"

let addx = Elm_object.create_addx add

external front_visible_get : Evas.obj -> bool = "ml_elm_flip_front_visible_get"

external perspective_set : Evas.obj -> int -> int -> int -> unit =
  "ml_elm_flip_perspective_set"

external go : Evas.obj -> mode -> unit = "ml_elm_flip_go"

external go_to : Evas.obj -> bool -> mode -> unit = "ml_elm_flip_go_to"

external interaction_set : Evas.obj -> interaction -> unit =
  "ml_elm_flip_interaction_set"

external interaction_get : Evas.obj -> interaction =
  "ml_elm_flip_interaction_get"

external interaction_direction_enabled_set :
  Evas.obj -> direction -> bool -> unit =
    "ml_elm_flip_interaction_direction_enabled_set"

external interaction_direction_enabled_get : Evas.obj -> direction -> bool =
  "ml_elm_flip_interaction_direction_enabled_get"

external interaction_direction_hitsize_set :
  Evas.obj -> direction -> float -> unit =
    "ml_elm_flip_interaction_direction_hitsize_set"

external interaction_direction_hitsize_get : Evas.obj -> direction -> float =
  "ml_elm_flip_interaction_direction_hitsize_get"

