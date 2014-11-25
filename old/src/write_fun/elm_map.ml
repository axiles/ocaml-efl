open Common

let overlay = simple_ty ~ptr:true "Elm_Map" "Overlay"
let route = simple_ty ~ptr:true "Elm_Map" "Route"
let name = simple_ty ~ptr:true "Elm_Map" "Name"
let zoom_mode = simple_ty "Elm_Map" "Zoom_Mode"
let overlay_type = simple_ty "Elm_Map" "Overlay_Type"
let source_type = simple_ty "Elm_Map" "Source_Type"

let funs = [
  prop "zoom" int;
  prop "zoom_mode" zoom_mode;
  prop "zoom_min" int;
  prop "zoom_max" int;
  simple_unit "region_bring_in" [evas_object; double; double];
  simple_unit "region_show" [evas_object; double; double];
  prop "paused" bool;
  simple_unit "rotate_set" [evas_object; double; int; int];
  prop "wheel_disabled" bool;
  prop "user_agent" safe_string;
  simple_unit "overlay_del" [overlay];
  simple "overlay_type_get" [overlay] overlay_type;
  prop ~args:[overlay] "overlay_hide" bool;
  prop ~args:[overlay] "overlay_displayed_zoom_min" int;
  prop ~args:[overlay] "overlay_paused" bool;
  simple "overlay_visible_get" [overlay] bool;
  simple_unit "overlay_region_set" [overlay; double; double];
  simple_unit "overlay_color_set" [overlay; int; int; int; int];
  simple_unit "overlay_show" [overlay];
  simple_unit "overlay_class_append" [overlay; overlay];
  simple_unit "overlay_class_remove" [overlay; overlay];
  prop ~args:[overlay] "overlay_class_zoom_max" int;
  simple_unit "overlay_bubble_follow" [overlay; overlay];
  simple_unit "overlay_bubble_content_append" [overlay; evas_object];
  simple_unit "overlay_bubble_content_clear" [overlay];
  simple_unit "overlay_polygon_region_add" [overlay; double; double];
  prop ~args:[evas_object; source_type] "source" safe_string;
  simple_unit "route_del" [route];
  simple "route_distance_get" [route] double;
  simple "route_node_get" [route] safe_string;
  simple "route_waypoint_get" [route] safe_string;
  simple "name_address_get" [name] safe_string;
  simple_unit "name_del" [name];
  simple_unit "track_remove" [evas_object; evas_object]
]

