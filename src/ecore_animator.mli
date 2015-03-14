(** Ecore Animator *)

type t = Ecore.animator

type source = [`timer | `custom]

val frametime_set : float -> unit

val frametime_get : unit -> float

val pos_map : float -> Ecore.pos_map -> float -> float -> float

val pos_map_list : float -> Ecore.pos_map -> float list -> float

val source_set : source -> unit

val source_get : unit -> source

val custom_source_tick_begin_callback_set : Ecore.cb -> unit

val custom_source_tick_end_callback_set : Ecore.cb -> unit

val custom_tick : unit -> unit

val add : Ecore.task_cb -> t

val timeline_add : float -> Ecore.timeline_cb -> t

val del : t -> unit

val freeze : t -> unit

val thaw : t -> unit

