(* WARNING: this example is still under developpment *)

open Efl
open Printf

let commands =
  "commands are:\n\
  \tn - flip to next item\n\
  \tp - flip to previous item\n\                    
  \tf - print first item's label\n\
  \tl - print last item's label\n\
  \ts - print selected item's label\n\
  \th - print help\n"

let unsel_cb fp obj =
  match Elm_flipselector.selected_item_get fp with
  | None -> ()
  | Some it -> Elm_flipselector.item_selected_set it false

let del_cb fp obj =
  match Elm_flipselector.selected_item_get fp with
  | None -> ()
  | Some it -> Elm_object.item_del it

let underflow_cb obj = print_endline "Underflow!"

let overflow_cb obj = print_endline "Overflow!"

let lbl =
  ["Elementary"; "Evas"; "Eina"; "Edje"; "Eet"; "Ecore"; "Efreet"; "Eldbus"]

let () =
  Elm.init ();
  Elm.policy_quit_set `last_window_closed;

  let win = Elm_win.util_standard_add "flipselector" "Flipselector" in
  Elm_win.autodel_set win true;

  let bx = Elm_box.add win in
  Evas_object.size_hint_set bx [`expand];
  Elm_win.resize_object_add win bx;
  Evas_object.show bx;

  let fp = Elm_flipselector.add win in
  Evas_object.size_hint_set fp [`expand];
  Evas_object_smart.callback_add fp Elm_sig.overflowed overflow_cb;
  Evas_object_smart.callback_add fp Elm_sig.underflowed underflow_cb;
  let add_item label =
    ignore (Elm_flipselector.item_append fp ~label () : Elm_object.item) in
  List.iter add_item lbl;
  Elm_box.pack_end bx fp;
  Evas_object.show fp;

  let add_bt label cb =
    let bt = Elm_button.add win in
    Elm_object.text_set bt label;
    Evas_object_smart.callback_add bt Elm_sig.clicked (cb fp);
    Elm_box.pack_end bx bt;
    Evas_object.show bt in
  add_bt "Unselect item" unsel_cb;
  add_bt "Delete item" del_cb;

  Evas_object.show win;
  printf "%s%!" commands;

  Elm.run ();
  Elm.shutdown ()

