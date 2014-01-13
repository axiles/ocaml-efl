(* Cache *)

external cache_all_flush : unit -> unit = "ml_elm_cache_all_flush"

(* Fingers *)

external coords_finger_size_adjust : int -> int -> int * int =
  "ml_elm_coords_finger_size_adjust"

(* Focus *)

type focus_direction = [
  `previous |
  `next |
  `up |
  `down |
  `right |
  `left]

(* General *)

type policy = [`quit]

type policy_value = [`none | `last_window_closed]

external init_with_counter : string array -> int = "ml_elm_init_with_counter"

let init () = let (_ : int) = init_with_counter Sys.argv in ()

external shutdown : unit -> unit = "ml_elm_shutdown"

external run : unit -> unit = "ml_elm_run"

external exit : unit -> unit = "ml_elm_exit"

external policy_set_bool : policy -> policy_value -> bool = "ml_elm_policy_set"

let policy_set p pv =
  let (_ : bool) = policy_set_bool p pv in
  ()

external policy_get : policy -> policy_value = "ml_elm_policy_get"

external language_set : string -> unit = "ml_elm_language_set"

(* Theme *)

type theme

(* Others *)

type wrap_type = [`none | `char | `word | `mixed]

type text_format = [`plain_utf8 | `markup_utf8]

type input_panel_layout = [
  | `normal
  | `number
  | `email
  | `url
  | `phonenumber
  | `ip
  | `month
  | `numberonly
  | `invalid
  | `hex
  | `terminal
  | `password
  | `datetime
]

type autocapital_type = [`none | `word | `sentence | `allcharacter]

type input_panel_lang = [`automatic | `alphabet]

type input_panel_return_key_type = [
  | `default
  | `_done
  | `go
  | `join
  | `login
  | `next
  | `search
  | `send
  | `signin
]

type cnp_mode = [`markup | `no_image | `plaintext]

type illume_command = [`focus_back | `focus_forward | `focus_home | `close]

type gesture_type = [
  | `n_taps
  | `n_long_taps
  | `n_double_taps
  | `n_triple_taps
  | `momentum
  | `n_lines
  | `n_flicks
  | `zoom
  | `rotate]

type gesture_state = [
  | `undefined
  | `start
  | `move
  | `_end
  | `abort]

type gesture_event_cb = Evas.ptr -> unit

module Gesture_taps_info = struct
  type t = {
    y : int;
    n : int;
    timestamp : int;
  }
  external of_ptr : Evas.ptr -> t = "ml_Elm_Gesture_Taps_Info_of_ptr"
end

module Gesture_momentum_info = struct
  type t = {
    x1 : int;
    y1 : int;
    x2 : int;
    y2 : int;
    tx : int;
    ty : int;
    mx : int;
    my : int;
    n : int;
  }
  external of_ptr : Evas.ptr -> t = "ml_Elm_Gesture_Momentum_Info_of_ptr"
end

module Gesture_line_info = struct
  type t = {
    momentum : Gesture_momentum_info.t;
    angle : float;
  }
  external of_ptr : Evas.ptr -> t = "ml_Elm_Gesture_Line_Info_of_ptr"
end

module Gesture_zoom_info = struct
  type t = {
    y : int;
    radius : int;
    zoom : float;
    momentum : float;
  }
  external of_ptr : Evas.ptr -> t = "ml_Elm_Gesture_Zoom_Info_of_ptr"
end

module Gesture_rotate_info = struct
  type t = {
    y : int;
    radius : int;
    base_angle : float;
    angle : float;
    momentum : float;
  }
  external of_ptr : Evas.ptr -> t = "ml_Elm_Gesture_Rotate_Info_of_ptr"
end

external need_ethumb : unit -> bool = "ml_elm_need_ethumb"

