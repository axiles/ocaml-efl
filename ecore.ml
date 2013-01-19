exception Not_X

let _ = Callback.register_exception "Not_X exception" Not_X

exception Not_Wayland

let _ = Callback.register_exception "Not_Wayland exception" Not_Wayland

type cb = unit -> unit

