open Common

let effect name list =
  simple_unit (Printf.sprintf "effect_%s_add" name) ([elm_transit] @ list)
let tween_mode = simple_ty "Elm_Transit" "Tween_Mode"
let effect_flip_axis = simple_ty "Elm_Transit" "Effect_Flip_Axis"
let effect_wipe_type = simple_ty "Elm_Transit" "Effect_Wipe_Type"
let effect_wipe_dir = simple_ty "Elm_Transit" "Effect_Wipe_Dir"

let funs = [
  simple_unit "del" [elm_transit];
  simple_unit "object_add" [elm_transit; evas_object];
  simple_unit "object_remove" [elm_transit; evas_object];
  prop ~args:[elm_transit] "objects_final_state_keep" bool;
  prop ~args:[elm_transit] "event_enabled" bool;
  prop ~args:[elm_transit] "auto_reverse" bool;
  prop ~args:[elm_transit] "repeat_times" int;
  prop ~args:[elm_transit] "tween_mode" tween_mode;
  simple_unit "tween_mode_factor_set" [elm_transit; double; double];
  prop ~args:[elm_transit] "duration" double;
  simple_unit "go" [elm_transit];
(* BEGIN: 1.14 *)
  simple_unit "go_in" [elm_transit; double];
(* END *)
  prop ~args:[elm_transit] "paused" bool;
  simple "progress_value_get" [elm_transit] double;
  simple_unit "chain_transit_add" [elm_transit; elm_transit];
  simple_unit "chain_transit_del" [elm_transit; elm_transit];
  prop ~args:[elm_transit] "smooth" bool;
  effect "resizing" [int; int; int; int];
  effect "translation" [int; int; int; int];
  effect "zoom" [double; double];
  effect "flip" [effect_flip_axis; bool];
  effect "resizable_flip" [effect_flip_axis; bool];
  effect "wipe" [effect_wipe_type; effect_wipe_dir];
  effect "color" [int; int; int; int; int; int; int; int];
  effect "fade" [];
  effect "blend" [];
  effect "rotation" [double; double]
]

