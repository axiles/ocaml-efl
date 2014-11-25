open Common

let funs = [
  simple "file_set" [evas_object; safe_string] bool;
  simple_unit "size_set" [evas_object; int];
  simple_unit "fill_inside_set"  [evas_object; bool];
  simple_unit "editable_set" [evas_object; bool];
  prop "aspect_fixed" bool;
]

