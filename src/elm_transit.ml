include Henums.Elm_transit

type t = Elm.transit

module AF = Autofun.Elm_transit.F (struct
  type elm_transit = t
  type evas_object = Evas.obj
  type elm_transit_tween_mode = tween_mode
  type elm_transit_effect_flip_axis = effect_flip_axis
  type elm_transit_effect_wipe_type = effect_wipe_type
  type elm_transit_effect_wipe_dir = effect_wipe_dir
end)
include AF

external add : unit -> t = "ml_elm_transit_add"

external effect_add : t -> (t -> float -> unit) -> unit =
  "ml_elm_transit_effect_add"

external objects_get : t -> Evas.obj list = "ml_elm_transit_objects_get"

external del_cb_set : t -> (t -> unit) -> unit = "ml_elm_transit_del_cb_set"

external tween_mode_factor_get : t -> float * float =
  "ml_elm_transit_tween_mode_factor_get"

external chain_transits_get : t -> t list = "ml_elm_transit_chain_transits_get"

external effect_image_animation_add : t -> string list -> unit =
  "ml_elm_transit_effect_image_animation_add"

