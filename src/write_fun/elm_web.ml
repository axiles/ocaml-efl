open Common

let window_features = simple_ty "Elm_Web" "Window_Features"
let window_feature_flag = simple_ty "Elm_Web" "Window_Feature_Flag"
let zoom_mode = simple_ty "Elm_Web" "Zoom_Mode"

let funs = [
  prop "useragent" safe_string;
  simple "webkit_view_get" [evas_object] evas_object;
  prop "tab_propagate" bool;
  simple "url_set" [evas_object; safe_string] bool;
  simple_unit "bg_color_set" [evas_object; int; int; int; int];
  simple_unit "popup_selected_set" [evas_object; int];
  simple "popup_destroy" [evas_object] bool;
  simple "text_matches_unmark_all" [evas_object] bool;
  simple "text_matches_highlight_get" [evas_object] bool;
  simple "text_matches_highlight_set" [evas_object; bool] bool;
  simple "load_progress_get" [evas_object] double;
  simple "stop" [evas_object] bool;
  simple "reload" [evas_object] bool;
  simple "reload_full" [evas_object] bool;
  simple "back" [evas_object] bool;
  simple "forward" [evas_object] bool;
  simple "navigate" [evas_object; int] bool;
  simple "back_possible_get" [evas_object] bool;
  simple "forward_possible_get" [evas_object] bool;
  simple "navigate_possible_get" [evas_object; int] bool;
  prop "history_enabled" bool;
  prop "zoom" double;
  prop "zoom_mode" zoom_mode;
  simple_unit "region_show" [evas_object; int; int; int; int];
  simple_unit "region_bring_in" [evas_object; int; int; int; int];
  prop "inwin_mode" bool;
  simple "window_features_property_get" [window_features; window_feature_flag]
    bool;
]

