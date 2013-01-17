type ty = [`basic]

external add : ?p:Evas.obj -> string -> ty -> Evas.obj =
  "ml_elm_win_add"

external util_standard_add : string -> string -> Evas.obj =
  "ml_elm_win_util_standard_add"

external title_set : Evas.obj -> string -> unit = "ml_elm_win_title_set"

external resize_object_add : Evas.obj -> Evas.obj -> unit =
  "ml_elm_win_resize_object_add"

external autodel_set : Evas.obj -> bool -> unit = "ml_elm_win_autodel_set"

