include Henums.Elm_web

type window_features

type window_open = Evas.obj -> bool -> window_features -> Evas.obj option

type dialog_alert = Evas.obj -> string -> Evas.obj option

type dialog_confirm = Evas.obj -> string -> Evas.obj option * bool

type dialog_prompt =
  Evas.obj -> string -> string -> Evas.obj option * string option * bool

type dialog_file_selector =
  Evas.obj -> bool -> string list -> Evas.obj * string list * bool

type console_message = Evas.obj -> string -> int -> string -> unit

type frame_load_error = {
  code : int;
  is_cancellation : bool;
  domain : string;
  description : string;
  failing_url : string;
  frame : Evas.obj;
}

type menu_item = {text : string; ty : menu_item_type}

type menu = {
  items : menu_item list;
  x : int;
  y : int;
  width : int;
  height : int;
  handled : bool;
}

type download = {url : string}

module AF = Autofun.Elm_web.F (struct
  type evas_object = Evas.obj
  type elm_web_window_features = window_features
  type elm_web_window_feature_flag = window_feature_flag
  type elm_web_zoom_mode = zoom_mode
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_web_add"

let addx = Elm_object.create_addx add

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

external url_get : Evas.obj -> string option = "ml_elm_web_url_get"

external title_get : Evas.obj -> string option = "ml_elm_web_title_get"

external bg_color_get : Evas.obj -> int * int * int * int =
  "ml_elm_web_bg_color_get"

external selection_get : Evas.obj -> string option = "ml_elm_web_selection_get"

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

external window_features_region_get : window_features -> int * int * int * int =
  "ml_elm_web_window_features_region_get"

external frame_load_error_of_ptr : Evas.ptr -> frame_load_error =
  "ml_Elm_Web_Frame_Load_Error_of_ptr"

external menu_of_ptr : Evas.ptr -> menu = "ml_Elm_Web_Menu_of_ptr"

external download_of_ptr : Evas.ptr -> download = "ml_Elm_Web_Download_of_ptr"

