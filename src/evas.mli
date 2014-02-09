(** Evas *)

type ptr

type obj

type t

type smart_cb = obj -> ptr -> unit

type modifier

module Event_mouse_down : sig
  type t = {
    button : int;
    output_x : int;
    output_y : int;
    canvas_x : int;
    canvas_y : int;
    modifiers : modifier;
    flags_double_click : bool;
    flags_triple_click : bool;
  }
end

type event_mouse_down = Event_mouse_down.t

module Event_mouse_up : sig
  type t = {
    button : int;
    output_x : int;
    output_y : int;
    canvas_x : int;
    canvas_y : int;
    modifiers : modifier;
    flags_double_click : bool;
    flags_triple_click : bool;
  }
end

type event_mouse_up = Event_mouse_up.t

module Event_key_down : sig
  type t = {
    keyname : string;
    modifiers : modifier;
    key : string;
    str : string;
    compose : string;
    timestamp : int;
  }
end

type event_key_down = Event_key_down.t

type event_info = [
  | `mouse_down of event_mouse_down
  | `mouse_up of event_mouse_up
  | `key_down of event_key_down
  | `free
  | `other
]

type aspect_control = [`none | `neither | `horizontal | `vertical | `both]

module Event_type : sig
  type 'a t
  type 'a v = (obj -> 'a -> unit) t
  type 'a r = (obj -> 'a) t
  type u = (obj -> unit) t
  val create : string -> (ptr -> 'a) -> 'a v
  val create_unit : string -> u
  val create_ref : string -> (ptr -> 'a -> unit) -> 'a r
  val get_name : 'a t -> string
  val get_cb : 'a t -> 'a -> smart_cb
end 

type load_error = [
  | `none
  | `generic
  | `does_not_exist
  | `permission_denied
  | `resource_allocation_failed
  | `corrupt_file
  | `unknown_format
]

type gl_api

val hint_expand : float

val hint_fill : float

val string_of_ptr : ptr -> string

val string_opt_of_ptr : ptr -> string option

val pointer_canvas_xy_get : t -> int * int

val smart_objects_calculate : t -> unit

val bool_of_ptr : ptr -> bool

val string_string_of_ptr : ptr -> string * string

val store_ptr_bool : ptr -> bool -> unit

val obj_of_ptr : ptr -> obj

val float_of_ptr : ptr -> float

val color_argb_premul : int -> int -> int -> int -> int * int * int

