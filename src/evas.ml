type ptr

type obj

type t

type smart_cb = obj -> ptr -> unit

type modifier

module Point = struct
  type t = {x : int; y : int}
end

type point = Point.t

module Coord_point = struct
  type t = Point.t = {x : int; y : int}
end

type coord_point = Coord_point.t

module Position = struct
  type t = {output : point; canvas : point}
end

type position = Position.t

type button_flags = [`none | `on_hold | `on_scroll]

type device

module Coord_precision_point = struct
  type t = {x : int; y : int; xsub : float; ysub : float}
end

type coord_precision_point = Coord_precision_point.t

module Precision_position = struct
  type t = {output : point; canvas : coord_precision_point}
end

type precision_position = Precision_position.t

type aspect_control = [`none | `neither | `horizontal | `vertical | `both]

type load_error = [
  | `none
  | `generic
  | `does_not_exist
  | `permission_denied
  | `resource_allocation_failed
  | `corrupt_file
  | `unknown_format
]

module Signal = struct
  type 'a t = {name : string; make_cb : 'a -> smart_cb}
  type 'a v = (obj -> 'a -> unit) t
  type u = (obj -> unit) t
  type 'a r = (obj -> 'a) t
  let create name value_of_ptr =
    let make_cb f obj ptr = f obj (value_of_ptr ptr) in
    {name; make_cb}
  let create_unit name =
    let make_cb f obj ptr = f obj in
    {name; make_cb}
  let create_ref name store_ptr =
    let make_cb f obj ptr =
      let x = f obj in store_ptr ptr x in
    {name; make_cb}
  let get_name et = et.name
  let get_cb et f = et.make_cb f
end 

type gl_api

let hint_expand = 1.

let hint_fill = -1.

external string_of_ptr : ptr -> string = "ml_string_of_ptr"

external string_opt_of_ptr : ptr -> string option = "ml_string_opt_of_ptr"

external pointer_canvas_xy_get : t -> int * int =
  "ml_evas_pointer_canvas_xy_get"

external smart_objects_calculate : t -> unit =
  "ml_evas_smart_objects_calculate"

external bool_of_ptr : ptr -> bool = "ml_bool_of_ptr"

external string_string_of_ptr : ptr -> string * string =
  "ml_string_string_of_ptr"

external store_ptr_bool : ptr -> bool -> unit = "ml_store_ptr_bool"

external obj_of_ptr : ptr -> obj = "ml_obj_of_ptr"

external float_of_ptr : ptr -> float = "ml_float_of_ptr"

external color_argb_premul : int -> int -> int -> int -> int * int * int =
  "ml_evas_color_argb_premul"

(* Top Level Functions *)

type alloc_error = [`none | `fatal | `recovered]

external init : unit -> int = "ml_evas_init"

external shutdown : unit -> int = "ml_evas_shutdown"

external alloc_error : unit -> alloc_error = "ml_evas_alloc_error"

external async_events_fd_get : unit -> int = "ml_evas_async_events_fd_get"

external async_events_process : unit -> int =
  "ml_evas_async_events_process"

(* Render Engine Functions *)

external render_method_lookup : string -> int = "ml_evas_render_method_lookup"

external render_method_list : unit -> string list = "ml_evas_render_method_list"

external output_method_set : t -> int -> unit = "ml_evas_output_method_set"

external output_method_get : t -> int = "ml_evas_output_method_get"

(* Coordinate Mapping Functions *)

external coord_screen_x_to_world : t -> int -> int =
  "ml_evas_coord_screen_x_to_world"

external coord_screen_y_to_world : t -> int -> int =
  "ml_evas_coord_screen_y_to_world"

external coord_world_x_to_screen : t -> int -> int =
  "ml_evas_coord_world_x_to_screen"

external coord_world_y_to_screen : t -> int -> int =
  "ml_evas_coord_world_y_to_screen"

