open Efl

let on_click _ = Elm.exit ()

let () =
  Elm.init ();

  let win = Elm_win.add "Greetins" `basic in
  Elm_win.title_set win "Hello, World!";

  Elm_win.autodel_set win true;
  Elm.policy_quit_set `last_window_closed;
  Evas_object.resize win 240 60;
  Evas_object.show win;

  ignore (Elm_bg.addx ~size_hint:[`expand] ~win win);

  let btn = Elm_button.addx ~text:"Good-Bye, World"
    ~size:(120, 30) ~pos:(60, 15) win in
  Evas_object_smart.callback_add btn Elm_sig.clicked on_click;

  Elm.run ();
  Elm.shutdown ()
