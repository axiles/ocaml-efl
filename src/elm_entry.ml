type anchor_info = {
  name : string;
  button : int;
  x : int;
  y : int;
  w : int;
  h : int;
}

type anchor_hover_info = {
  anchor_info : anchor_info;
  hover : Evas.obj;
  hover_left : bool;
  hover_right : bool;
  hover_top : bool;
  hover_bottom : bool;
}

type item_provider_cb = Evas.obj -> string -> Evas.obj option

type filter_cb = Evas.obj -> string -> string option

type change_info

type filter_limit_size = {
  mutable max_char_count : int;
  mutable max_byte_count : int
}

type filter_accept_set = {mutable accepted : string; mutable rejected : string}

type text_format = Elm.text_format

type wrap_type = Elm.wrap_type

type input_panel_layout = Elm.input_panel_layout

type input_panel_lang = Elm.input_panel_lang

type autocapital_type = Elm.autocapital_type

type input_panel_return_key_type = Elm.input_panel_return_key_type

type cnp_mode = Elm.cnp_mode

external add : Evas.obj -> Evas.obj = "ml_elm_entry_add"

external text_style_user_push : Evas.obj -> string -> unit =
  "ml_elm_entry_text_style_user_push"

external text_style_user_pop : Evas.obj -> unit =
  "ml_elm_entry_text_style_user_pop"

external text_style_user_peek : Evas.obj -> string option =
  "ml_elm_entry_text_style_user_peek"

external single_line_set : Evas.obj -> bool -> unit =
  "ml_elm_entry_single_line_set"

external single_line_get : Evas.obj -> bool = "ml_elm_entry_single_line_get"

external password_set : Evas.obj -> bool -> unit = "ml_elm_entry_password_set"

external password_get : Evas.obj -> bool = "ml_elm_entry_password_get"

external entry_set : Evas.obj -> string -> unit = "ml_elm_entry_entry_set"

external entry_get : Evas.obj -> string = "ml_elm_entry_entry_get"

external entry_append : Evas.obj -> string -> unit = "ml_elm_entry_entry_append"

external is_empty : Evas.obj -> bool = "ml_elm_entry_is_empty"

external selection_get : Evas.obj -> string option =
  "ml_elm_entry_selection_get"

external textblock_get : Evas.obj -> Evas.obj = "ml_elm_entry_textblock_get"

external calc_force : Evas.obj -> unit = "ml_elm_entry_calc_force"

external entry_insert : Evas.obj -> string -> unit = "ml_elm_entry_entry_insert"

external line_wrap_set : Evas.obj -> Elm.wrap_type -> unit =
  "ml_elm_entry_line_wrap_set"

external line_wrap_get : Evas.obj -> Elm.wrap_type =
  "ml_elm_entry_line_wrap_get"

external editable_set : Evas.obj -> bool -> unit =
  "ml_elm_entry_editable_set"

external editable_get : Evas.obj -> bool = "ml_elm_entry_editable_get"

external select_none : Evas.obj -> unit = "ml_elm_entry_select_none"

external select_all : Evas.obj -> unit = "ml_elm_entry_select_all"

external cursor_next : Evas.obj -> bool = "ml_elm_entry_cursor_next"

external cursor_prev : Evas.obj -> bool = "ml_elm_entry_cursor_prev"

external cursor_up : Evas.obj -> bool = "ml_elm_entry_cursor_up"

external cursor_down : Evas.obj -> bool = "ml_elm_entry_cursor_down"

external cursor_begin_set : Evas.obj -> unit = "ml_elm_entry_cursor_begin_set"

external cursor_end_set : Evas.obj -> unit = "ml_elm_entry_cursor_end_set"

external cursor_line_begin_set : Evas.obj -> unit =
  "ml_elm_entry_cursor_line_begin_set"

external cursor_line_end_set : Evas.obj -> unit =
  "ml_elm_entry_cursor_line_end_set"

external cursor_selection_begin : Evas.obj -> unit =
  "ml_elm_entry_cursor_selection_begin"

external cursor_selection_end : Evas.obj -> unit =
  "ml_elm_entry_cursor_selection_end"

external cursor_is_format_get : Evas.obj -> bool =
  "ml_elm_entry_cursor_is_format_get"

external cursor_is_visible_format_get : Evas.obj -> bool =
  "ml_elm_entry_cursor_is_visible_format_get"

external cursor_content_get : Evas.obj -> string =
  "ml_elm_entry_cursor_content_get"

external cursor_geometry_get : Evas.obj -> int * int * int * int =
  "ml_elm_entry_cursor_geometry_get"

external cursor_pos_set : Evas.obj -> int -> unit =
  "ml_elm_entry_cursor_pos_set"

external cursor_pos_get : Evas.obj -> int =
  "ml_elm_entry_cursor_pos_get"

external selection_cut : Evas.obj -> unit = "ml_elm_entry_selection_cut"

external selection_copy : Evas.obj -> unit = "ml_elm_entry_selection_copy"

external selection_paste : Evas.obj -> unit = "ml_elm_entry_selection_paste"

external context_menu_clear : Evas.obj -> unit =
  "ml_elm_entry_context_menu_clear"

external context_menu_item_add :
  Evas.obj -> string -> string -> Elm_icon.ty -> Evas.smart_cb -> unit =
  "ml_elm_entry_context_menu_item_add"

external context_menu_disabled_set : Evas.obj -> bool -> unit =
  "ml_elm_entry_context_menu_disabled_set"

external context_menu_disabled_get : Evas.obj -> bool =
  "ml_elm_entry_context_menu_disabled_get"

