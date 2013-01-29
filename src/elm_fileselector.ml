external add : Evas.obj -> Evas.obj = "ml_elm_fileselector_add"

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

