open Common

let funs = [
  simple "file_set" [evas_object; safe_string] evas_load_error;
  prop "zoom" double;
  prop "zoom_mode" elm_photocam_zoom_mode;
  simple_unit "image_region_show" [evas_object; int; int; int; int];
  simple_unit "image_region_bring_in" [evas_object; int; int; int; int];
  prop "paused" bool;
  prop "gesture_enabled" bool;
]

