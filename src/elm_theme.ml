type t = Elm.theme

external _new : unit -> t = "ml_elm_theme_new"

external free : t -> unit = "ml_elm_theme_free"

external copy : t -> t -> unit = "ml_elm_theme_copy"

external ref_set : t -> t option -> unit = "ml_elm_theme_ref_set"

external ref_get : t -> t option = "ml_elm_theme_ref_get"

external default_get : unit -> t = "ml_elm_theme_default_get"

external overlay_add : ?th:t -> string -> unit = "ml_elm_theme_overlay_add"

external overlay_del : ?th:t -> string -> unit = "ml_elm_theme_overlay_del"

external overlay_list_get : t -> string list = "ml_elm_theme_overlay_list_get"

external extension_add : ?th:t -> string -> unit = "ml_elm_theme_extension_add"

external extension_del : ?th:t -> string -> unit = "ml_elm_theme_extension_del"

external extension_list_get : t -> string list =
  "ml_elm_theme_extension_list_get"

external list_item_path_get : string -> (string * bool) option =
  "ml_elm_theme_list_item_path_get"

