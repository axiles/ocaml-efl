open Efl

let () =
  Elm.init ();
  let win = Elm_win.add "hello" `basic in
  Elm_win.title_set win "Hello";
  Evas_object_smart.callback_add win Elm_sig.delete_request
    (fun _ -> print_endline "Exiting..."; Elm.exit ());

  ignore (Elm_bg.addx ~size_hint:[`expand] ~win win);

  ignore (Elm_label.addx ~size_hint:[`expand]
  ~text:"Hello world!" ~win win);

  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()
