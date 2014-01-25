type window_features

type window_open = Evas.obj -> bool -> window_features -> Evas.obj option

type dialog_alert = Evas.obj -> string -> Evas.obj option

type dialog_confirm = Evas.obj -> string -> Evas.obj option * bool

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

