(** elm_* Elm_* *)

(** {2 Cache} *)

val cache_all_flush : unit -> unit

(** {2 Fingers} *)

val coords_finger_size_adjust : int -> int -> int * int

(** {2 Focus *)

type focus_direction = [
  `previous |
  `next |
  `up |
  `down |
  `right |
  `left]

(** {2 General} *)

type policy = [`quit]

type policy_value = [`none | `last_window_closed]

val init : unit -> unit

val shutdown : unit -> unit

val run : unit -> unit

val exit : unit -> unit

val policy_set_bool : policy -> policy_value -> bool

val policy_set : policy -> policy_value -> unit

val policy_get : policy -> policy_value

val language_set : string -> unit

(** {2 Theme} *)

type theme

(** {2 Others} *)

type text_format = [`plain_utf8 | `markup_utf8]

type wrap_type = [`none | `char | `word | `mixed]

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

type input_panel_lang = [`automatic | `alphabet]

type autocapital_type = [`none | `word | `sentence | `allcharacter]

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

val init_with_counter : string array -> int

val need_ethumb : unit -> bool

