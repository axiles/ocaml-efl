open Common

let funs = [
  prop "horizontal" bool;
  prop "homogeneous" bool;
  simple_unit "pack_start" [evas_object; evas_object];
  simple_unit "pack_end" [evas_object; evas_object];
  simple_unit "pack_before" [evas_object; evas_object; evas_object];
  simple_unit "pack_after" [evas_object; evas_object; evas_object];
  simple_unit "clear" [evas_object];
  simple_unit "unpack" [evas_object; evas_object];
  simple_unit "unpack_all" [evas_object];
  simple_unit "padding_set" [evas_object; int; int];
  simple_unit "align_set" [evas_object; double; double];
  simple_unit "recalculate" [evas_object];
]

