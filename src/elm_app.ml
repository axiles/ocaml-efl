external info_set : string -> ?checkfile:string -> unit -> unit =
  "ml_elm_app_info_set"

external name_set : string -> unit = "ml_elm_app_name_set"

external desktop_entry_set : string -> unit = "ml_elm_app_desktop_entry_set"

external compile_bin_dir_set : string -> unit = "ml_elm_app_compile_bin_dir_set"

external compile_lib_dir_set : string -> unit = "ml_elm_app_compile_lib_dir_set"

external compile_data_dir_set : string -> unit =
  "ml_elm_app_compile_data_dir_set"

external compile_locale_set : string -> unit = "ml_elm_app_compile_locale_set"

external data_dir_get : unit -> string = "ml_elm_app_data_dir_get"

