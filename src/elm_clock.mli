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

val add : Evas.obj -> Evas.obj

val time_set : Evas.obj -> int -> int -> int -> unit

val time_get : Evas.obj -> int * int * int

val edit_set : Evas.obj -> bool -> unit

val edit_get : Evas.obj -> bool

val edit_mode_set : Evas.obj -> edit_mode list -> unit

val edit_mode_get : Evas.obj -> edit_mode_

val show_am_pm_set : Evas.obj -> bool -> unit

val show_am_pm_get : Evas.obj -> bool

val show_seconds_set : Evas.obj -> bool -> unit

val show_seconds_get : Evas.obj -> bool

