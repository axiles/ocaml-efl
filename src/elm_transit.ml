type t = Elm.transit

type tween_mode = [
  | `linear
  | `sinusoidal
  | `decelerate
  | `accelerate]

type effect_flip_axis = [`x | `y]

type effect_wipe_type = [`hide | `show]

type effect_wipe_dir = [`left | `right | `up | `down]

external add : unit -> t = "ml_elm_transit_add"

external del : t -> unit = "ml_elm_transit_del"

external effect_add : t -> (t -> float -> unit) -> unit =
  "ml_elm_transit_effect_add"

external object_add : t -> Evas.obj -> unit = "ml_elm_transit_object_add"

external object_remove : t -> Evas.obj -> unit = "ml_elm_transit_object_remove"

external objects_get : t -> Evas.obj list = "ml_elm_transit_objects_get"

external objects_final_state_keep_set : t -> bool -> unit =
  "ml_elm_transit_objects_final_state_keep_set"

external objects_final_state_keep_get : t -> bool =
  "ml_elm_transit_objects_final_state_keep_get"

external event_enabled_set : t -> bool -> unit =
  "ml_elm_transit_event_enabled_set"

external event_enabled_get : t -> bool = "ml_elm_transit_event_enabled_get"

external del_cb_set : t -> (t -> unit) -> unit = "ml_elm_transit_del_cb_set"

external auto_reverse_set : t -> bool -> unit =
  "ml_elm_transit_auto_reverse_set"

external auto_reverse_get : t -> bool = "ml_elm_transit_auto_reverse_get"

external repeat_times_set : t -> int -> unit = "ml_elm_transit_repeat_times_set"

external repeat_times_get : t -> int = "ml_elm_transit_repeat_times_get"

external tween_mode_set : t -> tween_mode -> unit =
  "ml_elm_transit_tween_mode_set"

external tween_mode_get : t -> tween_mode = "ml_elm_transit_tween_mode_get"

external tween_mode_factor_set : t  -> float -> float -> unit =
  "ml_elm_transit_tween_mode_factor_set"

external tween_mode_factor_get : t -> float * float =
  "ml_elm_transit_tween_mode_factor_get"

external duration_set : t -> float -> unit = "ml_elm_transit_duration_set"

external duration_get : t -> float = "ml_elm_transit_duration_get"

external go : t -> unit = "ml_elm_transit_go"

external paused_set : t -> bool -> unit = "ml_elm_transit_paused_set"

external paused_get : t -> bool = "ml_elm_transit_paused_get"

external progress_value_get : t -> float = "ml_elm_transit_progress_value_get"

external chain_transit_add : t -> t -> unit = "ml_elm_transit_chain_transit_add"

external chain_transit_del : t -> t -> unit = "ml_elm_transit_chain_transit_del"

external chain_transits_get : t -> t list = "ml_elm_transit_chain_transits_get"

external smooth_set : t -> bool -> unit = "ml_elm_transit_smooth_set"

external smooth_get : t -> bool = "ml_elm_transit_smooth_get"

external effect_resizing_add : t -> int -> int -> int -> int -> unit =
  "ml_elm_transit_effect_resizing_add"

external effect_translation_add : t -> int -> int -> int -> int -> unit =
  "ml_elm_transit_effect_translation_add"

external effect_zoom_add : t -> float -> float -> unit =
  "ml_elm_transit_effect_zoom_add"

external effect_flip_add : t -> effect_flip_axis -> bool -> unit =
  "ml_elm_transit_effect_flip_add"

external effect_resizable_flip_add : t -> effect_flip_axis -> bool -> unit =
    "ml_elm_transit_effect_resizable_flip_add"

external effect_wipe_add : t -> effect_wipe_type -> effect_wipe_dir -> unit =
    "ml_elm_transit_effect_wipe_add"

external effect_color_add :
  t -> int -> int -> int -> int -> int -> int -> int -> int -> unit =
   "ml_elm_transit_effect_color_add_bytecode"
   "ml_elm_transit_effect_color_add_native"

external effect_fade_add : t -> unit = "ml_elm_transit_effect_fade_add"

external effect_blend_add : t -> unit = "ml_elm_transit_effect_blend_add"

external effect_rotation_add : t -> float -> float -> unit =
  "ml_elm_transit_effect_rotation_add"

external effect_image_animation_add : t -> string list -> unit =
  "ml_elm_transit_effect_image_animation_add"

