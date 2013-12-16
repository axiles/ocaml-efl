exception Not_X

let _ = Callback.register_exception "Not_X exception" Not_X

exception Not_Wayland

let _ = Callback.register_exception "Not_Wayland exception" Not_Wayland

type cb = unit -> unit

type task_cb = unit -> bool

type timer

type window

type x_window = int

type wl_window

external x_window_focus : x_window -> unit = "ml_ecore_x_window_focus"

