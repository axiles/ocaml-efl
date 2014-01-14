external add : Evas.obj -> Evas.obj = "ml_elm_table_add"

external homogeneous_set : Evas.obj -> bool -> unit =
  "ml_elm_table_homogeneous_set"

external homogeneous_get : Evas.obj -> bool = "ml_elm_table_homogeneous_get"

external padding_set : Evas.obj -> int -> int -> unit =
  "ml_elm_table_padding_set"

external padding_get : Evas.obj -> int * int = "ml_elm_table_padding_get"

