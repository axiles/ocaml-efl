open Common

let funs = [
  simple_unit "item_del_at" [evas_object; int];
  simple "item_count_get" [evas_object] int;
  simple "item_index_get" [elm_object_item] int;
  simple "item_object_get" [elm_object_item] evas_object;
  simple_unit "item_selected_set" [elm_object_item; bool];
]

