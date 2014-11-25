open Common

let mode = simple_ty "Elm_Flip" "Mode"
let interaction = simple_ty "Elm_Flip" "Interaction"
let direction = simple_ty "Elm_Flip" "Direction"

let funs = [
  simple "front_visible_get" [evas_object] bool;
  simple_unit "perspective_set" [evas_object; int; int; int];
  simple_unit "go" [evas_object; mode];
  simple_unit "go_to" [evas_object; bool; mode];
  prop "interaction" interaction;
  prop ~args:[evas_object; direction] "interaction_direction_enabled" bool;
  prop ~args:[evas_object; direction] "interaction_direction_hitsize" double;
]

