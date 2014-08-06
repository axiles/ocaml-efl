open Common

let funs = [
  simple_unit "resize_object_add" [evas_object; evas_object];
  simple_unit "resize_object_del" [evas_object; evas_object];
  prop "title" safe_string;
  prop "icon_name" safe_string;
  prop "role" safe_string;
  prop "autodel" bool;
  simple_unit "activate" [evas_object];
  simple_unit "lower" [evas_object];
  simple_unit "raise" [evas_object];
  simple_unit "center" [evas_object; bool; bool];
  prop "borderless" bool;
  prop "shaped" bool;
  prop "alpha" bool;
  prop "override" bool;
  prop "fullscreen" bool;
  prop "maximized" bool;
  prop "iconified" bool;
  prop "withdrawn" bool;
  prop "profile" safe_string;
  prop "urgent" bool;
  prop "demand_attention" bool;
  prop "modal" bool;
  prop "aspect" double;
  simple_unit "size_base_set" [evas_object; int; int];
  simple_unit "size_step_set" [evas_object; int; int];
  prop "layer" int;
  simple_unit "norender_push" [evas_object];
  simple_unit "norender_pop" [evas_object];
  simple "norender_get" [evas_object] int;
  simple_unit "render" [evas_object];
  prop "rotation" int;
  simple "wm_rotation_supported_get" [evas_object] bool;
  simple_unit "rotation_with_resize_set" [evas_object; int];
  prop "sticky" bool;
  prop "conformant" bool;
  prop "quickpanel" bool;
  prop "quickpanel_priority_major" int;
  prop "quickpanel_priority_minor" int;
  prop "quickpanel_zone" int;
  simple_unit "prop_focus_skip_set" [evas_object; bool];
  simple "inlined_image_object_get" [evas_object] evas_object;
  simple "focus_get" [evas_object] bool;
  prop "screen_constrain" bool;
  prop "focus_highlight_enabled" bool;
  prop "focus_highlight_animate" bool;
  prop "keyboard_mode" elm_win_keyboard_mode;
  prop "keyboard_win" bool;
  prop "indicator_mode" elm_win_indicator_mode;
  prop "indicator_opacity" elm_win_indicator_opacity_mode;
  simple_unit "socket_listen" [evas_object; safe_string; int; bool];
  prop "floating_mode" bool;
]

