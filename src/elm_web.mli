type window_features

type window_open = Evas.obj -> bool -> window_features -> Evas.obj option

type dialog_alert = Evas.obj -> string -> Evas.obj option

type dialog_confirm = Evas.obj -> string -> Evas.obj option * bool

type dialog_prompt =
  Evas.obj -> string -> string -> Evas.obj option * string option * bool

type dialog_file_selector =
  Evas.obj -> bool -> string list -> Evas.obj * string list * bool

type console_message = Evas.obj -> string -> int -> string -> unit

type zoom_mode = [`manual | `auto_fit | `auto_fill | `last]

val add : Evas.obj -> Evas.obj

val useragent_set : Evas.obj -> string -> unit

val useragent_get : Evas.obj -> string

val webkit_view_get : Evas.obj -> Evas.obj

val window_create_hook_set : Evas.obj -> window_open -> unit

val dialog_alert_hook_set : Evas.obj -> dialog_alert -> unit

val dialog_confirm_hook_set : Evas.obj -> dialog_confirm -> unit

val dialog_prompt_hook_set : Evas.obj -> dialog_prompt -> unit

val dialog_file_selector_hook_set : Evas.obj -> dialog_file_selector -> unit

val console_message_hook_set : Evas.obj -> console_message -> unit

val tab_propagate_get : Evas.obj -> bool

val tab_propagate_set : Evas.obj -> bool -> unit

val url_set : Evas.obj -> string -> bool

val url_get : Evas.obj -> string option

val title_get : Evas.obj -> string option

val bg_color_set : Evas.obj -> int -> int -> int -> int -> unit

val bg_color_get : Evas.obj -> int * int * int * int

val selection_get : Evas.obj -> string option

val popup_selected_set : Evas.obj -> int -> unit

val popup_destroy : Evas.obj -> bool

val text_search : Evas.obj -> string -> cs:bool -> fwd:bool -> wrp:bool -> bool

val text_matches_mark : Evas.obj -> string -> cs:bool -> hl:bool -> int -> int

val text_matches_unmark_all : Evas.obj -> bool

val text_matches_highlight_set : Evas.obj -> bool -> bool

val text_matches_highlight_get : Evas.obj -> bool

val load_progress_get : Evas.obj -> float

val stop : Evas.obj -> bool

val reload : Evas.obj -> bool

val reload_full : Evas.obj -> bool

val back : Evas.obj -> bool

val forward : Evas.obj -> bool

val navigate : Evas.obj -> int -> bool

val back_possible_get : Evas.obj -> bool

val forward_possible_get : Evas.obj -> bool

val navigate_possible_get : Evas.obj -> int -> bool

val history_enabled_get : Evas.obj -> bool

val history_enabled_set : Evas.obj -> bool -> unit

val zoom_set : Evas.obj -> float -> unit

val zoom_get : Evas.obj -> float

val zoom_mode_set : Evas.obj -> zoom_mode -> unit

val zoom_mode_get : Evas.obj -> zoom_mode

val region_show : Evas.obj -> int -> int -> int -> int -> unit

val region_bring_in : Evas.obj -> int -> int -> int -> int -> unit

