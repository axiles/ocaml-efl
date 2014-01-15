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

external folder_only_set : Evas.obj -> bool -> unit =
  "ml_elm_fileselector_button_folder_only_set"

external folder_only_get : Evas.obj -> bool =
  "ml_elm_fileselector_button_folder_only_get"

external is_save_set : Evas.obj -> bool -> unit =
  "ml_elm_fileselector_button_is_save_set"

external is_save_get : Evas.obj -> bool =
  "ml_elm_fileselector_button_is_save_get"

external inwin_mode_set : Evas.obj -> bool -> unit =
  "ml_elm_fileselector_button_inwin_mode_set"

external inwin_mode_get : Evas.obj -> bool =
  "ml_elm_fileselector_button_inwin_mode_get"

module E = struct
  type u = Evas.Event_type.u
  type 'a v = 'a Evas.Event_type.v
  let f = Evas.Event_type.create_unit
  let g x = Evas.Event_type.create x Evas.string_opt_of_ptr
  let file_chosen = g "file,chosen"
  let language_changed = f "language,changed"
end

