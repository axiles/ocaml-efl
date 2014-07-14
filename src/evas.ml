type ptr

type obj

type t

type smart_cb = obj -> ptr -> unit

type modifier

type callback_priority = [`after | `before | `default | `other of int]

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

module Button_flags = struct
  type t = {double_click : bool; triple_click : bool}
end

type button_flags = Button_flags.t

type device

module Coord_precision_point = struct
  type t = {x : int; y : int; xsub : float; ysub : float}
end

type coord_precision_point = Coord_precision_point.t

module Precision_position = struct
  type t = {output : point; canvas : coord_precision_point}
end

type precision_position = Precision_position.t

type aspect_control = Henums.Evas.aspect_control

type load_error = Henums.Evas.load_error

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

type map

type display_mode = Henums.Evas.display_mode

type render_op = Henums.Evas.render_op

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

(* Top Level Functions *)

type alloc_error = Henums.Evas.alloc_error

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

(* Output and viewport Resizing Functions *)

external output_size_set : t -> int -> int -> unit = "ml_evas_output_size_set"

external output_size_get : t -> int * int = "ml_evas_output_size_get"

external output_viewport_set : t -> int -> int -> int -> int -> unit =
  "ml_evas_output_viewport_set"

external output_viewport_get : t -> int * int * int * int =
  "ml_evas_output_viewport_get"

external output_framespace_set : t -> int -> int -> int -> int -> unit =
  "ml_evas_output_framespace_set"

external output_framespace_get : t -> int * int * int * int =
  "ml_evas_output_framespace_get"

(* Image Functions *)

external image_cache_flush : t -> unit = "ml_evas_image_cache_flush"

external image_cache_reload : t -> unit = "ml_evas_image_cache_reload"

external image_cache_set : t -> int -> unit = "ml_evas_image_cache_set"

external image_cache_get : t -> int = "ml_evas_image_cache_get"

external image_max_size_get : t -> (int * int) option =
  "ml_evas_image_max_size_get"

(* General Canvas Functions *)

external new_ : unit -> t = "ml_evas_new"

external free : t -> unit = "ml_evas_free"

external focus_in : t -> unit = "ml_evas_focus_in"

external focus_out : t -> unit = "ml_evas_focus_out"

external focus_state_get : t -> bool = "ml_evas_focus_state_get"

external nochange_push : t -> unit = "ml_evas_nochange_push"

external nochange_pop : t -> unit = "ml_evas_nochange_pop"

external damage_rectangle_add : t -> int -> int -> int -> int -> unit =
  "ml_evas_damage_rectangle_add"

external obscured_rectangle_add : t -> int -> int -> int -> int -> unit =
  "ml_evas_obscured_rectangle_add"

external obscured_clear : t -> unit = "ml_evas_obscured_clear"

external render_async : t -> bool = "ml_evas_render_async"

external render_updates : t -> (int * int * int * int) list =
  "ml_evas_render_updates"

external render : t -> unit = "ml_evas_render"

external norender : t -> unit = "ml_evas_norender"

external render_idle_flush : t -> unit = "ml_evas_render_idle_flush"

external render_dump : t -> unit = "ml_evas_render_dump"

(* Input Evas Feeding Functions *)

external device_add : t -> device = "ml_evas_device_add"

external device_del : device -> unit = "ml_evas_device_del"

external device_push : t -> device -> unit = "ml_evas_device_push"

external device_pop : t -> unit = "ml_evas_device_pop"

external device_list : t -> device option -> device list = "ml_evas_device_list"

external device_name_set : device -> string -> unit = "ml_evas_device_name_set"

external device_name_get : device -> string option = "ml_evas_device_name_get"

external device_description_set : device -> string -> unit =
  "ml_evas_device_description_set"

external device_description_get : device -> string option =
  "ml_evas_device_description_get"

external device_parent_set : device -> device option -> unit =
  "ml_evas_device_parent_set"

external device_parent_get : device -> device option =
  "ml_evas_device_parent_get"

(* Finding Objects *)

external focus_get : t -> obj option = "ml_evas_focus_get"

external objects_at_xy_get : t -> int -> int -> bool -> bool -> obj list =
  "ml_evas_objects_at_xy_get"

external objects_in_rectangle_get :
  t -> int -> int -> int -> int -> bool -> bool -> obj list =
    "ml_evas_objects_in_rectangle_get_byte"
    "ml_evas_objects_in_rectangle_get_native"

(* Shared Image Cache Server *)

type cserve_stats = {
  saved_memory : int;
  wasted_memory : int;
  save_memory_peak : int;
  wasted_memory_peak : int;
  saved_time_image_header_load : float;
  saved_time_image_data_load : float;
}

type cserve_config = {
  cache_max_usage : int;
  cache_item_timeout : int;
  cache_item_timeout_check : int;
}

external cserve_want_get : unit -> bool = "ml_evas_cserve_want_get"

external cserve_connected_get : unit -> bool = "ml_evas_cserve_connected_get"

external cserve_stats_get : unit -> cserve_stats option =
  "ml_evas_cserve_stats_get"

external cserve_config_get : unit -> cserve_config option =
  "ml_evas_cserve_config_get"

external cserve_config_set : cserve_config -> bool = "ml_evas_cserve_config_set"

external cserve_disconnected : unit -> unit = "ml_evas_cserve_disconnected"

(* General Utilities *)

external load_error_str : load_error -> string = "ml_evas_load_error_str"

external color_hsv_to_rgb : float -> float -> float -> int * int * int =
  "ml_evas_color_hsv_to_rgb"

external color_rgb_to_hsv : int -> int -> int -> float * float * float =
  "ml_evas_color_rgb_to_hsv"

external color_argb_premul : int -> int -> int -> int -> int * int * int =
  "ml_evas_color_argb_premul"

external color_argb_unpremul : int -> int -> int -> int -> int * int * int =
  "ml_evas_color_argb_unpremul"

external data_argb_premul : int array -> unit = "ml_evas_data_argb_premul"

external data_argb_unpremul : int array -> unit = "ml_evas_data_argb_unpremul"

external string_char_next_get : string -> int -> int * Int32.t =
  "ml_evas_string_char_next_get"

external string_char_prev_get : string -> int -> int * Int32.t =
  "ml_evas_string_char_prev_get"

external string_char_len_get : string -> int = "ml_evas_string_char_len_get"

