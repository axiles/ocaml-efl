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

