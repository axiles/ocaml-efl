(* Compared to the official example, this example does not have box transitions
yet. *)

open Efl

let () =
  Elm.init Sys.argv;
  let (_: bool) = Elm.policy_set `quit `last_window_closed in

  let win = Elm_win.add "box-transition" `basic; in
  Elm_win.title_set win "Box transition";
  Elm_win.autodel_set win true;
  Evas_object.resize win 300 320;
  Evas_object.show win;

  let bg = Elm_bg.add win in
  Elm_win.resize_object_add win bg;
  Evas_object.size_hint_weight_set bg Evas.hint_expand Evas.hint_expand;
  Evas_object.show bg;

  let bigbox = Elm_box.add win in
  Evas_object.size_hint_weight_set bigbox Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win bigbox;
  Evas_object.show bigbox;

  let bx = Elm_box.add win in
  Elm_box.horizontal_set bx true;
  Elm_box.pack_end bigbox bx;
  Evas_object.show bx;

  let bt_add = Elm_button.add win in
  Elm_object.text_set bt_add "Add";
  Elm_box.pack_end bx bt_add;
  Evas_object.show bt_add;

  let bt_clear = Elm_button.add win in
  Elm_object.text_set bt_clear "Clear";
  Elm_box.pack_end bx bt_clear;
  Evas_object.show bt_clear;

  let bx = Elm_box.add win in
  Evas_object.size_hint_weight_set bx Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set bx Evas.hint_fill Evas.hint_fill;
  Elm_box.pack_end bigbox bx;
  Evas_object.show bx;

  let unpack_cb obj =
    Elm_box.unpack bx obj;
    Evas_object.move obj 0 50;
    Evas_object.color_set obj 128 64 0 128 in

  let bt = Elm_button.add win in
  Elm_object.text_set bt "Button 1";
  Evas_object_smart.callback_add_safe bt Elm_button.E.clicked unpack_cb;
  Evas_object.size_hint_weight_set bt Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set bt Evas.hint_fill Evas.hint_fill;
  Elm_box.pack_end bx bt;
  Evas_object.show bt;

  let bt = Elm_button.add win in
  Elm_object.text_set bt "Button 2";
  Evas_object_smart.callback_add_safe bt Elm_button.E.clicked unpack_cb;
  Evas_object.size_hint_weight_set bt Evas.hint_expand 0.;
  Evas_object.size_hint_align_set bt 1. 0.5;
  Elm_box.pack_end bx bt;
  Evas_object.show bt;

  let bt = Elm_button.add win in
  Elm_object.text_set bt "Button 3";
  Evas_object_smart.callback_add_safe bt Elm_button.E.clicked unpack_cb;
  Elm_box.pack_end bx bt;
  Evas_object.show bt;

  let add_cb _ =
    let btn = Elm_button.add bx in
    Elm_object.text_set btn "I do nothing";
    let children = Elm_box.children_get bx in
    (match children with
    | [] -> Elm_box.pack_end bx btn
    | o :: _ -> Elm_box.pack_after bx btn o);
    Evas_object.show btn in
  Evas_object_smart.callback_add_safe bt_add Elm_button.E.clicked add_cb;

  let clear_cb _ = Elm_box.clear bx in
  Evas_object_smart.callback_add_safe bt_clear Elm_button.E.clicked clear_cb;

  Elm.run ();
  Elm.shutdown ()

