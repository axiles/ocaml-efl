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

