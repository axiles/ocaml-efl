open Efl

let () =
  Elm.init ();
  Elm.policy_set `quit `last_window_closed;

  let win = Elm_win.util_standard_add "toolbar" "Toolbar Example" in
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
  Evas_object.size_hint_set tb [`hfill; `valign 0.];
  Evas_object.show tb;

  let append icon label =
    ignore (Elm_toolbar.item_append tb ~icon ~label () : Elm_object.item) in
  append "document-print" "Print";
  append "folder-new" "Folder";
  append "clock" "Clock";
  append "refresh" "Update";

  Elm_toolbar.menu_parent_set tb win;

  let tb_it =
    Elm_toolbar.item_append tb ~icon:"mail-send" ~label:"Send Mail" () in
  Elm_toolbar.item_menu_set tb_it true;

  let menu = match Elm_toolbar.item_menu_get tb_it with
  | Some m -> m
  | None -> assert false in
  let add icon label =
    ignore (Elm_menu.item_add menu ~icon ~label () : Elm_object.item) in
  add "emptytrash" "Empty Trash";
  add "trashcan_full" "Full Trash";

  Elm_toolbar.item_priority_set tb_it 10;

  Elm_box.pack_end bx tb;
  Elm_box.pack_end bx bt;

  Evas_object.resize win 230 200;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()

