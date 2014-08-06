open Common

let funs = [
  prop "useragent" safe_string;
  simple "webkit_view_get" [evas_object] evas_object;
  prop "tab_propagate" bool;
  simple "url_set" [evas_object; safe_string] bool;
  simple_unit "bg_color_set" [evas_object; int; int; int; int];
  simple_unit "popup_selected_set" [evas_object; int];
  simple "popup_destroy" [evas_object] bool;
  simple "text_matches_unmark_all" [evas_object] bool;
  prop "text_matches_highlight" bool;
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
  prop "zoom_mode" elm_web_zoom_mode;
  simple_unit "region_show" [evas_object; int; int; int; int];
  simple_unit "region_bring_in" [evas_object; int; int; int; int];
  prop "inwin_mode" bool;
  simple "window_features_property_get"
    [elm_web_window_features; elm_web_window_feature_flag] bool;
]

