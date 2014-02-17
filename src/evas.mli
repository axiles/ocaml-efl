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

type aspect_control = [`none | `neither | `horizontal | `vertical | `both]

module Signal : sig
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

(** {2 Top Level Functions} *)

val init : unit -> int

val shutdown : unit -> int

