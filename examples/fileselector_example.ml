open Efl
open Format
module EF = Elm_fileselector

let on_done _ =
  Elm.exit ()

let fs_done obj event_info =
  let selected = match event_info with Some s -> s | None -> "*none!*" in
  printf "We're done! Selected file is: %s\n%!" selected;
  Elm.exit ()

let fs_selected obj selected =
  printf "There's been a selection: %s\n%!" selected

let add_check win box fs name msg f_set f_get =
  let cb obj =
    let old_val = f_get fs in
    let old_val_s = if old_val then "Disabling" else "Enabling" in
    printf "%s %s\n%!" msg old_val_s;
    f_set fs (not old_val) in
  let bt = Elm_check.add win in
  Elm_object.text_set bt name;
  Elm_check.state_set bt (f_get fs);
  Evas_object_smart.callback_add bt Elm_check.E.changed cb;
  Elm_box.pack_end box bt;
  Evas_object.show bt

let add_data_button win box fs name msg f_get =
  let cb _ = printf "%s name is: %s\n%!" msg (f_get fs) in
  let bt = Elm_button.add win in
  Elm_object.text_set bt name;
  Evas_object_smart.callback_add bt Elm_button.E.clicked cb;
  Elm_box.pack_end box bt;
  Evas_object.show bt

let () =
  Elm.init Sys.argv;
  let (_ : bool) = Elm.need_ethumb () in

  let win = Elm_win.add "fileselector" `basic in
  Elm_win.title_set win "File Selector Example";
  Evas_object_smart.callback_add win Elm_win.E.delete_request on_done;

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

  Evas_object_smart.callback_add fs EF.E._done fs_done;
  Evas_object_smart.callback_add fs EF.E.selected fs_selected;

  let sep = Elm_separator.add win in
  Elm_separator.horizontal_set sep true;
  Elm_box.pack_end vbox sep;
  Evas_object.show sep;

  let buttons_bx = Elm_box.add win in
  Elm_box.horizontal_set buttons_bx true;
  Elm_box.pack_end vbox buttons_bx;
  Evas_object.show buttons_bx;

  let list_check = [
    ("enable selection", "text entry with selected item's name", EF.is_save_set,
      EF.is_save_get);
    ("folder only", "folder-only mode", EF.folder_only_set, EF.folder_only_get);
    ("expandable", "tree-view mode", EF.expandable_set, EF.expandable_get)] in
  let check_aux (name, msg, f_get, f_set) =
    add_check win buttons_bx fs name msg f_get f_set in
  List.iter check_aux list_check;

  let buttons_bx = Elm_box.add win in
  Elm_box.horizontal_set  buttons_bx true;
  Elm_box.pack_end vbox buttons_bx;
  Evas_object.show buttons_bx;

  let list_bts = [
    ("Print selection", "Current selection", EF.selected_get);
    ("Print path", "Current selection's directory", EF.path_get)] in
  let data_aux (name, msg, f_get) =
    add_data_button win buttons_bx fs name msg f_get in
  List.iter data_aux list_bts;

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
