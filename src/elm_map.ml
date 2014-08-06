include Henums.Elm_map

type overlay

type overlay_get_cb = Evas.obj -> overlay -> unit

type route

type route_cb = Evas.obj -> route -> unit

type name

type name_cb = Evas.obj -> name -> unit

module AF = Autofun.Elm_map.F (struct
  type evas_object = Evas.obj
  type elm_map_overlay = overlay
  type elm_map_route = route
  type elm_map_name = name
  type elm_map_zoom_mode = zoom_mode
  type elm_map_source_type = source_type
  type elm_map_overlay_type = overlay_type
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_map_add"

let addx = Elm_object.create_addx add

external region_get : Evas.obj -> float * float = "ml_elm_map_region_get"

external canvas_to_region_convert : Evas.obj -> int -> int -> float * float =
  "ml_elm_map_canvas_to_region_convert"

external region_to_canvas_convert : Evas.obj -> float -> float -> int * int =
  "ml_elm_map_region_to_canvas_convert"

external rotate_get : Evas.obj -> float * int * int = "ml_elm_map_rotate_get"

external overlay_add : Evas.obj -> float -> float -> overlay =
  "ml_elm_map_overlay_add"

external overlays_get : Evas.obj -> overlay list = "ml_elm_map_overlays_get"

external overlay_content_set : overlay -> Evas.obj option -> unit =
  "ml_elm_map_overlay_content_set"

external overlay_content_get : overlay -> Evas.obj option =
  "ml_elm_map_overlay_content_get"

external overlay_icon_set : overlay -> Evas.obj option -> unit =
  "ml_elm_map_overlay_icon_set"

external overlay_icon_get : overlay -> Evas.obj option =
  "ml_elm_map_overlay_icon_get"

external overlay_region_get : overlay -> float * float =
  "ml_elm_map_overlay_region_get"

external overlay_color_get : overlay -> int * int * int * int =
  "ml_elm_map_overlay_color_get"

external overlays_show : overlay list -> unit = "ml_elm_map_overlays_show"

external overlay_get_cb_set : overlay -> overlay_get_cb -> unit =
  "ml_elm_map_overlay_get_cb_set"

external overlay_class_add : Evas.obj -> overlay =
  "ml_elm_map_overlay_class_add"

external overlay_group_members_get : overlay -> overlay list =
  "ml_elm_map_overlay_group_members_get"

external overlay_bubble_add : Evas.obj -> overlay =
  "ml_elm_map_overlay_bubble_add"

external overlay_route_add : Evas.obj -> route -> overlay =
  "ml_elm_map_overlay_route_add"

external overlay_line_add :
  Evas.obj -> float -> float -> float -> float -> overlay =
    "ml_elm_map_overlay_line_add"

external overlay_polygon_add : Evas.obj -> overlay =
  "ml_elm_map_overlay_polygon_add"

external overlay_polygon_region_add : overlay -> float -> float -> unit =
  "ml_elm_map_overlay_polygon_region_add"

external overlay_circle_add : Evas.obj -> float -> float -> float -> overlay =
  "ml_elm_map_overlay_circle_add"

external overlay_scale_add : Evas.obj -> int -> int -> overlay =
  "ml_elm_map_overlay_scale_add"

external tile_load_status_get : Evas.obj -> int * int =
  "ml_elm_map_tile_load_status_get"

external sources_get : Evas.obj -> source_type -> string list =
  "ml_elm_map_sources_get"

external route_add :
  Evas.obj -> route_type -> route_method -> float -> float -> float -> float ->
    route_cb -> route =
      "ml_elm_map_route_add_bytecode"
      "ml_elm_map_route_add_native"

external name_add :
  Evas.obj -> ?addr:string -> ?lon:float -> ?lat:float -> ?cb:name_cb -> unit ->
    name =
      "ml_elm_map_name_add_bytecode"
      "ml_elm_map_name_add_native"

external name_region_get : name -> float * float = "ml_elm_map_name_region_get"

external track_add : Evas.obj -> route -> Evas.obj = "ml_elm_map_track_add"

