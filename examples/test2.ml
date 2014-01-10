open Efl

let on_done _ = Elm.exit ()

let () =
  Elm.init ();

  let win = Elm_win.add "hello" `basic in
  Elm_win.title_set win "Hello";
  Evas_object_smart.callback_add win Elm_win.E.delete_request on_done;

  let bg = Elm_bg.add win in
  Evas_object.size_hint_set bg [`weight0];
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  let box = Elm_box.add win in
  Elm_box.horizontal_set box true;
  Evas_object.size_hint_set box [`weight0];
  Elm_win.resize_object_add win box;
  Evas_object.show box;

  let lab = Elm_label.add win in
  Elm_object.text_set lab "Hello out there world!";
  Evas_object.size_hint_weight_set lab 0. 0.;
  Elm_box.pack_end box lab;
  Evas_object.show lab;

  let btn = Elm_button.add win in
  Elm_object.text_set btn "OK";
  Evas_object.size_hint_weight_set btn 0. 0.;
  Elm_box.pack_end box btn;
  Evas_object.show btn;
  Evas_object_smart.callback_add btn Elm_button.E.clicked on_done;

  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()
