type t = Elm.transit

external add : unit -> t = "ml_elm_transit_add"

external del : t -> unit = "ml_elm_transit_del"

external effect_add : t -> (t -> float -> unit) -> unit =
  "ml_elm_transit_effect_add"

