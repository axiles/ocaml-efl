open Efl
open Printf

let () =
  Elm.init ();
  Elm.policy_set `quit `last_window_closed;

  let win = Elm_win.util_standard_add "table" "Table" in
  Elm_win.autodel_set win true;

  let table = Elm_table.add win in
  Elm_win.resize_object_add win table;
  Evas_object.show table;
  Elm_table.padding_set table 5 5;
  Elm_table.homogeneous_set table true;

  let add_label n x y w h =
    let label = Elm_label.add win in
    Elm_object.text_set label (sprintf "label %d" n);
    Evas_object.show label;
    Elm_table.pack table label x y w h in

  add_label 0 0 0 1 1;
  add_label 1 1 0 1 1;
  add_label 2 0 1 1 1;
  add_label 3 1 1 1 1;

  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()

