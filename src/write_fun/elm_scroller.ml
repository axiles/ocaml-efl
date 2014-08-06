open Common

let funs = [
  simple_unit "content_min_limit" [evas_object; bool; bool];
  simple_unit "region_show" [evas_object; int; int; int; int];
  simple_unit "policy_set"
    [evas_object; elm_scroller_policy; elm_scroller_policy];
  prop "single_direction" elm_scroller_single_direction;
  simple_unit "page_snap_set" [evas_object; bool; bool];
  simple_unit "bounce_set" [evas_object; bool; bool];
  simple_unit "page_relative_set" [evas_object; double; double];
  simple_unit "page_size_set" [evas_object; int; int];
  simple_unit "page_scroll_limit_set" [evas_object; int; int];
  simple_unit "page_show" [evas_object; int; int];
  simple_unit "page_bring_in" [evas_object; int; int];
  simple_unit "region_bring_in" [evas_object; int; int; int; int];
  prop "propagate_events" bool;
  simple_unit "gravity_set" [evas_object; double; double];
  prop_flags "movement_block" elm_scroller_movement_block;
]

