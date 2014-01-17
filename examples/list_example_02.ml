open Efl
open Elm_sig

let on_done _ = Elm.exit ()

let lbl = [
  "Sunday"; "Monday"; "Tuesday"; "Wednesday"; "Thursday"; "Friday"; "Saturday"]

let () =
  Elm.init ();

  let win = Elm_win.add "list" `basic in
  Elm_win.title_set win "List Example";
  Evas_object_smart.callback_add win delete_request on_done;

  let bg = Elm_bg.add win in
  Elm_win.resize_object_add win bg;
  Evas_object.size_hint_weight_set bg Evas.hint_expand Evas.hint_expand;
  Evas_object.show bg;

  let bx = Elm_box.add win in
  Evas_object.size_hint_weight_set bx Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set bx Evas.hint_fill Evas.hint_fill;
  Elm_win.resize_object_add win bx;
  Evas_object.show bx;

  let li = Elm_list.add win in
  Evas_object.size_hint_weight_set li Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set li Evas.hint_fill Evas.hint_fill;
  Elm_box.pack_end bx li;
  let iter_aux s =
    let (_ : Elm_object.item) = Elm_list.item_append li ~label:s () in () in
  List.iter iter_aux lbl;

  Elm_list.horizontal_set li true;
  Elm_list.mode_set li `compress;

  Elm_list.multi_select_set li true;
  Elm_list.select_mode_set li `always;

  Elm_scroller.bounce_set li true true;
  Elm_scroller.policy_set li `auto `on;

  Evas_object.show li;
  Elm_list.go li;

  Evas_object.resize win 320 240;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()
