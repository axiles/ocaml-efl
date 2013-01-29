type ptr

type obj

type t

type smart_cb = obj -> ptr -> unit

let hint_expand = 1.

let hint_fill = -1.

external string_of_ptr : ptr -> string = "ml_string_of_ptr"

