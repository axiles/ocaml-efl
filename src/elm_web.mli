type window_features

type window_open = Evas.obj -> bool -> window_features -> Evas.obj option

type dialog_alert = Evas.obj -> string -> Evas.obj option

type dialog_confirm = Evas.obj -> string -> Evas.obj option * bool

type dialog_prompt =
  Evas.obj -> string -> string -> Evas.obj option * string option * bool

type dialog_file_selector =
  Evas.obj -> bool -> string list -> Evas.obj * string list * bool

type console_message = Evas.obj -> string -> int -> string -> unit

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

