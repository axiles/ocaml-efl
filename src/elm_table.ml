external add : Evas.obj -> Evas.obj = "ml_elm_table_add"

external homogeneous_set : Evas.obj -> bool -> unit =
  "ml_elm_table_homogeneous_set"

external homogeneous_get : Evas.obj -> bool = "ml_elm_table_homogeneous_get"

external padding_set : Evas.obj -> int -> int -> unit =
  "ml_elm_table_padding_set"

external padding_get : Evas.obj -> int * int = "ml_elm_table_padding_get"

external pack : Evas.obj -> Evas.obj -> int -> int -> int -> int -> unit =
  "ml_elm_table_pack_bytecode" "ml_elm_table_pack_native"

external unpack : Evas.obj -> Evas.obj -> unit = "ml_elm_table_unpack"

external clear : Evas.obj -> bool -> unit = "ml_elm_table_clear"

external pack_set : Evas.obj -> int -> int -> int -> int -> unit =
  "ml_elm_table_pack_set"

external pack_get : Evas.obj -> int * int * int * int = "ml_elm_table_pack_get"

external child_get : Evas.obj -> int -> int -> Evas.obj option =
  "ml_elm_table_child_get"

