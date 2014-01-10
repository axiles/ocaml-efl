open Efl

let () =
  Elm.init ();
  let win = Elm_win.add "hello" `basic in
  Elm_win.title_set win "Hello";
  Evas_object_smart.callback_add win Elm_win.E.delete_request
    (fun _ -> print_endline "Exiting..."; Elm.exit ());

  let bg = Elm_bg.add win in
  Evas_object.size_hint_set bg [`expand];
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  let lb = Elm_label.add win in
  Elm_object.text_set lb "Hello world!";
  Evas_object.size_hint_set lb [`expand];
  Elm_win.resize_object_add win lb;
  Evas_object.show lb;

  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()
