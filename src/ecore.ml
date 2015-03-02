include Henums.Ecore

exception Not_X

let _ = Callback.register_exception "Not_X exception" Not_X

exception Not_Wayland

let _ = Callback.register_exception "Not_Wayland exception" Not_Wayland

type cb = unit -> unit

type task_cb = unit -> bool

type timer

type window

type evas

type x_window = int

type wl_window

type 'a event_type (* It is an integer *)

type event

type event_handler

type 'a event_handler_cb = 'a event_type -> 'a -> bool

external x_window_focus : x_window -> unit = "ml_ecore_x_window_focus"

external main_loop_thread_safe_call_async : cb -> unit =
  "ml_ecore_main_loop_thread_safe_call_async"

external main_loop_thread_safe_call_sync : cb -> unit =
  "ml_ecore_main_loop_thread_safe_call_sync"

let call f =
  let r = ref None and r_e = ref None in
  let g () =
    try r := Some (f ()) with e -> r_e := Some e in
  main_loop_thread_safe_call_sync g;
  (match !r_e with None -> () | Some e -> raise e);
  match !r with None -> assert false | Some x -> x

external event_type_new : unit -> 'a event_type =
  "ml_ecore_event_type_new"

external event_handler_add :
  'a event_type -> 'a event_handler_cb -> event_handler =
    "ml_ecore_event_handler_add"

external event_handler_del : event_handler -> unit =
  "ml_ecore_event_handler_del"

external event_add : 'a event_type -> 'a -> ('a -> unit) -> event =
  "ml_ecore_event_add"

external event_del : event -> unit = "ml_ecore_event_del"

