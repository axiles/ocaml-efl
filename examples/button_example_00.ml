open Efl

let on_click _ _ = Elm.exit ()

let () =
  Elm.init Sys.argv;

  let win = Elm_win.add "Greetins" `basic in
  Elm_win.title_set win "Hello, World!";

  Elm_win.autodel_set win true;
  let (_ : bool) = Elm.policy_set `quit `last_window_closed in
  Evas_object.resize win 240 60;
  Evas_object.show win;

  let bg = Elm_bg.add win in
  Evas_object.size_hint_weight_set bg Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  let btn = Elm_button.add win in
  Elm_object.text_set btn "Good-Bye, World!";
  Evas_object_smart.callback_add btn "clicked" on_click;
  Evas_object.resize btn 120 30;
  Evas_object.move btn 60 15;
  Evas_object.show btn;

  Elm.run ();
  Elm.shutdown ()
