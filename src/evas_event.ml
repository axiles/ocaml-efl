type obj = Evas.obj
type point = Evas.point
type modifier = Evas.modifier
type coord_point = Evas.coord_point
type device = Evas.device
type button_flags = Evas.button_flags
type position = Evas.position
type coord_precision_point = Evas.coord_precision_point
type precision_position = Evas.precision_position

type flags = [`none | `double_click | `triple_click]

module Mouse_in = struct
  type t = {
    buttons : int;
    output : point;
    canvas : coord_point;
    modifiers : modifier;
    timestamp : int;
    event_flags : flags;
    dev : device;
    event_src : obj;
  }
end

type mouse_in = Mouse_in.t

module Mouse_out = struct
  type t = {
    buttons : int;
    output : point;
    canvas : coord_point;
    modifiers : modifier;
    timestamp : int;
    event_flags : flags;
    dev : device;
    event_src : obj;
  }
end

type mouse_out = Mouse_out.t

module Mouse_down = struct
  type t = {
    button : int;
    output : point;
    canvas : coord_point;
    modifiers : modifier;
    flags : button_flags;
    timestamp : int;
    event_flags : flags;
    dev : device;
    event_src : obj;
  }
end

type mouse_down = Mouse_down.t

module Mouse_up = struct
  type t = {
    button : int;
    output : point;
    canvas : coord_point;
    modifiers : modifier;
    flags : button_flags;
    timestamp : int;
    event_flags : flags;
    dev : device;
    event_src : obj;
  }
end

type mouse_up = Mouse_up.t

module Mouse_move = struct
  type t = {
    buttons : int;
    cur : position;
    prev : position;
    modifiers : modifier;
    timestamp : int;
    event_flags : flags;
    dev : device;
    event_src : obj;
  }
end

type mouse_move = Mouse_move.t

module Mouse_wheel = struct
  type t = {
    direction : int;
    output : point;
    canvas : coord_point;
    modifiers : modifier;
    timestamp : int;
    event_flags : flags;
    dev : device;
  }
end

type mouse_wheel = Mouse_wheel.t

module Multi_down = struct
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
    event_flags : flags;
    dev : device;
  }
end

type multi_down = Multi_down.t

module Multi_up = struct
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
    event_flags : flags;
    dev : device;
  }
end

type multi_up = Multi_up.t

module Multi_move = struct
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
    event_flags : flags;
    dev : device;
  }
end

type multi_move = Multi_move.t

module Key_down = struct
  type t = {
    keyname : string;
    modifiers : modifier;
    key : string;
    string : string;
    compose : string;
    timestamp : int;
    event_flags : flags;
    dev : device;
  }
end

type key_down = Key_down.t

module Key_up = struct
  type t = {
    keyname : string;
    modifiers : modifier;
    key : string;
    string : string;
    compose : string;
    timestamp : int;
    event_flags : flags;
    dev : device;
  }
end

type key_up = Key_up.t

module Hold = struct
  type t = {
    hold : int;
    timestamp : int;
    event_flags : flags;
    dev : device;
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

(* Canvas Events *)

type 'a cb = Evas.t -> 'a -> unit

type post_cb = Evas.t -> unit

external callback_add_render_flush_pre : Evas.t -> unit cb -> unit =
  "ml_evas_event_callback_add_render_flush_pre"

external callback_add_render_flush_post : Evas.t -> unit cb -> unit =
  "ml_evas_event_callback_add_render_flush_post"

external callback_add_canvas_focus_in : Evas.t -> unit cb -> unit =
  "ml_evas_event_callback_add_canvas_focus_in"

external callback_add_canvas_focus_out : Evas.t -> unit cb -> unit =
  "ml_evas_event_callback_add_canvas_focus_out"

external callback_add_canvas_object_focus_in : Evas.t -> Evas.obj cb -> unit =
  "ml_evas_event_callback_add_canvas_object_focus_in"

external callback_add_canvas_object_focus_out : Evas.t -> Evas.obj cb -> unit =
  "ml_evas_event_callback_add_canvas_object_focus_out"

external callback_priority_add_render_flush_pre :
  Evas.t -> Evas.callback_priority -> unit cb -> unit =
    "ml_evas_event_callback_priority_add_render_flush_pre"

external callback_priority_add_render_flush_post :
  Evas.t -> Evas.callback_priority -> unit cb -> unit =
    "ml_evas_event_callback_priority_add_render_flush_post"

external callback_priority_add_canvas_focus_in :
  Evas.t -> Evas.callback_priority -> unit cb -> unit =
    "ml_evas_event_callback_priority_add_canvas_focus_in"

external callback_priority_add_canvas_focus_out :
  Evas.t -> Evas.callback_priority -> unit cb -> unit =
    "ml_evas_event_callback_priority_add_canvas_focus_out"

external callback_priority_add_canvas_object_focus_in :
  Evas.t -> Evas.callback_priority -> Evas.obj cb -> unit =
    "ml_evas_event_callback_priority_add_canvas_object_focus_in"

external callback_priority_add_canvas_object_focus_out :
  Evas.t -> Evas.callback_priority -> Evas.obj cb -> unit =
    "ml_evas_event_callback_priority_add_canvas_object_focus_out"

external post_callback_push : Evas.t -> post_cb -> unit =
  "ml_evas_post_event_callback_push"

(* Input Events Freezing/Feeding *)

external freeze : Evas.t -> unit = "ml_evas_event_freeze"

external thaw : Evas.t -> unit = "ml_evas_event_thaw"

