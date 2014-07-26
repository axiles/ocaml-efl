open Common

let field_type = elm_datetime_field_type

let funs = [
  prop "format" safe_string;
  simple_unit "field_limit_set" [evas_object; field_type; int; int];
  prop ~args:[evas_object; elm_datetime_field_type] "field_visible" bool;
]

