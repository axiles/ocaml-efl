open Efl

let () =
  Elm.init Sys.argv;
  let win = Elm_win.add "hello" `basic in
  Elm_win.title_set win "Hello";
  Evas_object_smart.callback_add_safe win Elm_win.delete_request
    (fun _ -> print_endline "Exiting..."; Elm.exit ());

  let bg = Elm_bg.add win in
  Evas_object.size_hint_weight_set bg 1. 1.;
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  let lb = Elm_label.add win in
  Elm_object.text_set lb "Hello world!";
  Evas_object.size_hint_weight_set lb 1. 1.;
  Elm_win.resize_object_add win lb;
  Evas_object.show lb;

  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()
