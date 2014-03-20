(** Elementary *)

(** {2 Cache} *)

val cache_all_flush : unit -> unit

(** {2 Fingers} *)

val coords_finger_size_adjust : int -> int -> int * int

(** {2 Focus} *)

type focus_direction = [
  `previous |
  `next |
  `up |
  `down |
  `right |
  `left]

(** {2 General} *)

type policy_quit = [`none | `last_window_closed]

type policy_exit = [`none | `windows_del]

type policy_throttle = [`config | `hidden_always | `never]

type event_cb = Evas.obj -> Evas.obj -> Evas_event.t -> bool

val init : unit -> unit

val shutdown : unit -> unit

val run : unit -> unit

val exit : unit -> unit

val policy_quit_set_bool : policy_quit -> bool

val policy_quit_set : policy_quit -> unit

val policy_exit_set_bool : policy_exit -> bool

val policy_exit_set : policy_exit -> unit

val policy_throttle_set_bool : policy_throttle -> bool

val policy_throttle_set : policy_throttle -> unit

val policy_quit_get : unit -> policy_quit

val policy_exit_get : unit -> policy_exit

val policy_throttle_get : unit -> policy_throttle

val language_set : string -> unit

val connect : 'a Evas.Signal.t -> 'a -> Evas_object_smart.sig_with_cb

(** {2 Gesture Layer} *)

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

module Gesture_taps_info : sig
  type t = {
    y : int;
    n : int;
    timestamp : int;
  }
  val of_ptr : Evas.ptr -> t
end

module Gesture_momentum_info : sig
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
  val of_ptr : Evas.ptr -> t
end

module Gesture_line_info : sig
  type t = {
    momentum : Gesture_momentum_info.t;
    angle : float;
  }
  val of_ptr : Evas.ptr -> t
end

module Gesture_zoom_info : sig
  type t = {
    y : int;
    radius : int;
    zoom : float;
    momentum : float;
  }
  val of_ptr : Evas.ptr -> t
end

module Gesture_rotate_info : sig
  type t = {
    y : int;
    radius : int;
    base_angle : float;
    angle : float;
    momentum : float;
  }
  val of_ptr : Evas.ptr -> t
end

(** {2 Theme} *)

type theme

(** {2 Need} *)

val need_efreet : unit -> bool

val need_systray : unit -> bool

val need_sys_notify : unit -> bool

val need_eldbus : unit -> bool

val need_elocation : unit -> bool

val need_ethumb : unit -> bool

val need_web : unit -> bool

(** Entry *)

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

(** {2 Window} *)

type illume_command = [`focus_back | `focus_forward | `focus_home | `close]

(** {2 Transit} *)

type transit

(** {2 Tooltips} *)

type tooltip_content_cb = Evas.obj -> Evas.obj -> Evas.obj option

type 'a tooltip_item_content_cb = Evas.obj -> Evas.obj -> 'a -> Evas.obj option

(** {2 Video} *)

val player_add : Evas.obj -> Evas.obj

