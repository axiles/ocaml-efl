external add : Evas.obj -> Evas.obj = "ml_elm_grid_add"

external size_set : Evas.obj -> int -> int -> unit = "ml_elm_grid_size_set"

external size_get : Evas.obj -> int * int = "ml_elm_grid_size_get"

external pack : Evas.obj -> Evas.obj -> int -> int -> int -> int -> unit =
  "ml_elm_grid_pack_bytecode" "ml_elm_grid_pack_native"

external unpack : Evas.obj -> Evas.obj -> unit = "ml_elm_grid_unpack"

external clear : Evas.obj -> bool -> unit = "ml_elm_grid_clear"

external pack_set : Evas.obj -> int -> int -> int -> int -> unit =
  "ml_elm_grid_pack_set"

external pack_get : Evas.obj -> int * int * int * int = "ml_elm_grid_pack_get"

external children_get : Evas.obj -> Evas.obj list = "ml_elm_grid_children_get"

