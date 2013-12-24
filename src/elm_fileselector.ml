type mode = [`list | `grid | `last]

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

external path_get : Evas.obj -> string = "ml_elm_fileselector_path_get"

external selected_set : Evas.obj -> string -> bool =
  "ml_elm_fileselector_selected_set"

external selected_get : Evas.obj -> string = "ml_elm_fileselector_selected_get"

external mime_types_filter_append :
  Evas.obj -> string -> ?filter_name:string -> unit -> bool =
    "ml_elm_fileselector_mime_types_filter_append"

external filters_clear : Evas.obj -> unit = "ml_elm_fileselector_filters_clear"

external mode_set : Evas.obj -> mode -> unit = "ml_elm_fileselector_mode_set"

external mode_get : Evas.obj -> mode = "ml_elm_fileselector_mode_get"

external multi_select_set : Evas.obj -> bool -> unit =
  "ml_elm_fileselector_multi_select_set"

external multi_select_get : Evas.obj -> bool =
  "ml_elm_fileselector_multi_select_get"

external selected_paths_get : Evas.obj -> string list =
  "ml_elm_fileselector_selected_paths_get"

module E = struct
  type 'a v = 'a Evas.Event_type.v
  type u = Evas.Event_type.u
  let f = Evas.Event_type.create_unit
  let g x = Evas.Event_type.create x Evas.string_of_ptr
  let h x = Evas.Event_type.create x Evas.string_opt_of_ptr
  let activated = g "activated"
  let selected = g "selected"
  let selected_invalid = f "selected,invalid"
  let directory_open = g "directory,open"
  let _done = h "done"
end

