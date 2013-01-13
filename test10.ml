(* WARNING: this example is still in heavy development *)

let () =
  Elm.init Sys.argv;
  Elm.policy_set `quit `last_window_closed;

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

  let bt = Elm_button.add win in
  Elm_object.text_set bt "Add";
  Elm_box.pack_end bx bt;
  Evas_object.show bt;

  let bt = Elm_button.add win in
  Elm_object.text_set bt "Clear";
  Elm_box.pack_end bx bt;
  Evas_object.show bt;

  let bx = Elm_box.add win in
  Evas_object.size_hint_weight_set bx Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set bx Evas.hint_fill Evas.hint_fill;
  Elm_box.pack_end bigbox bx;
  Evas_object.show bx;

  let bt = Elm_button.add win in
  Elm_object.text_set bt "Button 1";
  Evas_object.size_hint_weight_set bt Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set bt Evas.hint_fill Evas.hint_fill;
  Elm_box.pack_end bx bt;
  Evas_object.show bt;

  let bt = Elm_button.add win in
  Elm_object.text_set bt "Button 2";
  Evas_object.size_hint_weight_set bt Evas.hint_expand 0.;
  Evas_object.size_hint_align_set bt 1. 0.5;
  Elm_box.pack_end bx bt;
  Evas_object.show bt;

  let bt = Elm_button.add win in
  Elm_object.text_set bt "Button 3";
  Elm_box.pack_end bx bt;
  Evas_object.show bt;

  Elm.run ();
  Elm.shutdown ()

