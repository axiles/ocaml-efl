open Efl
open Printf

(******************************************************************************)
(* The module Elwt is a helper module for the  interaction between the EFL and
   Lwt.
   It is still experimental, therefore, it is not in a library yet. *)
module Elwt : sig
  (** [Elwt.main f] runs in a premptive thread: [Elm.init ()], [f()],
      [Elm.run ()], and [Elm.shutdown ()].
      The returned result is the result of f ().
      Normally, in [f], you should do the construction of the widgets *)
  val main : (unit -> 'a) -> 'a

  (** [Elwt.detach f] calls [f ()] in the Ecore main loop.
      This function must be called in the Lwt main loop.
      When [f ()] terminates, the returned thread terminates*)
  val detach : (unit -> 'a) -> 'a Lwt.t

  (** [Elwt.bind f g] is the same as [Lwt.bind (detach f) g].
      This function must be called in the Lwt main loop. *)
  val bind : (unit -> 'a) -> ('a -> 'b Lwt.t) -> 'b Lwt.t

  (* [Elwt.async f] calls [f ()] in the Lwt main loop.
     This function must be used in the Ecore main loop, and a call of this
     function does not block the Ecore main loop. *)
  val async : (unit -> unit Lwt.t) -> unit

  (* [Elwt.run f g] calls [f ()] in the Lwt main loop, and then calls [g x]
     in the Ecore main loop with [x] the result of [f ()].
     This function must be called in the Ecore main loop, and while [f ()] is
     not finished, the Ecore main loop still runs normally.*)
  val run : (unit -> 'a Lwt.t) -> ('a -> unit) -> unit
end = struct
  let main f =
    let aux () =
      Elm.init ();
      let x = f () in
      Elm.run ();
      Elm.shutdown ();
      x in
    Lwt_main.run (Lwt_preemptive.detach aux ())

  let detach f =
    let w, u = Lwt.wait () in
    let g () =
      try
        let x = f () in
        Lwt_preemptive.run_in_main (fun () -> Lwt.wakeup u x; Lwt.return_unit)
      with exn ->
        Lwt_preemptive.run_in_main (fun () ->
          Lwt.wakeup_exn u exn; Lwt.return_unit) in
    Ecore.main_loop_thread_safe_call_async g;
    w

  let bind f g = Lwt.bind (detach f) g

  let async f =
    Lwt_preemptive.run_in_main (fun () -> Lwt.async f; Lwt.return_unit)

  let run f g =
    async (fun () ->
      Lwt.bind (f ()) (fun x ->
      detach (fun () -> g x)))
end
(******************************************************************************)

let add_button window box list text =
  let btn = Elm_button.add window in
  Elm_object.text_set btn (sprintf "Print %s" text);
  let clicked_cb obj =
    Elwt.async (fun () ->
      let rec loop i =
        if i > 10 then Lwt.return_unit
        else
          Elwt.bind (fun () ->
            ignore (Elm_list.item_append list ~label:text ());
            Elm_list.go list
          ) (fun () ->
          Lwt.bind (Lwt_unix.sleep 0.5) (fun () ->
          loop (i + 1))) in
      loop 0
    ) in
  Elm_connect.Button.clicked btn clicked_cb;
  Elm_box.pack_end box btn;
  Evas_object.show btn

let elm_init () =
  Elm.policy_quit_set `last_window_closed;
  let window = Elm_win.add "two buttons" `basic in
  Elm_win.autodel_set window true;

  let bg = Elm_bg.add window in
  Elm_win.resize_object_add window bg;
  Evas_object.show bg;

  let box = Elm_box.add window in
  Elm_win.resize_object_add window box;
  Evas_object.show box;

  let box1 = Elm_box.add window in
  Elm_box.horizontal_set box1 true;
  Elm_box.pack_end box box1;
  Evas_object.show box1;

  let list = Elm_list.add window in
  Elm_box.pack_end box list;
  Elm_list.mode_set list `expand;
  Evas_object.size_hint_align_set list Evas.hint_fill Evas.hint_fill;
  Evas_object.show list;

  add_button window box1 list "A";
  add_button window box1 list "B";

  Evas_object.show window

let () = Elwt.main elm_init

