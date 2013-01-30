type ptr

type obj

type t

type smart_cb = obj -> ptr -> unit

module Event_type : sig
  type ('a, 'b) t
  type 'a v = ('a, obj -> 'a -> unit) t
  type u = (unit, obj -> unit) t
  val create : string -> (ptr -> 'a) -> 'a v
  val create_unit : string -> u
  val get_name : ('a, 'b) t -> string
  val get_cb : ('a, 'b) t -> 'b -> smart_cb
end 

val hint_expand : float

val hint_fill : float

val string_of_ptr : ptr -> string

val string_opt_of_ptr : ptr -> string option

