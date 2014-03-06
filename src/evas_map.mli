(** UV Mapping *)

type t = Evas.map

val util_points_populate_from_object_full : t -> Evas.obj -> int -> unit

val util_points_populate_from_object : t -> Evas.obj -> unit

val util_points_populate_from_geometry :
  t -> int -> int -> int -> int -> int -> unit

