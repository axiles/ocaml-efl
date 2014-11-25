open Common

let resize_policy = simple_ty "Elm_GLView" "Resize_Policy"
let render_policy = simple_ty "Elm_GLView" "Render_Policy"

let funs = [
  simple_unit "size_set" [evas_object; int; int];
  simple "resize_policy_set" [evas_object; resize_policy] bool;
  simple "render_policy_set" [evas_object; render_policy] bool;
  simple_unit "changed_set" [evas_object]
]

