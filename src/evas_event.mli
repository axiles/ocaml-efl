type flags = [`none | `double_click | `triple_click]

type 'a cb = Evas.t -> 'a -> unit

module Mouse_in : sig
  type t = {
    buttons : int;
    output : Evas.point;
    canvas : Evas.coord_point;
    modifiers : Evas.modifier;
    timestamp : int;
    event_flags : flags;
    dev : Evas.device;
    event_src : Evas.obj;
  }
end

type mouse_in = Mouse_in.t

module Mouse_out : sig
  type t = {
    buttons : int;
    output : Evas.point;
    canvas : Evas.coord_point;
    modifiers : Evas.modifier;
    timestamp : int;
    event_flags : flags;
    dev : Evas.device;
    event_src : Evas.obj;
  }
end

type mouse_out = Mouse_out.t

module Mouse_down : sig
  type t = {
    button : int;
    output : Evas.point;
    canvas : Evas.coord_point;
    modifiers : Evas.modifier;
    flags : Evas.button_flags;
    timestamp : int;
    event_flags : flags;
    dev : Evas.device;
    event_src : Evas.obj;
  }
end

type mouse_down = Mouse_down.t

module Mouse_up : sig
  type t = {
    button : int;
    output : Evas.point;
    canvas : Evas.coord_point;
    modifiers : Evas.modifier;
    flags : Evas.button_flags;
    timestamp : int;
    event_flags : flags;
    dev : Evas.device;
    event_src : Evas.obj;
  }
end

type mouse_up = Mouse_up.t

module Mouse_move : sig
  type t = {
    buttons : int;
    cur : Evas.position;
    prev : Evas.position;
    modifiers : Evas.modifier;
    timestamp : int;
    event_flags : flags;
    dev : Evas.device;
    event_src : Evas.obj;
  }
end

type mouse_move = Mouse_move.t

module Mouse_wheel : sig
  type t = {
    direction : int;
    output : Evas.point;
    canvas : Evas.coord_point;
    modifiers : Evas.modifier;
    timestamp : int;
    event_flags : flags;
    dev : Evas.device;
  }
end

type mouse_wheel = Mouse_wheel.t

module Multi_down : sig
  type t = {
    device : int;
    radius : float;
    radius_x : float;
    radius_y : float;
    pressure : float;
    angle : float;
    output : Evas.point;
    canvas : Evas.coord_precision_point;
    modifiers : Evas.modifier;
    flags : Evas.button_flags;
    timestamp : int;
    event_flags : flags;
    dev : Evas.device;
  }
end

type multi_down = Multi_down.t

module Multi_up : sig
  type t = {
    device : int;
    radius : float;
    radius_x : float;
    radius_y : float;
    pressure : float;
    angle : float;
    output : Evas.point;
    canvas : Evas.coord_precision_point;
    modifiers : Evas.modifier;
    flags : Evas.button_flags;
    timestamp : int;
    event_flags : flags;
    dev : Evas.device;
  }
end

type multi_up = Multi_up.t

module Multi_move : sig
  type t = {
    device : int;
    radius : float;
    radius_x : float;
    radius_y : float;
    pressure : float;
    angle : float;
    cur : Evas.precision_position;
    modifiers : Evas.modifier;
    timestamp : int;
    event_flags : flags;
    dev : Evas.device;
  }
end

type multi_move = Multi_move.t

module Key_down : sig
  type t = {
    keyname : string;
    modifiers : Evas.modifier;
    key : string;
    string : string;
    compose : string;
    timestamp : int;
    event_flags : flags;
    dev : Evas.device;
  }
end

type key_down = Key_down.t

module Key_up : sig
  type t = {
    keyname : string;
    modifiers : Evas.modifier;
    key : string;
    string : string;
    compose : string;
    timestamp : int;
    event_flags : flags;
    dev : Evas.device;
  }
end

type key_up = Key_up.t

module Hold : sig
  type t = {
    hold : int;
    timestamp : int;
    event_flags : flags;
    dev : Evas.device;
  }
end

type hold = Hold.t

type t = [
  | `mouse_in of mouse_in
  | `mouse_out of mouse_out
  | `mouse_down of mouse_down
  | `mouse_up of mouse_up
  | `mouse_move of mouse_move
  | `mouse_wheel of mouse_wheel
  | `multi_down of multi_down
  | `multi_up of multi_up
  | `multi_move of multi_move
  | `free
  | `key_down of key_down
  | `key_up of key_up
  | `focus_in
  | `focus_out
  | `show
  | `hide
  | `move
  | `resize
  | `restack
  | `del
  | `hold of hold
  | `changed_size_hints
  | `image_preloaded
  | `canvas_focus_in
  | `canvas_focus_out
  | `render_flush_pre
  | `render_flush_post
  | `canvas_object_focus_in of Evas.obj
  | `canvas_object_focus_out of Evas.obj
  | `image_unloaded
  | `render_pre
  | `render_post
  | `image_resize
  | `device_changed
  | `last
]

val callback_add_render_flush_pre : Evas.t -> unit cb -> unit

val callback_add_render_flush_post : Evas.t -> unit cb -> unit

val callback_add_canvas_focus_in : Evas.t -> unit cb -> unit

val callback_add_canvas_focus_out : Evas.t -> unit cb -> unit

val callback_add_canvas_object_focus_in : Evas.t -> Evas.obj cb -> unit

val callback_add_canvas_object_focus_out : Evas.t -> Evas.obj cb -> unit

