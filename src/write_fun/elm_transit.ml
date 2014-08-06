open Common

let effect name list =
  simple_unit (Printf.sprintf "effect_%s_add" name) ([elm_transit] @ list)

let funs = [
  simple_unit "del" [elm_transit];
  simple_unit "object_add" [elm_transit; evas_object];
  simple_unit "object_remove" [elm_transit; evas_object];
  prop ~args:[elm_transit] "objects_final_state_keep" bool;
  prop ~args:[elm_transit] "event_enabled" bool;
  prop ~args:[elm_transit] "auto_reverse" bool;
  prop ~args:[elm_transit] "repeat_times" int;
  prop ~args:[elm_transit] "tween_mode" elm_transit_tween_mode;
  simple_unit "tween_mode_factor_set" [elm_transit; double; double];
  prop ~args:[elm_transit] "duration" double;
  simple_unit "go" [elm_transit];
  prop ~args:[elm_transit] "paused" bool;
  simple "progress_value_get" [elm_transit] double;
  simple_unit "chain_transit_add" [elm_transit; elm_transit];
  simple_unit "chain_transit_del" [elm_transit; elm_transit];
  prop ~args:[elm_transit] "smooth" bool;
  effect "resizing" [int; int; int; int];
  effect "translation" [int; int; int; int];
  effect "zoom" [double; double];
  effect "flip" [ elm_transit_effect_flip_axis; bool];
  effect "resizable_flip" [elm_transit_effect_flip_axis; bool];
  effect "wipe" [elm_transit_effect_wipe_type; elm_transit_effect_wipe_dir];
  effect "color" [int; int; int; int; int; int; int; int];
  effect "fade" [];
  effect "blend" [];
  effect "rotation" [double; double]
]

