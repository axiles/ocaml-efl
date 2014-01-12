type t = Elm.theme

external _new : unit -> t = "ml_elm_theme_new"

external free : t -> unit = "ml_elm_theme_free"

external copy : t -> t -> unit = "ml_elm_theme_copy"

external list_item_path_get : string -> (string * bool) option =
  "ml_elm_theme_list_item_path_get"

