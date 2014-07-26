open Common

let direction = elm_flip_direction

let funs = [
  simple "front_visible_get" [evas_object] bool;
  simple_unit "perspective_set" [evas_object; int; int; int];
  simple_unit "go" [evas_object; elm_flip_mode];
  simple_unit "go_to" [evas_object; bool; elm_flip_mode];
  prop "interaction" elm_flip_interaction;
  prop ~args:[evas_object; direction] "interaction_direction_enabled" bool;
  prop ~args:[evas_object; direction] "interaction_direction_hitsize" double;
]

