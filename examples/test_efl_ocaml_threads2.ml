open Efl
open Printf

let add_button window box list text =
  let btn = Elm_button.add window in
  Elm_object.text_set btn (sprintf "Print %s" text);
  let thread_cb () =
    for i = 0 to 10 do
      (*Ecore_thread.main_loop_begin ();*)
      Ecore.main_loop_thread_safe_call_sync (fun () ->
        let (_ : Elm_object.item) = Elm_list.item_append list ~label:text () in
        Elm_list.go list);
      (*Ecore_thread.main_loop_end ();*)
      Thread.delay 0.5;
    done in
  let clicked_cb obj =
    let (_ : Thread.t) = Thread.create thread_cb () in
    () in
  Evas_object_smart.callback_add btn Elm_button.E.clicked clicked_cb;
  Elm_box.pack_end box btn;
  Evas_object.show btn

let () =
  Elm.init ();
  Elm.policy_set `quit `last_window_closed;
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

  Evas_object.show window;
  Elm.run ();
  Elm.shutdown ()

