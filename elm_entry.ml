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

