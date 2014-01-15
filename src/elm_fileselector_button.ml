external add : Evas.obj -> Evas.obj = "ml_elm_fileselector_button_add"

external window_title_set : Evas.obj -> string -> unit =
  "ml_elm_fileselector_button_window_title_set"

external window_title_get : Evas.obj -> string =
  "ml_elm_fileselector_button_window_title_get"

external window_size_set : Evas.obj -> int -> int -> unit =
  "ml_elm_fileselector_button_window_size_set"

external window_size_get : Evas.obj -> int * int =
  "ml_elm_fileselector_button_window_size_get"

external path_set : Evas.obj -> string -> unit =
  "ml_elm_fileselector_button_path_set"

external path_get : Evas.obj -> string = "ml_elm_fileselector_button_path_get"

external expandable_set : Evas.obj -> bool -> unit =
  "ml_elm_fileselector_button_expandable_set"

external expandable_get : Evas.obj -> bool =
  "ml_elm_fileselector_button_expandable_get"

