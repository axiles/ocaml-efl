include Henums.Elm_dayselector
module AF = Autofun.Elm_dayselector.F (struct
  type evas_object = Evas.obj
  type elm_dayselector_day = day
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_dayselector_add"

let addx = Elm_object.create_addx add

external weekdays_names_set : Evas.obj -> string array -> unit =
  "ml_elm_dayselector_weekdays_names_set"

external weekdays_names_get : Evas.obj -> string list =
  "ml_elm_dayselector_weekdays_names_get"

external day_of_ptr : Evas.ptr -> day = "ml_Elm_Dayselector_Day_of_ptr"

