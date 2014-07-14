(*type mode = [`list | `grid | `last]*)

type mode = Henums.Elm_fileselector.mode

external add : Evas.obj -> Evas.obj = "ml_elm_fileselector_add"

let addx = Elm_object.create_addx add

external is_save_set : Evas.obj -> bool -> unit =
  "ml_elm_fileselector_is_save_set"

external is_save_get : Evas.obj -> bool = "ml_elm_fileselector_is_save_get"

external folder_only_set : Evas.obj -> bool -> unit =
  "ml_elm_fileselector_folder_only_set"

external folder_only_get : Evas.obj -> bool =
  "ml_elm_fileselector_folder_only_get"

external buttons_ok_cancel_set : Evas.obj -> bool -> unit =
  "ml_elm_fileselector_buttons_ok_cancel_set"
  
external buttons_ok_cancel_get : Evas.obj -> bool =
  "ml_elm_fileselector_buttons_ok_cancel_get"

external expandable_set : Evas.obj -> bool -> unit =
  "ml_elm_fileselector_expandable_set"

external expandable_get : Evas.obj -> bool =
  "ml_elm_fileselector_expandable_get"

external path_set : Evas.obj -> string -> unit = "ml_elm_fileselector_path_set"

external path_get : Evas.obj -> string = "ml_elm_fileselector_path_get"

external selected_set : Evas.obj -> string -> bool =
  "ml_elm_fileselector_selected_set"

external selected_get : Evas.obj -> string = "ml_elm_fileselector_selected_get"

external mime_types_filter_append :
  Evas.obj -> string -> ?filter_name:string -> unit -> bool =
    "ml_elm_fileselector_mime_types_filter_append"

external filters_clear : Evas.obj -> unit = "ml_elm_fileselector_filters_clear"

external hidden_visible_set : Evas.obj -> bool -> unit =
  "ml_elm_fileselector_hidden_visible_set"

external hidden_visible_get : Evas.obj -> bool =
  "ml_elm_fileselector_hidden_visible_get"

external mode_set : Evas.obj -> mode -> unit = "ml_elm_fileselector_mode_set"

external mode_get : Evas.obj -> mode = "ml_elm_fileselector_mode_get"

external multi_select_set : Evas.obj -> bool -> unit =
  "ml_elm_fileselector_multi_select_set"

external multi_select_get : Evas.obj -> bool =
  "ml_elm_fileselector_multi_select_get"

external selected_paths_get : Evas.obj -> string list =
  "ml_elm_fileselector_selected_paths_get"

