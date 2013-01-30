open Efl
open Format
module EF = Elm_fileselector

let on_done _ _ =
  Elm.exit ()

let fs_done obj event_info =
  let selected = match event_info with Some s -> s | None -> "*none!*" in
  printf "We're done! Selected file is: %s\n%!" selected;
  Elm.exit ()

let fs_selected obj event_info =
  let selected = Evas.string_of_ptr event_info in
  printf "There's been a selection: %s\n%!" selected

let option_clicked msg f_set f_get fs obj _ =
  let old_val = f_get fs in
  let old_val_s = if old_val then "Disabling" else "Enabling" in
  printf "%s %s\n%!" msg old_val_s;
  f_set fs (not old_val)
  
let is_save_clicked =
  let f_set = EF.is_save_set and f_get = EF.is_save_get in
  option_clicked "text entry with selected item's name" f_set f_get

let folder_only_clicked =
  option_clicked "folder-only mode" EF.folder_only_set EF.folder_only_get

let expandable_clicked =
  option_clicked "tree-view mode" EF.expandable_set EF.expandable_get

let data_clicked name f_get fs _ _ = printf "%s name is: %s\n%!" name (f_get fs)

let sel_get_clicked = data_clicked "Current selection" EF.selected_get

let path_get_clicked = data_clicked "Current selection's directory" EF.path_get

let () =
  Elm.init Sys.argv;
  let (_ : bool) = Elm.need_ethumb () in

  let win = Elm_win.add "fileselector" `basic in
  Elm_win.title_set win "File Selector Example";
  Evas_object_smart.callback_add win "delete,request" on_done;

  let bg = Elm_bg.add win in
  Elm_win.resize_object_add win bg;
  Evas_object.size_hint_weight_set bg Evas.hint_expand Evas.hint_expand;
  Evas_object.show bg;

  let bx = Elm_box.add win in
  Elm_win.resize_object_add win bx;
  Elm_box.horizontal_set bx true;
  Evas_object.size_hint_weight_set bx Evas.hint_expand Evas.hint_expand;
  Evas_object.show bx;

  let vbox = Elm_box.add win in
  Evas_object.size_hint_weight_set vbox Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set vbox Evas.hint_fill Evas.hint_fill;
  Evas_object.show vbox;
  Elm_box.pack_end bx vbox;

  let fs = EF.add win in
  EF.is_save_set fs true;
  EF.expandable_set fs false;
  EF.path_set fs "/tmp";

  Evas_object.size_hint_weight_set fs Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set fs Evas.hint_fill Evas.hint_fill;
  Elm_box.pack_end vbox fs;
  Evas_object.show fs;

  Evas_object_smart.callback_add_safe fs EF._done fs_done;
  Evas_object_smart.callback_add fs "selected" fs_selected;

  let sep = Elm_separator.add win in
  Elm_separator.horizontal_set sep true;
  Elm_box.pack_end vbox sep;
  Evas_object.show sep;

  let buttons_bx = Elm_box.add win in
  Elm_box.horizontal_set buttons_bx true;
  Elm_box.pack_end vbox buttons_bx;
  Evas_object.show buttons_bx;

  let bt = Elm_check.add win in
  Elm_object.text_set bt "editable selection";
  Elm_check.state_set bt (EF.is_save_get fs);
  Evas_object_smart.callback_add bt "changed" (is_save_clicked fs);
  Elm_box.pack_end buttons_bx bt;
  Evas_object.show bt;

  let bt = Elm_check.add win in
  Elm_object.text_set bt "folder only";
  Elm_check.state_set bt (EF.folder_only_get fs);
  Evas_object_smart.callback_add bt "changed" (folder_only_clicked fs);
  Elm_box.pack_end buttons_bx bt;
  Evas_object.show bt;

  let bt = Elm_check.add win in
  Elm_object.text_set bt "expandable";
  Elm_check.state_set bt (EF.expandable_get fs);
  Evas_object_smart.callback_add bt "changed" (expandable_clicked fs);
  Elm_box.pack_end buttons_bx bt;
  Evas_object.show bt;

  let buttons_bx = Elm_box.add win in
  Elm_box.horizontal_set  buttons_bx true;
  Elm_box.pack_end vbox buttons_bx;
  Evas_object.show buttons_bx;

  let bt = Elm_button.add win in
  Elm_object.text_set bt "Print selection";
  Evas_object_smart.callback_add bt "clicked" (sel_get_clicked fs);
  Elm_box.pack_end buttons_bx bt;
  Evas_object.show bt;

  let bt = Elm_button.add win in
  Elm_object.text_set bt "Print path";
  Evas_object_smart.callback_add bt "clicked" (path_get_clicked fs);
  Elm_box.pack_end buttons_bx bt;
  Evas_object.show bt;

  let sep = Elm_separator.add win in
  Elm_separator.horizontal_set sep false;
  Elm_box.pack_end bx sep;

  let fs = EF.add win in
  EF.path_set fs "/tmp";
  EF.is_save_set fs true;
  EF.mode_set fs `grid;
  EF.buttons_ok_cancel_set fs false;

  Evas_object.size_hint_weight_set fs Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set fs Evas.hint_fill Evas.hint_fill;
  Elm_box.pack_end bx fs;
  Evas_object.show fs;

  Evas_object.resize win 800 600;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()
