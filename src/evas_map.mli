(** UV Mapping *)

type t = Evas.map

val util_points_populate_from_object_full : t -> Evas.obj -> int -> unit

val util_points_populate_from_object : t -> Evas.obj -> unit

val util_points_populate_from_geometry :
  t -> int -> int -> int -> int -> int -> unit

val util_points_color_set : t -> int -> int -> int -> int -> unit

val util_rotate : t -> float -> int -> int -> unit

val util_zoom : t -> float -> float -> int -> int -> unit

val util_3d_rotate : t -> float -> float -> float -> int -> int -> int -> unit

val util_quat_rotate :
  t -> float -> float -> float -> float -> float -> float -> float -> unit

val util_3d_lighting :
  t -> int -> int -> int -> int -> int -> int -> int -> int -> int -> unit

val util_3d_perspective : t -> int -> int -> int -> int -> unit

val util_clockwise_get : t -> bool

val new_ : int -> t

