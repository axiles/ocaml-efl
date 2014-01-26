type window_features

type window_open = Evas.obj -> bool -> window_features -> Evas.obj option

type dialog_alert = Evas.obj -> string -> Evas.obj option

type dialog_confirm = Evas.obj -> string -> Evas.obj option * bool

type dialog_prompt =
  Evas.obj -> string -> string -> Evas.obj option * string option * bool

type dialog_file_selector =
  Evas.obj -> bool -> string list -> Evas.obj * string list * bool

type console_message = Evas.obj -> string -> int -> string -> unit

external add : Evas.obj -> Evas.obj = "ml_elm_web_add"

external useragent_set : Evas.obj -> string -> unit = "ml_elm_web_useragent_set"

external useragent_get : Evas.obj -> string = "ml_elm_web_useragent_get"

external webkit_view_get : Evas.obj -> Evas.obj = "ml_elm_web_webkit_view_get"

external window_create_hook_set : Evas.obj -> window_open -> unit =
  "ml_elm_web_window_create_hook_set"

external dialog_alert_hook_set : Evas.obj -> dialog_alert -> unit =
  "ml_elm_web_dialog_alert_hook_set"

external dialog_confirm_hook_set : Evas.obj -> dialog_confirm -> unit =
  "ml_elm_web_dialog_confirm_hook_set"

external dialog_prompt_hook_set : Evas.obj -> dialog_prompt -> unit =
  "ml_elm_web_dialog_prompt_hook_set"

external dialog_file_selector_hook_set :
  Evas.obj -> dialog_file_selector -> unit =
    "ml_elm_web_dialog_file_selector_hook_set"

external console_message_hook_set : Evas.obj -> console_message -> unit =
  "ml_elm_web_console_message_hook_set"

external tab_propagate_get : Evas.obj -> bool = "ml_elm_web_tab_propagate_get"

external tab_propagate_set : Evas.obj -> bool -> unit =
  "ml_elm_web_tab_propagate_set"

external url_set : Evas.obj -> string -> bool = "ml_elm_web_url_set"

external url_get : Evas.obj -> string option = "ml_elm_web_url_get"

external title_get : Evas.obj -> string option = "ml_elm_web_title_get"

external bg_color_set : Evas.obj -> int -> int -> int -> int -> unit =
  "ml_elm_web_bg_color_set"

external bg_color_get : Evas.obj -> int * int * int * int =
  "ml_elm_web_bg_color_get"

external selection_get : Evas.obj -> string option = "ml_elm_web_selection_get"

external popup_selected_set : Evas.obj -> int -> unit =
  "ml_elm_web_popup_selected_set"

external popup_destroy : Evas.obj -> bool = "ml_elm_web_popup_destroy"

external text_search :
  Evas.obj -> string -> cs:bool -> fwd:bool -> wrp:bool -> bool =
    "ml_elm_web_text_search"

external text_matches_mark :
  Evas.obj -> string -> cs:bool -> hl:bool -> int -> int =
    "ml_elm_web_text_matches_mark"

external text_matches_unmark_all : Evas.obj -> bool =
  "ml_elm_web_text_matches_unmark_all"

external text_matches_highlight_set : Evas.obj -> bool -> bool =
  "ml_elm_web_text_matches_highlight_set"

external text_matches_highlight_get : Evas.obj -> bool =
  "ml_elm_web_text_matches_highlight_get"

external load_progress_get : Evas.obj -> float = "ml_elm_web_load_progress_get"

external stop : Evas.obj -> bool = "ml_elm_web_stop"

external reload : Evas.obj -> bool = "ml_elm_web_reload"

external reload_full : Evas.obj -> bool = "ml_elm_web_reload_full"

external back : Evas.obj -> bool = "ml_elm_web_back"

external forward : Evas.obj -> bool = "ml_elm_web_forward"

external navigate : Evas.obj -> int -> bool = "ml_elm_web_navigate"

external back_possible_get : Evas.obj -> bool = "ml_elm_web_back_possible_get"

external forward_possible_get : Evas.obj -> bool =
  "ml_elm_web_forward_possible_get"

external navigate_possible_get : Evas.obj -> int -> bool =
  "ml_elm_web_navigate_possible_get"

external history_enabled_get : Evas.obj -> bool =
  "ml_elm_web_history_enabled_get"

external history_enabled_set : Evas.obj -> bool -> unit =
  "ml_elm_web_history_enabled_set"

external zoom_set : Evas.obj -> float -> unit = "ml_elm_web_zoom_set"

external zoom_get : Evas.obj -> float = "ml_elm_web_zoom_get"

