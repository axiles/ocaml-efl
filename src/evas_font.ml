(*type hinting_flags = [`none | `auto | `bytecode]*)

type hinting_flags = Henums.Evas_font.hinting_flags

external hinting_set : Evas.t -> hinting_flags -> unit =
  "ml_evas_font_hinting_set"

external hinting_get : Evas.t -> hinting_flags = "ml_evas_font_hinting_get"

external hinting_can_hint : Evas.t -> hinting_flags -> bool =
  "ml_evas_font_hinting_can_hint"

external cache_flush : Evas.t -> unit = "ml_evas_font_cache_flush"

external cache_set : Evas.t -> int -> unit = "ml_evas_font_cache_set"

external cache_get : Evas.t -> int = "ml_evas_font_cache_get"

external available_list : Evas.t -> string list = "ml_evas_font_available_list"

external path_clear : Evas.t -> unit = "ml_evas_font_path_clear"

external path_append : Evas.t -> string -> unit = "ml_evas_font_path_append"

external path_prepend : Evas.t -> string -> unit = "ml_evas_font_path_prepend"

external path_list : Evas.t -> string list = "ml_evas_font_path_list"

