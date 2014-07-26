include Henums.Elm_clock

type edit_mode_ = {
  defalt : bool;
  hour_decimal : bool;
  hour_unit : bool;
  min_decimal : bool;
  min_unit : bool;
  sec_decimal : bool;
  sec_unit : bool;
  all : bool;
}

module AF = Autofun.Elm_clock.F (struct
  type evas_object = Evas.obj
  type elm_clock_edit_mode_list = edit_mode list
  type elm_clock_edit_mode_ = edit_mode_
end)
include AF

external add : Evas.obj -> Evas.obj = "ml_elm_clock_add"

let addx = Elm_object.create_addx add

external time_get : Evas.obj -> int * int * int = "ml_elm_clock_time_get"

