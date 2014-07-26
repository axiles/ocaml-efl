open Common

let funs = [
  prop "line_wrap" elm_wrap_type;
  prop "wrap_width" int;
  prop "ellipsis" bool;
  prop "slide_mode" bool;
  prop "slide_duration" double;
  simple_unit "slide_go" [evas_object];
]

