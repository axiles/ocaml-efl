open Hstructs.Evas_event

type obj = Evas.obj
type point = Evas.point
type modifier = Evas.modifier
type coord_point = Evas.coord_point
type device = Evas.device
type button_flags = Evas.button_flags
type position = Evas.position
type coord_precision_point = Evas.coord_precision_point
type precision_position = Evas.precision_position

type flags =  [`none | `on_hold | `on_scroll]

module T = struct
  type evas_object = Evas.obj
  type evas_modifier = Evas.modifier
  type evas_device = Evas.device
  type evas_event_flags = flags
  type evas_point = Evas.point
  type evas_coord_point = Evas.coord_point
  type evas_button_flags = Evas.button_flags
  type evas_position = Evas.position
  type evas_coord_precision_point = Evas.coord_precision_point
  type evas_precision_position = Evas.precision_position
end

(*module Mouse_in = struct
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

type mouse_in = Mouse_in.t*)

module Mmouse_in = Fmouse_in(T)
include Mmouse_in

(*module Mouse_out = struct
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

type mouse_out = Mouse_out.t*)

module Mmouse_out = Fmouse_out(T)
include Mmouse_out

(*module Mouse_down = struct
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

type mouse_down = Mouse_down.t*)

module Mmouse_down = Fmouse_down(T)
include Mmouse_down

(*module Mouse_up = struct
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

type mouse_up = Mouse_up.t*)

module Mmouse_up = Fmouse_up(T)
include Mmouse_up

(*module Mouse_move = struct
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

type mouse_move = Mouse_move.t*)

module Mmouse_move = Fmouse_move(T)
include Mmouse_move

(*module Mouse_wheel = struct
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

type mouse_wheel = Mouse_wheel.t*)

module Mmouse_wheel = Fmouse_wheel(T)
include Mmouse_wheel

(*module Multi_down = struct
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

type multi_down = Multi_down.t*)

module Mmulti_down = Fmulti_down(T)
include Mmulti_down

(*module Multi_up = struct
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

type multi_up = Multi_up.t*)

module Mmulti_up = Fmulti_up(T)
include Mmulti_up

(*module Multi_move = struct
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

type multi_move = Multi_move.t*)

module Mmulti_move = Fmulti_move(T)
include Mmulti_move

(*module Key_down = struct
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

type key_down = Key_down.t*)

module Mkey_down = Fkey_down(T)
include Mkey_down

(*module Key_up = struct
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

type key_up = Key_up.t*)

module Mkey_up = Fkey_up(T)
include Mkey_up

(*module Hold = struct
  type t = {
    hold : int;
    timestamp : int;
    event_flags : flags;
    dev : device;
  }
end

type hold = Hold.t*)

module Mhold = Fhold(T)
include Mhold

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

