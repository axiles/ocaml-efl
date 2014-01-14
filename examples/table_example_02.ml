open Efl

let () =
  Elm.init ();
  Elm.policy_quit_set `last_window_closed;

  let win = Elm_win.util_standard_add "table" "Table" in
  Elm_win.autodel_set win true;

  let table = Elm_table.add win in
  Elm_win.resize_object_add win table;
  Evas_object.show table;
  Elm_table.homogeneous_set table false;

  let rect = Evas_object.rectangle_add (Evas_object.evas_get win) in
  Evas_object.color_set rect 255 0 0 255;
  Evas_object.size_hint_min_set rect 100 50;
  Evas_object.show rect;
  Elm_table.pack table rect 0 0 2 1;

  let rect = Evas_object.rectangle_add (Evas_object.evas_get win) in
  Evas_object.color_set rect 0 255 0 255;
  Evas_object.size_hint_min_set rect 50 100;
  Evas_object.show rect;
  Elm_table.pack table rect 0 1 1 2;

  let rect = Evas_object.rectangle_add (Evas_object.evas_get win) in
  Evas_object.color_set rect 0 0 255 255;
  Evas_object.size_hint_min_set rect 50 50;
  Evas_object.show rect;
  Elm_table.pack table rect 1 1 1 1;

  let rect = Evas_object.rectangle_add (Evas_object.evas_get win) in
  Evas_object.color_set rect 255 255 0 255;
  Evas_object.size_hint_min_set rect 50 50;
  Evas_object.show rect;
  Elm_table.pack table rect 1 2 1 1;

  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()

