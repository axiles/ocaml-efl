open Efl

let item_pressed obj ptr =
  let tb_it = Elm_object.item_of_ptr ptr in
  (match Elm_toolbar.item_state_next tb_it with
  | None -> ignore (Elm_toolbar.item_state_set_null tb_it : bool)
  | Some state -> ignore (Elm_toolbar.item_state_set tb_it state : bool));
  Elm_toolbar.item_selected_set tb_it false

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
  Elm_toolbar.shrink_mode_set tb `hide;
  Evas_object.size_hint_set tb [`hfill; `valign 0.];
  Evas_object.show tb;

  let append icon label =
    ignore (Elm_toolbar.item_append tb ~icon ~label () : Elm_object.item) in
  append "document-print" "Print";
  append "folder-new" "Folder";
  append "clock" "Clock";
  append "refresh" "Update";

  let tb_it = Elm_toolbar.item_append tb ~icon:"mail-send" ~label:"Send Mail"
    ~func:item_pressed () in
  let add_state icon label =
    ignore (Elm_toolbar.item_state_add tb_it ~icon ~label ~func:item_pressed
      () : Elm_toolbar.item_state) in
  add_state "emptytrash" "Empty Trash";
  add_state "trashcan_full" "Full Trash";

  Elm_toolbar.item_priority_set tb_it 10;

  Elm_box.pack_end bx tb;
  Elm_box.pack_end bx bt;

  Evas_object.resize win 230 200;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()


