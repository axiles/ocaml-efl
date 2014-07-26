open Common

let funs = [
  simple_unit "clear" [evas_object];
  prop "multi_select" bool;
  prop "multi_select_mode" bool;
  prop "mode" elm_list_mode;
  prop ~args:[elm_object_item] "item_selected" bool;
  simple_unit "item_show" [elm_object_item; elm_genlist_item_scrollto_type];
  simple_unit "item_bring_in" [elm_object_item; elm_genlist_item_scrollto_type];
  simple_unit "item_update" [elm_object_item];
  simple "item_index_get" [elm_object_item] int;
  simple_unit "realized_items_update" [evas_object];
  simple "items_count" [evas_object] int;
  simple_unit "item_tooltip_text_set" [elm_object_item; safe_string];
  simple_unit "item_tooltip_unset" [elm_object_item];
  prop ~args:[elm_object_item] "item_tooltip_style" safe_string;
  prop ~args:[elm_object_item] "item_tooltip_window_mode" bool;
  simple_unit "item_cursor_set" [elm_object_item; safe_string];
  simple_unit "item_cursor_unset" [elm_object_item];
  simple_unit "item_cursor_style_set" [elm_object_item; safe_string];
  prop ~args:[elm_object_item] "item_cursor_engine_only" bool;
  prop "homogeneous" bool;
  prop "block_count" int;
  prop "longpress_timeout" double;
  simple_unit "item_subitems_clear" [elm_object_item];
  prop ~args:[elm_object_item] "item_expanded" bool;
  simple "item_expanded_depth_get" [elm_object_item] int;
  simple_unit "item_promote" [elm_object_item];
  simple_unit "item_demote" [elm_object_item];
  simple_unit "item_fields_update"
    [elm_object_item; safe_string; elm_genlist_item_field_type];
  simple_unit "item_decorate_mode_set" [elm_object_item; safe_string; bool];
  simple "item_decorate_mode_get" [elm_object_item] safe_string;
  prop "reorder_mode" bool;
  simple "item_type_get" [elm_object_item] elm_genlist_item_type;
  prop "decorate_mode" bool;
  prop ~args:[elm_object_item] "item_flip" bool;
  prop "tree_effect_enabled" bool;
  prop "select_mode" elm_object_select_mode;
  prop "highlight_mode" bool;
  prop ~args:[elm_object_item] "item_select_mode" elm_object_select_mode;
]


