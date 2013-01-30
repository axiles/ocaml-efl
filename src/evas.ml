type ptr

type obj

type t

type smart_cb = obj -> ptr -> unit

module Event_type = struct
  type ('a, 'b) t = {name : string; make_cb : 'b -> smart_cb}
  type 'a v = ('a, obj -> 'a -> unit) t
  type u = (unit, obj -> unit) t
  let create name value_of_ptr =
    let make_cb f obj ptr = f obj (value_of_ptr ptr) in
    {name; make_cb}
  let create_unit name =
    let make_cb f obj ptr = f obj in
    {name; make_cb}
  let get_name et = et.name
  let get_cb et f = et.make_cb f
end 

let hint_expand = 1.

let hint_fill = -1.

external string_of_ptr : ptr -> string = "ml_string_of_ptr"

external string_opt_of_ptr : ptr -> string option = "ml_string_opt_of_ptr"

