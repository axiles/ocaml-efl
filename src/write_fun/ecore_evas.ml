open Common

let ee = simple_ty "Ecore" "Evas"

let funs = [
  prop ~args:[ee] "title" safe_string;
]

