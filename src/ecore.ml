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

type pos_map = Henums.Ecore.pos_map

external x_window_focus : x_window -> unit = "ml_ecore_x_window_focus"

external main_loop_thread_safe_call_sync : cb -> unit =
  "ml_ecore_main_loop_thread_safe_call_sync"

let call f =
  let r = ref None and r_e = ref None in
  let g () =
    try r := Some (f ()) with e -> r_e := Some e in
  main_loop_thread_safe_call_sync g;
  (match !r_e with None -> () | Some e -> raise e);
  match !r with None -> assert false | Some x -> x

