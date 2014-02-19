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

type alloc_error = [`none | `fatal | `recovered]

val init : unit -> int

val shutdown : unit -> int

val alloc_error : unit -> alloc_error

val async_events_fd_get : unit -> int

val async_events_process : unit -> int

(** {2 Render Engine Functions} *)

val render_method_lookup : string -> int

val render_method_list : unit -> string list

val output_method_set : t -> int -> unit

val output_method_get : t -> int

(** {2 Coordinate Mapping Functions} *)

val coord_screen_x_to_world : t -> int -> int

val coord_screen_y_to_world : t -> int -> int

val coord_world_x_to_screen : t -> int -> int

val coord_world_y_to_screen : t -> int -> int

(** {2 Output and Viewport Resizing Functions} *)

val output_size_set : t -> int -> int -> unit

val output_size_get : t -> int * int

val output_viewport_set : t -> int -> int -> int -> int -> unit

val output_viewport_get : t -> int * int * int * int

val output_framespace_set : t -> int -> int -> int -> int -> unit

val output_framespace_get : t -> int * int * int * int

(** {2 Image Functions} *)

val image_cache_flush : t -> unit

val image_cache_reload : t -> unit

