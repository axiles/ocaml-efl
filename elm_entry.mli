(** elm_entry_* Elm_Entry_*

Functions not interfaced yet:

- elm_entry_input_panel_imdata_get
- elm_entry_input_panel_imdata_set

Functions that will not be interfaced:

- elm_entry_item_provider_remove
- elm_entry_markup_filter_remove

*)

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

type filter_limit_size = {
  mutable max_char_count : int;
  mutable max_byte_count : int
}

type filter_accept_set = {mutable accepted : string; mutable rejected : string}

val add : Evas.obj -> Evas.obj

val text_style_user_push : Evas.obj -> string -> unit 

val text_style_user_pop : Evas.obj -> unit

val text_style_user_peek : Evas.obj -> string option

val single_line_set : Evas.obj -> bool -> unit

val single_line_get : Evas.obj -> bool

val password_set : Evas.obj -> bool -> unit

val password_get : Evas.obj -> bool

val entry_set : Evas.obj -> string -> unit

val entry_get : Evas.obj -> string

val entry_append : Evas.obj -> string -> unit

val is_empty : Evas.obj -> bool

val selection_get : Evas.obj -> string option

val textblock_get : Evas.obj ->  Evas.obj

val calc_force : Evas.obj -> unit

val entry_insert : Evas.obj -> string -> unit

val line_wrap_set : Evas.obj -> Elm.wrap_type -> unit

val line_wrap_get : Evas.obj -> Elm.wrap_type

val editable_set : Evas.obj -> bool -> unit

val editable_get : Evas.obj -> bool

val select_none : Evas.obj -> unit

val select_all : Evas.obj -> unit

val cursor_next : Evas.obj -> bool

val cursor_prev : Evas.obj -> bool

val cursor_up : Evas.obj -> bool

val cursor_down : Evas.obj -> bool

val cursor_begin_set : Evas.obj -> unit

val cursor_end_set : Evas.obj -> unit

val cursor_line_begin_set : Evas.obj -> unit

val cursor_line_end_set : Evas.obj -> unit

val cursor_selection_begin : Evas.obj -> unit

val cursor_selection_end : Evas.obj -> unit

val cursor_is_format_get : Evas.obj -> bool

val cursor_is_visible_format_get : Evas.obj -> bool

val cursor_content_get : Evas.obj -> string

val cursor_geometry_get : Evas.obj -> int * int * int * int

val cursor_pos_set : Evas.obj -> int -> unit

val cursor_pos_get : Evas.obj -> int

val selection_cut : Evas.obj -> unit

val selection_copy : Evas.obj -> unit

val selection_paste : Evas.obj -> unit

val context_menu_clear : Evas.obj -> unit

val context_menu_item_add :
  Evas.obj -> string -> string -> Elm_icon.ty -> Evas.smart_cb -> unit

val context_menu_disabled_set : Evas.obj -> bool -> unit

val context_menu_disabled_get : Evas.obj -> bool

val item_provider_append : Evas.obj -> item_provider_cb -> unit

val item_provider_prepend : Evas.obj -> item_provider_cb -> unit

val markup_filter_append : Evas.obj -> filter_cb -> unit

val markup_filter_prepend : Evas.obj -> filter_cb -> unit

val markup_to_utf8 : string -> string

val utf8_to_markup : string -> string

val file_set : Evas.obj -> string -> Elm.text_format -> unit

val file_get : Evas.obj -> string * Elm.text_format

val file_save : Evas.obj -> unit

val autosave_set : Evas.obj -> bool -> unit

val autosave_get : Evas.obj -> bool

val scrollable_set : Evas.obj -> bool -> unit

val scrollable_get : Evas.obj -> bool

val icon_visible_set : Evas.obj -> bool -> unit

val end_visible_set : Evas.obj -> bool -> unit

val scrollbar_policy_set :
  Evas.obj -> Elm_scroller.policy -> Elm_scroller.policy -> unit

val bounce_set : Evas.obj -> bool -> bool -> unit

val bounce_get : Evas.obj -> bool * bool

val input_panel_layout_set : Evas.obj -> Elm.input_panel_layout -> unit

val input_panel_layout_get : Evas.obj -> Elm.input_panel_layout

val autocapital_type_set : Evas.obj -> Elm.autocapital_type -> unit

val autocapital_type_get : Evas.obj -> Elm.autocapital_type

val input_panel_enabled_set : Evas.obj -> bool -> unit

val input_panel_enabled_get : Evas.obj -> bool

val input_panel_show : Evas.obj -> unit

val input_panel_hide : Evas.obj -> unit

val input_panel_language_set : Evas.obj -> Elm.input_panel_lang -> unit

val input_panel_language_get : Evas.obj -> Elm.input_panel_lang

val input_panel_return_key_type_set :
  Evas.obj -> Elm.input_panel_return_key_type -> unit

val input_panel_return_key_type_get :
  Evas.obj -> Elm.input_panel_return_key_type

val input_panel_return_key_disabled_set : Evas.obj -> bool -> unit

val input_panel_return_key_disabled_get : Evas.obj -> bool

val input_panel_return_key_autoenabled_set : Evas.obj -> bool -> unit

val imf_context_reset : Evas.obj -> unit

val prediction_allow_set : Evas.obj -> bool -> unit

val prediction_allow_get : Evas.obj -> bool

val filter_limit_size : filter_limit_size -> filter_cb

val filter_accept_set : filter_accept_set -> filter_cb

val cnp_mode_set : Evas.obj -> Elm.cnp_mode -> unit

val cnp_mode_get : Evas.obj -> Elm.cnp_mode

val anchor_hover_parent_set : Evas.obj -> Evas.obj -> unit

val anchor_hover_parent_get : Evas.obj -> Evas.obj option

val anchor_hover_style_set : Evas.obj -> string -> unit

val anchor_hover_style_get : Evas.obj -> string

val anchor_hover_end : Evas.obj -> unit

val anchor_info_of_ptr : Evas.ptr -> anchor_info

val anchor_info_of_ptr : Evas.ptr -> anchor_info

