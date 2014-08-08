open Common

let funs = [
  simple_unit "text_style_user_push" [evas_object; safe_string];
  simple_unit "text_style_user_pop" [evas_object];
  prop "single_line" bool;
  prop "password" bool;
  prop "entry" safe_string;
  simple_unit "entry_append" [evas_object; safe_string];
  simple "is_empty" [evas_object] bool;
  simple "textblock_get" [evas_object] evas_object;
  simple_unit "calc_force" [evas_object];
  simple_unit "entry_insert" [evas_object; safe_string];
  prop "line_wrap" elm_wrap_type;
  prop "editable" bool;
  simple_unit "select_none" [evas_object];
  simple_unit "select_all" [evas_object];
  simple_unit "select_region_set" [evas_object; int; int];
  simple "cursor_next" [evas_object] bool;
  simple "cursor_prev" [evas_object] bool;
  simple "cursor_up" [evas_object] bool;
  simple "cursor_down" [evas_object] bool;
  simple_unit "cursor_begin_set" [evas_object];
  simple_unit "cursor_end_set" [evas_object];
  simple_unit "cursor_line_begin_set" [evas_object];
  simple_unit "cursor_line_end_set" [evas_object];
  simple_unit "cursor_selection_begin" [evas_object];
  simple_unit "cursor_selection_end" [evas_object];
  simple "cursor_is_format_get" [evas_object] bool;
  simple "cursor_is_visible_format_get" [evas_object] bool;
  prop "cursor_pos" int;
  simple_unit "selection_cut" [evas_object];
  simple_unit "selection_copy" [evas_object];
  simple_unit "selection_paste" [evas_object];
  simple_unit "context_menu_clear" [evas_object];
  prop "context_menu_disabled" bool;
  simple "markup_to_utf8" [safe_string] safe_string_free;
  simple "utf8_to_markup" [safe_string] safe_string_free;
  simple "file_set" [evas_object; safe_string; elm_text_format] bool;
  simple_unit "file_save" [evas_object];
  prop "autosave" bool;
  prop "scrollable" bool;
  simple_unit "icon_visible_set" [evas_object; bool];
  simple_unit "end_visible_set" [evas_object; bool];
  prop "input_panel_layout" elm_input_panel_layout;
  prop "autocapital_type" elm_autocapital_type;
  prop "input_panel_enabled" bool;
  simple_unit "input_panel_show" [evas_object];
  simple_unit "input_panel_hide" [evas_object];
  prop "input_panel_language" elm_input_panel_lang;
  prop "input_panel_return_key_type" elm_input_panel_return_key_type;
  prop "input_panel_return_key_disabled" bool;
  simple_unit "input_panel_return_key_autoenabled_set" [evas_object; bool];
  simple_unit "imf_context_reset" [evas_object];
  prop "prediction_allow" bool;
  prop "cnp_mode" elm_cnp_mode;
  simple_unit "anchor_hover_parent_set" [evas_object; evas_object];
  prop "anchor_hover_style" safe_string;
  simple_unit "anchor_hover_end" [evas_object];
  prop "input_panel_layout_variation" int;
  prop "input_panel_show_on_demand" bool;
]



