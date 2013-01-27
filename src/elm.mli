type policy = [`quit]

type policy_value = [`none | `last_window_closed]

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
]

type cnp_mode = [`markup | `no_image | `plaintext]

type illume_command = [`focus_back | `focus_forward | `focus_home | `close]

val init : string array -> unit

val run : unit -> unit

val shutdown : unit -> unit

val exit : unit -> unit

val init_with_counter : string array -> int

val policy_set : policy -> policy_value -> bool

