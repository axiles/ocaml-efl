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

val x_window_focus : x_window -> unit

val main_loop_thread_safe_call_sync : cb -> unit

(** Same thing as Ecore.main_loop_thread_safe_call_sync except that:
- It is shorter to write
- It can return a result
- If an exception is raised by f () then it can be caught by the thread that
called Ecore.call f *)
val call : (unit -> 'a) -> 'a

