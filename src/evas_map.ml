type t = Evas.map

external util_points_populate_from_object_full : t -> Evas.obj -> int -> unit =
  "ml_evas_map_util_points_populate_from_object_full"

external util_points_populate_from_object : t -> Evas.obj -> unit =
  "ml_evas_map_util_points_populate_from_object"

external util_points_populate_from_geometry :
  t -> int -> int -> int -> int -> int -> unit =
    "ml_evas_map_util_points_populate_from_geometry_byte"
    "ml_evas_map_util_points_populate_from_geometry_native"

external util_points_color_set : t -> int -> int -> int -> int -> unit =
  "ml_evas_map_util_points_color_set"

external util_rotate : t -> float -> int -> int -> unit =
  "ml_evas_map_util_rotate"

external util_zoom : t -> float -> float -> int -> int -> unit =
  "ml_evas_map_util_zoom"

external util_3d_rotate :
  t -> float -> float -> float -> int -> int -> int -> unit =
    "ml_evas_map_util_3d_rotate_byte"
    "ml_evas_map_util_3d_rotate_native"

external util_quat_rotate :
  t -> float -> float -> float -> float -> float -> float -> float -> unit =
    "ml_evas_map_util_quat_rotate_byte"
    "ml_evas_map_util_quat_rotate_native"

external util_3d_lighting :
  t -> int -> int -> int -> int -> int -> int -> int -> int -> int -> unit =
    "ml_evas_map_util_3d_lighting_byte"
    "ml_evas_map_util_3d_lighting_native"

external util_3d_perspective : t -> int -> int -> int -> int -> unit =
  "ml_evas_map_util_3d_perspective"

external util_clockwise_get : t -> bool = "ml_evas_map_util_clockwise_get"

external new_ : int -> t = "ml_evas_map_new"

