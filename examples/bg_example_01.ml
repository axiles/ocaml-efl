open Efl

let on_done _ = Elm.exit ()

let () =
  Elm.init ();

  let win = Elm_win.add "bg-plain" `basic in
  Elm_win.title_set win "Bg Plain";
  Evas_object_smart.callback_add win Elm_sig.delete_request on_done;
  Elm_win.autodel_set win true;

  let bg = Elm_bg.add win in
  Evas_object.size_hint_weight_set bg Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  Evas_object.resize win 320 320;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()
