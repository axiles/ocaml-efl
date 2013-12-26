type ptr

type obj

type t

type smart_cb = obj -> ptr -> unit

type modifier

type event_mouse_down = {
  button : int;
  output_x : int;
  output_y : int;
  canvas_x : int;
  canvas_y : int;
  modifiers : modifier;
  flags_double_click : bool;
  flags_triple_click : bool;
}

type aspect_control = [`none | `neither | `horizontal | `vertical | `both]

module Event_type : sig
  type 'a t
  type 'a v = (obj -> 'a -> unit) t
  type u = (obj -> unit) t
  val create : string -> (ptr -> 'a) -> 'a v
  val create_unit : string -> u
  val get_name : 'a t -> string
  val get_cb : 'a t -> 'a -> smart_cb
end 

val hint_expand : float

val hint_fill : float

val string_of_ptr : ptr -> string

val string_opt_of_ptr : ptr -> string option

