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

module Mmouse_in = Fmouse_in(T)
include Mmouse_in

module Mmouse_out = Fmouse_out(T)
include Mmouse_out

module Mmouse_down = Fmouse_down(T)
include Mmouse_down

module Mmouse_up = Fmouse_up(T)
include Mmouse_up

module Mmouse_move = Fmouse_move(T)
include Mmouse_move

module Mmouse_wheel = Fmouse_wheel(T)
include Mmouse_wheel

module Mmulti_down = Fmulti_down(T)
include Mmulti_down

module Mmulti_up = Fmulti_up(T)
include Mmulti_up

module Mmulti_move = Fmulti_move(T)
include Mmulti_move

module Mkey_down = Fkey_down(T)
include Mkey_down

module Mkey_up = Fkey_up(T)
include Mkey_up

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

