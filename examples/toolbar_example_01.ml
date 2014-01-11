let item_1_pressed bt obj _ = Elm_object.text_set bt "Print document"

let item_2_pressed bt obj _ = Elm_object.text_set bt "Create new folder"

let item_3_pressed bt obj _ = Elm_object.text_set bt "Create and send email"

let () =
  Elm.init ();
  Elm.policy_set `quit `last_window_closed;

  let win = Elm_win.util_standard_add "toolbar" "Toolbar example" in
  Elm_win.autodel_set win true;

  let bx = Elm_box.add win in
  Evas_object.size_hint_set bx [`expand];
  Elm_win.resize_object_add win bx;
  Evas_object.show bx;

  let bt = Elm_button.add win in
  Evas_object.size_hint_set bt [`expand; `fill];
  Elm_object.text_set bt "Button";
  Evas_object.show bt;

  let tb = Elm_toolbar.add win in
  Elm_toolbar.shrink_mode_set tb `scroll;
  Evas_object.size_hint_set tb [`hfill];
  Evas_object.show tb;

  ignore(Elm_toolbar.item_append tb ~icon:"document-print" ~label:"Print"
    ~func:(item_1_pressed bt) () : Elm_object.item);
  ignore(Elm_toolbar.item_append tb ~icon:"folder-new" ~label:"New folder"
    ~func:(item_2_pressed bt) () : Elm_object.item);

  let tb_it = Elm_toolbar.item_append tb ~icon:"mail-send"
    ~label:"Create and send email" ~func:(item_3_pressed bt) () in
  Elm_object.item_disabled_set tb_it true;

  Elm_toolbar.homogeneous_set tb false;

  Elm_box.pack_end bx tb;
  Elm_box.pack_end bx bt;

  Evas_object.resize win 200 200;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()