external item_provider_append : Evas.obj -> item_provider_cb -> unit =
  "ml_elm_entry_item_provider_append"

external item_provider_prepend : Evas.obj -> item_provider_cb -> unit =
  "ml_elm_entry_item_provider_prepend"

external markup_filter_append : Evas.obj -> filter_cb -> unit =
  "ml_elm_entry_markup_filter_append"

external markup_filter_prepend : Evas.obj -> filter_cb -> unit =
  "ml_elm_entry_markup_filter_prepend"

external markup_to_utf8 : string -> string = "ml_elm_entry_markup_to_utf8"

external utf8_to_markup : string -> string = "ml_elm_entry_utf8_to_markup"

external file_set : Evas.obj -> string -> Elm.text_format -> bool =
  "ml_elm_entry_file_set"

external file_get : Evas.obj -> string * Elm.text_format =
  "ml_elm_entry_file_get"

external file_save : Evas.obj -> unit = "ml_elm_entry_file_save"

external autosave_set : Evas.obj -> bool -> unit =
  "ml_elm_entry_autosave_set"

external autosave_get : Evas.obj -> bool =
  "ml_elm_entry_autosave_get"

external scrollable_set : Evas.obj -> bool -> unit =
  "ml_elm_entry_scrollable_set"

external scrollable_get : Evas.obj -> bool =
  "ml_elm_entry_scrollable_get"

external icon_visible_set : Evas.obj -> bool -> unit =
  "ml_elm_entry_icon_visible_set"

external end_visible_set : Evas.obj -> bool -> unit =
  "ml_elm_entry_end_visible_set"

external input_panel_layout_set : Evas.obj -> Elm.input_panel_layout -> unit =
  "ml_elm_entry_input_panel_layout_set"

external input_panel_layout_get : Evas.obj -> Elm.input_panel_layout =
  "ml_elm_entry_input_panel_layout_get"

external autocapital_type_set : Evas.obj -> Elm.autocapital_type -> unit =
  "ml_elm_entry_autocapital_type_set"

external autocapital_type_get : Evas.obj -> Elm.autocapital_type =
  "ml_elm_entry_autocapital_type_get"

external input_panel_enabled_set : Evas.obj -> bool -> unit =
  "ml_elm_entry_input_panel_enabled_set"

external input_panel_enabled_get : Evas.obj -> bool =
  "ml_elm_entry_input_panel_enabled_get"

external input_panel_show : Evas.obj -> unit =
  "ml_elm_entry_input_panel_show"

external input_panel_hide : Evas.obj -> unit =
  "ml_elm_entry_input_panel_hide"

external input_panel_language_set : Evas.obj -> Elm.input_panel_lang -> unit =
  "ml_elm_entry_input_panel_language_set"

external input_panel_language_get : Evas.obj -> Elm.input_panel_lang =
  "ml_elm_entry_input_panel_language_get"

external input_panel_return_key_type_set :
  Evas.obj -> Elm.input_panel_return_key_type -> unit =
  "ml_elm_entry_input_panel_return_key_type_set"

external input_panel_return_key_type_get :
  Evas.obj -> Elm.input_panel_return_key_type =
  "ml_elm_entry_input_panel_return_key_type_get"

external input_panel_return_key_disabled_set : Evas.obj -> bool -> unit =
  "ml_elm_entry_input_panel_return_key_disabled_set"

external input_panel_return_key_disabled_get : Evas.obj -> bool =
  "ml_elm_entry_input_panel_return_key_disabled_get"

external input_panel_return_key_autoenabled_set : Evas.obj -> bool -> unit =
  "ml_elm_entry_input_panel_return_key_autoenabled_set"

external imf_context_reset : Evas.obj -> unit = "ml_elm_entry_imf_context_reset"

external prediction_allow_set : Evas.obj -> bool -> unit =
  "ml_elm_entry_prediction_allow_set"

external prediction_allow_get : Evas.obj -> bool =
  "ml_elm_entry_prediction_allow_get"

external filter_limit_size :
  filter_limit_size -> Evas.obj -> string -> string option  =
  "ml_elm_entry_filter_limit_size"

external filter_accept_set :
  filter_accept_set -> Evas.obj -> string -> string option =
  "ml_elm_entry_filter_accept_set"

external cnp_mode_set : Evas.obj -> Elm.cnp_mode -> unit =
  "ml_elm_entry_cnp_mode_set"

external cnp_mode_get : Evas.obj -> Elm.cnp_mode = "ml_elm_entry_cnp_mode_get"

external anchor_hover_parent_set : Evas.obj -> Evas.obj -> unit =
  "ml_elm_entry_anchor_hover_parent_set"

external anchor_hover_parent_get : Evas.obj -> Evas.obj option =
  "ml_elm_entry_anchor_hover_parent_get"

external anchor_hover_style_set : Evas.obj -> string -> unit =
  "ml_elm_entry_anchor_hover_style_set"

external anchor_hover_style_get : Evas.obj -> string =
  "ml_elm_entry_anchor_hover_style_get"

external anchor_hover_end : Evas.obj -> unit =
  "ml_elm_entry_anchor_hover_end"

external input_panel_layout_variation_set : Evas.obj -> int -> unit =
  "ml_elm_entry_input_panel_layout_variation_set"

external input_panel_layout_variation_get : Evas.obj -> int =
  "ml_elm_entry_input_panel_layout_variation_get"

external anchor_info_of_ptr : Evas.ptr -> anchor_info =
  "ml_elm_entry_anchor_info_of_ptr"

external anchor_hover_info_of_ptr : Evas.ptr -> anchor_hover_info =
  "ml_elm_entry_anchor_hover_info_of_ptr"

