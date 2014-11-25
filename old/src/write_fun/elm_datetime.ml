open Common

let field_type = simple_ty "Elm_Datetime" "Field_Type"

let funs = [
  prop "format" safe_string;
  simple_unit "field_limit_set" [evas_object; field_type; int; int];
  prop ~args:[evas_object; field_type] "field_visible" bool;
]

