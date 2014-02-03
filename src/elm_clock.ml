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

external time_set : Evas.obj -> int -> int -> int -> unit =
  "ml_elm_clock_time_set"

external time_get : Evas.obj -> int * int * int = "ml_elm_clock_time_get"

external edit_set : Evas.obj -> bool -> unit = "ml_elm_clock_edit_set"

external edit_get : Evas.obj -> bool = "ml_elm_clock_edit_get"

external edit_mode_set : Evas.obj -> edit_mode list -> unit =
  "ml_elm_clock_edit_mode_set"

external edit_mode_get : Evas.obj -> edit_mode_ = "ml_elm_clock_edit_mode_get"

