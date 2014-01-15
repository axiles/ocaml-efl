external add : Evas.obj -> Evas.obj = "ml_elm_fileselector_entry_add"

external window_title_set : Evas.obj -> string -> unit =
  "ml_elm_fileselector_entry_window_title_set"

external window_title_get : Evas.obj -> string =
  "ml_elm_fileselector_entry_window_title_get"

external window_size_set : Evas.obj -> int -> int -> unit =
  "ml_elm_fileselector_entry_window_size_set"

external window_size_get : Evas.obj -> int * int =
  "ml_elm_fileselector_entry_window_size_get"

external path_set : Evas.obj -> string -> unit =
  "ml_elm_fileselector_entry_path_set"

external path_get : Evas.obj -> string = "ml_elm_fileselector_entry_path_get"

external expandable_set : Evas.obj -> bool -> unit =
  "ml_elm_fileselector_entry_expandable_set"

external expandable_get : Evas.obj -> bool =
  "ml_elm_fileselector_entry_expandable_get"

external folder_only_set : Evas.obj -> bool -> unit =
  "ml_elm_fileselector_entry_folder_only_set"

external folder_only_get : Evas.obj -> bool =
  "ml_elm_fileselector_entry_folder_only_get"

external is_save_set : Evas.obj -> bool -> unit =
  "ml_elm_fileselector_entry_is_save_set"

external is_save_get : Evas.obj -> bool =
  "ml_elm_fileselector_entry_is_save_get"

external inwin_mode_set : Evas.obj -> bool -> unit =
  "ml_elm_fileselector_entry_inwin_mode_set"

external inwin_mode_get : Evas.obj -> bool =
  "ml_elm_fileselector_entry_inwin_mode_get"

module E = struct
  type u = Evas.Event_type.u
  type 'a v = 'a Evas.Event_type.v
  let f = Evas.Event_type.create_unit
  let g x = Evas.Event_type.create x Evas.string_opt_of_ptr
  let changed = f "changed"
  let activated = f "activated"
  let press = f "press"
  let longpressed = f "longpressed"
  let clicked = f "clicked"
  let clicked_double = f "clicked,double"
  let focused = f "focused"
  let unfocused = f "unfocused"
  let selection_paste = f "selection,paste"
  let selection_copy = f "selection,copy"
  let selection_cut = f "selection,cut"
  let unpressed = f "unpressed"
  let file_chosen = g "file,chosen"
  let language_changed = f "language,changed"
end

