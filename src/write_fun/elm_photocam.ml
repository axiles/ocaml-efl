open Common

let zoom_mode = simple_ty "Elm_Photocam" "Zoom_Mode"

let funs = [
  simple "file_set" [evas_object; safe_string] evas_load_error;
  prop "zoom" double;
  prop "zoom_mode" zoom_mode;
(* BEGIN: 1.14 *)
  prop "image_orient" Elm_image.orient;
(* END *)
  simple_unit "image_region_show" [evas_object; int; int; int; int];
  simple_unit "image_region_bring_in" [evas_object; int; int; int; int];
  prop "paused" bool;
  prop "gesture_enabled" bool;
]

