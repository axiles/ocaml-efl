open Efl
open Printf

let file_chosen entry obj file =
  match file with
  | Some s ->
    Elm_object.text_set entry s;
    printf "File chosen: %s\n%!" s
  | None -> print_endline "File selection canceled"


let inwin_mode_toggle fs_bt obj =
  let old_val = Elm_fileselector_button.inwin_mode_get fs_bt in
  Elm_fileselector_button.inwin_mode_set fs_bt (not old_val);
  printf "Inwin mode set to: %s\n%!" (if old_val then "false" else "true")

let current_sel_toggle fs_bt obj =
  let old_val = Elm_fileselector_button.is_save_get fs_bt in
  Elm_fileselector_button.is_save_set fs_bt (not old_val);
  printf "%s text entry with selected item's name\n%!"
    (if old_val then "Disabling" else "Enabling")

let folder_only_toggle fs_bt obj =
  let old_val = Elm_fileselector_button.folder_only_get fs_bt in
  Elm_fileselector_button.folder_only_set fs_bt (not old_val);
  printf "Folder only mode set to: %s\n%!" (if old_val then "false" else "true")

let expandable_toggle fs_bt obj =
  let old_val = Elm_fileselector_button.expandable_get fs_bt in
  Elm_fileselector_button.expandable_set fs_bt (not old_val);
  printf "Expandable folders mode set to: %s\n%!"
    (if old_val then "false" else "true")

let () =
  Elm.init ();
  Elm.policy_quit_set `last_window_closed;

  let win = Elm_win.util_standard_add "fileselector-button"
    "File Selector Button Example" in
  Elm_win.autodel_set win true;

  let vbox = Elm_box.add win in
  Evas_object.size_hint_set vbox [`expand; `fill];
  Elm_win.resize_object_add win vbox;
  Evas_object.show vbox;

  let ic = Elm_icon.add win in
  ignore (Elm_icon.standard_set ic "file" : bool);
  Evas_object.size_hint_aspect_set ic `vertical 1 1;

  let fs_bt = Elm_fileselector_button.add win in
  Elm_fileselector_button.path_set fs_bt "/tmp";
  Elm_object.text_set fs_bt "Select a file";
  Elm_object.part_content_set fs_bt ~p:"icon" ic;

  Elm_box.pack_end vbox fs_bt;
  Evas_object.show fs_bt;
  Evas_object.show ic;

  let sep = Elm_separator.add win in
  Elm_separator.horizontal_set sep true;
  Elm_box.pack_end vbox sep;
  Evas_object.show sep;

  let hbox = Elm_box.add win in
  Elm_box.horizontal_set hbox true;
  Elm_box.pack_end vbox hbox;
  Evas_object.show hbox;

  let add_cb ck cb =
    Evas_object_smart.callback_add ck Elm_sig.changed (cb fs_bt) in

  let ck = Elm_check.add win in
  Elm_object.text_set ck "editable selection";
  Elm_check.state_set ck (Elm_fileselector_button.is_save_get fs_bt);
  add_cb ck current_sel_toggle;
  Elm_box.pack_end hbox ck;
  Evas_object.show ck;

  let ck = Elm_check.add win in
  Elm_object.text_set ck "\"inwin\" mode";
  Elm_check.state_set ck (Elm_fileselector_button.inwin_mode_get fs_bt);
  add_cb ck inwin_mode_toggle;
  Elm_box.pack_end hbox ck;
  Evas_object.show ck;

  let ck = Elm_check.add win in
  Elm_object.text_set ck "folders only";
  Elm_check.state_set ck (Elm_fileselector_button.folder_only_get fs_bt);
  add_cb ck folder_only_toggle;
  Elm_box.pack_end hbox ck;
  Evas_object.show ck;

  let ck = Elm_check.add win in
  Elm_object.text_set ck "expandable";
  Elm_check.state_set ck (Elm_fileselector_button.expandable_get fs_bt);
  add_cb ck expandable_toggle;
  Elm_box.pack_end hbox ck;
  Evas_object.show ck;

  let lb = Elm_label.add win in
  Elm_object.text_set lb "Last selection:";
  Elm_box.pack_end vbox lb;
  Evas_object.show lb;

  let en = Elm_entry.add win in
  Elm_entry.line_wrap_set en `none;
  Elm_entry.editable_set en false;
  Evas_object_smart.callback_add fs_bt Elm_sig.file_chosen
    (file_chosen en);
  Elm_box.pack_end vbox en;
  Evas_object.show en;

  Evas_object.resize win 400 400;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()

