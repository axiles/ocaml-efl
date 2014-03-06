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

val smooth_set : t -> bool -> unit

val smooth_get : t -> bool

val alpha_set : t -> bool -> unit

val alpha_get : t -> bool

val dup : t -> t

val free : t -> unit

val count_get : t -> int

val point_coord_set : t -> int -> int -> int -> int -> unit

val point_coord_get : t -> int -> int * int * int

val point_image_uv_set : t -> int -> float -> float -> unit

val point_image_uv_get : t -> int -> float * float

