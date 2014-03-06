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

external smooth_set : t -> bool -> unit = "ml_evas_map_smooth_set"

external smooth_get : t -> bool = "ml_evas_map_smooth_get"

external alpha_set : t -> bool -> unit = "ml_evas_map_alpha_set"

external alpha_get : t -> bool = "ml_evas_map_alpha_get"

external dup : t -> t = "ml_evas_map_dup"

external free : t -> unit = "ml_evas_map_free"

external count_get : t -> int = "ml_evas_map_count_get"

external point_coord_set : t -> int -> int -> int -> int -> unit =
  "ml_evas_map_point_coord_set"

external point_coord_get : t -> int -> int * int * int =
  "ml_evas_map_point_coord_get"

external point_image_uv_set : t -> int -> float -> float -> unit =
  "ml_evas_map_point_image_uv_set"

external point_image_uv_get : t -> int -> float * float =
  "ml_evas_map_point_image_uv_get"

external point_color_set : t -> int -> int -> int -> int -> int -> unit =
  "ml_evas_map_point_color_set_byte" "ml_evas_map_point_color_set_native"

external point_color_get : t -> int -> int * int * int * int =
  "ml_evas_map_point_color_get"

