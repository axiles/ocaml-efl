open Efl

let on_done obj = Elm.exit ()

let () =
  Elm.init ();
  let win = Elm_win.addx ~title:"Hello" "hello" in
  Elm_connect.Win.delete_request win on_done;

  let box = Elm_box.addx ~win win in
  Elm_box.horizontal_set box true;

  ignore (Elm_label.addx ~text:"Hello out there World!" ~box win);

  let btn = Elm_button.addx ~text:"Ok" ~box win in
  Elm_connect.Button.clicked btn on_done;

  Evas_object.show win;
  Elm.run ();
  Elm.shutdown ()

