external main_loop_begin_int : unit -> int = "ml_ecore_thread_main_loop_begin"

let main_loop_begin () =
  let (_ : int) = main_loop_begin_int () in
  ()

external main_loop_end_int : unit -> int = "ml_ecore_thread_main_loop_end"

let main_loop_end () =
  let (_ : int) = main_loop_end_int () in
  ()

