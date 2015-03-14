open Common

let pos_map = simple_ty "Ecore" "Pos_Map"

let funs = [
  simple "time_get" [] double;
  simple "time_unix_get" [] double;
  simple  "loop_time_get" [] double;
]

