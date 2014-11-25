external add : Evas.obj -> Evas.obj = "ml_elm_route_add"

let addx = Elm_object.create_addx add

external longitude_min_max_get : Evas.obj -> float * float =
  "ml_elm_route_longitude_min_max_get"

external latitude_min_max_get : Evas.obj -> float * float =
  "ml_elm_route_latitude_min_max_get"

