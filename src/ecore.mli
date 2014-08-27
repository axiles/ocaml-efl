(** Ecore *)

exception Not_X

exception Not_Wayland

type cb = unit -> unit

type task_cb = unit -> bool

type timer

type window

type x_window

type wl_window

type pos_map = [
  | `linear
  | `accelerate
  | `decelerate
  | `sinusoidal
  | `accelerate_factor
  | `decelerate_factor
  | `sinusoidal_factor
  | `divisor_interp
  | `bounce
  | `spring]

type 'a event_type

type 'a event_handler_cb = 'a event_type -> 'a -> bool

type event_handler

type event

val x_window_focus : x_window -> unit

val main_loop_thread_safe_call_sync : cb -> unit

(** Same thing as Ecore.main_loop_thread_safe_call_sync except that:
- It is shorter to write
- It can return a result
- If an exception is raised by f () then it can be caught by the thread that
called Ecore.call f *)
val call : (unit -> 'a) -> 'a

val event_type_new : unit -> 'a event_type

val event_handler_add : 'a event_type -> 'a event_handler_cb -> event_handler

val event_handler_del : event_handler -> unit

val event_add : 'a event_type -> 'a -> ('a -> unit) -> event

val event_del : event -> unit

