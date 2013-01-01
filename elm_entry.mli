type item_provider_cb = Evas.obj -> string -> Evas.obj option

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

