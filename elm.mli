type policy = [`quit]

type policy_value = [`none | `last_window_closed]

val init : string array -> unit

val run : unit -> unit

val shutdown : unit -> unit

val exit : unit -> unit

val init_with_counter : string array -> int

val policy_set_with_bool : policy -> policy_value -> bool

val policy_set : policy -> policy_value -> unit

