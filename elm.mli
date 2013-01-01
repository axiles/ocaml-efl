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
]

val init : string array -> unit

val run : unit -> unit

val shutdown : unit -> unit

val exit : unit -> unit

val init_with_counter : string array -> int

val policy_set_with_bool : policy -> policy_value -> bool

val policy_set : policy -> policy_value -> unit

