open Efl

let on_done _ = Elm.exit ()

let () =
  Elm.init ();

  let win = Elm_win.add "hello" `basic in
  Elm_win.title_set win "Hello";
  Elm_connect.Win.delete_request win on_done;

  ignore (Elm_bg.addx ~size_hint:[`weight0] ~win win);

  let box = Elm_box.addx ~size_hint:[`weight0] ~win win in
  Elm_box.horizontal_set box true;

  ignore (Elm_label.addx ~text:"Hello out there world!"
    ~size_hint:[`weight0] ~box win);

  let btn = Elm_button.addx ~text:"Ok" ~size_hint:[`weight0] ~box win in
  Elm_connect.Button.clicked btn on_done;

  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()
