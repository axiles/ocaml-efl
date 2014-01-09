exception Not_X

exception Not_Wayland

type cb = unit -> unit

type task_cb = unit -> bool

type timer

type window

type x_window

type wl_window

val x_window_focus : x_window -> unit

val main_loop_thread_safe_call_sync : cb -> unit

