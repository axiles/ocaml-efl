include Henums.Ecore_animator

type t = Ecore.animator

module AF = Autofun.Ecore_animator.F (struct
  type ecore_pos_map = Ecore.pos_map
  type ecore_animator = t
  type ecore_animator_source = source
end)
include AF

external pos_map_list : float -> Ecore.pos_map -> float list -> float =
  "ml_ecore_animator_pos_map_list"

external custom_source_tick_begin_callback_set : Ecore.cb -> unit =
  "ml_ecore_animator_custom_source_tick_begin_callback_set"

external custom_source_tick_end_callback_set : Ecore.cb -> unit =
  "ml_ecore_animator_custom_source_tick_end_callback_set"

external add : Ecore.task_cb -> t = "ml_ecore_animator_add"

let timeline_add runtime f =
  if runtime <= 0. then invalid_arg "ecore_animator_timeline_add"
  else
  let start = Ecore.time_get () in
  let g () =
    let current = Ecore.time_get () in
    let x = (current -. start) /. runtime in
    if x > 1. then false
    else f ((current -. start) /. runtime) in
  try add g with Failure "ecore_animator_add" ->
    failwith "ecore_animator_timeline_add"

external del : t -> unit = "ml_ecore_animator_del"

