open Common

let funs = [
  prop "line_min_length" int;
  prop "zoom_distance_tolerance" int;
  prop "line_distance_tolerance" int;
  prop "line_angular_tolerance" double;
  prop "zoom_wheel_factor" double;
  prop "zoom_finger_factor" double;
  prop "rotate_angular_tolerance" double;
  prop "flick_time_limit_ms" int;
  prop "long_tap_start_timeout" double;
  prop "continues_enable" bool;
  prop "double_tap_timeout" double;
  prop "tap_finger_size" int;
  prop "hold_events" bool;
  prop "zoom_step" double;
  prop "rotate_step" double;
  simple "attach" [evas_object; evas_object] bool;
]

