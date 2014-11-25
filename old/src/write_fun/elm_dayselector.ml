open Common

let day = simple_ty "Elm_Dayselector" "Day"

let funs = [
  prop ~args:[evas_object; day] "day_selected" bool;
  prop "week_start" day;
  prop "weekend_start" day;
  prop "weekend_length" int;
]

