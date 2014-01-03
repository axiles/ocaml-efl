type policy = [`quit]

type policy_value = [`none | `last_window_closed]

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

external cache_all_flush : unit -> unit = "ml_elm_cache_all_flush"

external init_with_counter : string array -> int = "ml_elm_init_with_counter"

let init a = ignore (init_with_counter a)

external run : unit -> unit = "ml_elm_run"

external shutdown : unit -> unit = "ml_elm_shutdown"

external exit : unit -> unit = "ml_elm_exit"

external policy_set_bool : policy -> policy_value -> bool = "ml_elm_policy_set"

let policy_set p pv =
  let (_ : bool) = policy_set_bool p pv in
  ()

external need_ethumb : unit -> bool = "ml_elm_need_ethumb"

