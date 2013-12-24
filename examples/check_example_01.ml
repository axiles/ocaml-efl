open Efl
open Format

let print obj =
  printf "check %smarked\n%!" (if Elm_check.state_get obj then "" else "un")

let () =
  Elm.init Sys.argv;

  let win = Elm_win.add "check" `basic in
  Elm_win.title_set win "check";
  Elm_win.autodel_set win true;
  let (_ : bool) = Elm.policy_set `quit `last_window_closed in

  let bg = Elm_bg.add win in
  Evas_object.size_hint_weight_set bg Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  let cb = Elm_check.add win in
  Elm_object.text_set cb "checkbox";
  Evas_object_smart.callback_add cb Elm_check.E.changed print;
  Evas_object.move cb 10 10;
  Evas_object.resize cb 200 30;
  Evas_object.show cb;

  let icon = Evas_object.rectangle_add (Evas_object.evas_get win) in
  Evas_object.color_set icon 0 255 0 255;
  Evas_object.resize icon 20 20;
  Evas_object.show icon;

  let cb2 = Elm_check.add win in
  Elm_object.text_set cb2 "another checkbox";
  Elm_check.state_set cb true;
  Elm_object.part_content_set cb2 ~p:"icon" icon;
  Evas_object.move cb2 10 50;
  Evas_object.resize cb2 200 30;
  Evas_object.show cb2;

  Evas_object.resize win 200 100;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()
