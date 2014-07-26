open Common

let funs = [
  simple_unit "size_set" [evas_object; int; int];
  simple "resize_policy_set" [evas_object; elm_glview_resize_policy] bool;
  simple "render_policy_set" [evas_object; elm_glview_render_policy] bool;
  simple_unit "changed_set" [evas_object]
]

