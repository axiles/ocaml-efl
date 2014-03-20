type edit_mode = [
  | `default
  | `hour_decimal
  | `hour_unit
  | `min_decimal
  | `min_unit
  | `sec_decimal
  | `sec_unit
  | `all]

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

external add : Evas.obj -> Evas.obj = "ml_elm_clock_add"

let addx = Elm_object.create_addx add

external time_set : Evas.obj -> int -> int -> int -> unit =
  "ml_elm_clock_time_set"

external time_get : Evas.obj -> int * int * int = "ml_elm_clock_time_get"

external edit_set : Evas.obj -> bool -> unit = "ml_elm_clock_edit_set"

external edit_get : Evas.obj -> bool = "ml_elm_clock_edit_get"

external edit_mode_set : Evas.obj -> edit_mode list -> unit =
  "ml_elm_clock_edit_mode_set"

external edit_mode_get : Evas.obj -> edit_mode_ = "ml_elm_clock_edit_mode_get"

external show_am_pm_set : Evas.obj -> bool -> unit =
  "ml_elm_clock_show_am_pm_set"

external show_am_pm_get : Evas.obj -> bool =
  "ml_elm_clock_show_am_pm_get"

external show_seconds_set : Evas.obj -> bool -> unit =
  "ml_elm_clock_show_seconds_set"

external show_seconds_get : Evas.obj -> bool =
  "ml_elm_clock_show_seconds_get"

external first_interval_set : Evas.obj -> float -> unit =
  "ml_elm_clock_first_interval_set"

external first_interval_get : Evas.obj -> float =
  "ml_elm_clock_first_interval_get"

external pause_set : Evas.obj -> bool -> unit = "ml_elm_clock_pause_set"

external pause_get : Evas.obj -> bool = "ml_elm_clock_pause_get"

