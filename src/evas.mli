(** Evas *)

type ptr

type obj

type t

type smart_cb = obj -> ptr -> unit

type modifier

module Point : sig
  type t = {x : int; y : int}
end

type point = Point.t

module Coord_point : sig
  type t = Point.t = {x : int; y : int}
end

type coord_point = Coord_point.t

module Position : sig
  type t = {output : point; canvas : point}
end

type position = Position.t

type event_flags = [`none | `double_click | `triple_click]

type button_flags = [`none | `on_hold | `on_scroll]

type device

module Coord_precision_point : sig
  type t = {x : int; y : int; xsub : float; ysub : float}
end

type coord_precision_point = Coord_precision_point.t

module Precision_position : sig
  type t = {output : point; canvas : coord_precision_point}
end

type precision_position = Precision_position.t

module Event_Mouse_In : sig
  type t = {
    buttons : int;
    output : point;
    canvas : coord_point;
    modifiers : modifier;
    timestamp : int;
    event_flags : event_flags;
    dev : device;
    event_src : obj;
  }
end

type event_mouse_in = Event_Mouse_In.t

module Event_Mouse_Out : sig
  type t = {
    buttons : int;
    output : point;
    canvas : coord_point;
    modifiers : modifier;
    timestamp : int;
    event_flags : event_flags;
    dev : device;
    event_src : obj;
  }
end

type event_mouse_out = Event_Mouse_Out.t

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

module Event_mouse_move : sig
  type t = {
    buttons : int;
    cur : position;
    prev : position;
    modifiers : modifier;
    timestamp : int;
    event_flags : event_flags;
    dev : device;
    event_src : obj;
  }
end

type event_mouse_move = Event_mouse_move.t

module Event_mouse_wheel : sig
  type t = {
    direction : int;
    output : point;
    canvas : coord_point;
    modifiers : modifier;
    timestamp : int;
    event_flags : event_flags;
    dev : device;
  }
end

type event_mouse_wheel = Event_mouse_wheel.t

module Event_multi_down : sig
  type t = {
    device : int;
    radius : float;
    radius_x : float;
    radius_y : float;
    pressure : float;
    angle : float;
    output : point;
    canvas : coord_precision_point;
    modifiers : modifier;
    flags : button_flags;
    timestamp : int;
    event_flags : event_flags;
    dev : device;
  }
end

type event_multi_down = Event_multi_down.t

module Event_multi_up : sig
  type t = {
    device : int;
    radius : float;
    radius_x : float;
    radius_y : float;
    pressure : float;
    angle : float;
    output : point;
    canvas : coord_precision_point;
    modifiers : modifier;
    flags : button_flags;
    timestamp : int;
    event_flags : event_flags;
    dev : device;
  }
end

type event_multi_up = Event_multi_up.t

module Event_multi_move : sig
  type t = {
    device : int;
    radius : float;
    radius_x : float;
    radius_y : float;
    pressure : float;
    angle : float;
    cur : precision_position;
    modifiers : modifier;
    timestamp : int;
    event_flags : event_flags;
    dev : device;
  }
end

type event_multi_move = Event_multi_move.t

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
  | `mouse_in of event_mouse_in
  | `mouse_out of event_mouse_out
  | `mouse_down of event_mouse_down
  | `mouse_up of event_mouse_up
  | `mouse_move of event_mouse_move
  | `mouse_wheel of event_mouse_wheel
  | `multi_down of event_multi_down
  | `multi_up of event_multi_up
  | `multi_move of event_multi_move
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

