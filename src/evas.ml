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

type event_flags = [`none | `double_click | `triple_click]

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

module Event_Mouse_In = struct
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

module Event_Mouse_Out = struct
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

module Event_mouse_down = struct
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

module Event_mouse_up = struct
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

module Event_mouse_move = struct
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

module Event_mouse_wheel = struct
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

module Event_multi_down = struct
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

module Event_multi_up = struct
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

module Event_multi_move = struct
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

module Event_key_down = struct
  type t = {
    keyname : string;
    modifiers : modifier;
    key : string;
    string : string;
    compose : string;
    timestamp : int;
    event_flags : event_flags;
    dev : device;
  }
end

type event_key_down = Event_key_down.t

module Event_key_up = struct
  type t = {
    keyname : string;
    modifiers : modifier;
    key : string;
    string : string;
    compose : string;
    timestamp : int;
    event_flags : event_flags;
    dev : device;
  }
end

type event_key_up = Event_key_up.t

module Event_hold = struct
  type t = {
    hold : int;
    timestamp : int;
    event_flags : event_flags;
    dev : device;
  }
end

type event_hold = Event_hold.t

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
  | `free
  | `key_down of event_key_down
  | `key_up of event_key_up
  | `focus_in
  | `focus_out
  | `show
  | `hide
  | `move
  | `resize
  | `restack
  | `del
  | `hold of event_hold
  | `changed_size_hints
  | `image_preloaded
  | `canvas_focus_in
  | `canvas_focus_out
  | `render_flush_pre
  | `render_flush_post
  | `canvas_object_focus_in
  | `canvas_object_focus_out
  | `image_unloaded
  | `render_pre
  | `render_post
  | `image_resize
  | `device_changed
  | `last
]

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

module Event_type = struct
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

