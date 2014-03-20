open Efl
let ( >< ) = Elm.connect

let on_done obj = Elm.exit ()

let () =
  Elm.init ();
  let win = Elm_win.addx ~title:"Hello"
    ~cb:[Elm_sig.delete_request >< on_done] "hello" in

  let box = Elm_box.addx ~win win in
  Elm_box.horizontal_set box true;

  ignore (Elm_label.addx ~text:"Hello out there World!" ~box win);

  ignore (Elm_button.addx ~text:"Ok" ~box ~cb:[Elm_sig.clicked >< on_done] win);

  Evas_object.show win;
  Elm.run ();
  Elm.shutdown ()

