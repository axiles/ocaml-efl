open Efl
open Printf

let file_chosen obj file =
  match file with
  | Some s ->
    printf "File chosen: %s\n%!" s
  | None -> print_endline "File selection canceled"


let inwin_mode_toggle fs_entry obj =
  let old_val = Elm_fileselector_entry.inwin_mode_get fs_entry in
  Elm_fileselector_entry.inwin_mode_set fs_entry (not old_val);
  printf "Inwin mode set to: %s\n%!" (if old_val then "false" else "true")

let current_sel_toggle fs_entry obj =
  let old_val = Elm_fileselector_entry.is_save_get fs_entry in
  Elm_fileselector_entry.is_save_set fs_entry (not old_val);
  printf "%s text entry with selected item's name\n%!"
    (if old_val then "Disabling" else "Enabling")

let folder_only_toggle fs_entry obj =
  let old_val = Elm_fileselector_entry.folder_only_get fs_entry in
  Elm_fileselector_entry.folder_only_set fs_entry (not old_val);
  printf "Folder only mode set to: %s\n%!" (if old_val then "false" else "true")

let expandable_toggle fs_entry obj =
  let old_val = Elm_fileselector_entry.expandable_get fs_entry in
  Elm_fileselector_entry.expandable_set fs_entry (not old_val);
  printf "Expandable folders mode set to: %s\n%!"
    (if old_val then "false" else "true")

let () =
  Elm.init ();
  Elm.policy_quit_set `last_window_closed;

  let win = Elm_win.util_standard_add "fileselector-entry"
    "File Selector Entry Example" in
  Elm_win.autodel_set win true;

  let vbox = Elm_box.add win in
  Evas_object.size_hint_set vbox [`expand];
  Elm_win.resize_object_add win vbox;
  Evas_object.show vbox;

  let ic = Elm_icon.add win in
  ignore (Elm_icon.standard_set ic "file" : bool);
  Evas_object.size_hint_aspect_set ic `vertical 1 1;

  let fs_entry = Elm_fileselector_entry.add win in
  Evas_object.size_hint_set fs_entry [`hfill; `valign 0.];
  Elm_fileselector_entry.path_set fs_entry "/tmp";
  Elm_object.text_set fs_entry "Select a file";
  Elm_object.part_content_set fs_entry ~p:"button icon" ic;

  Elm_box.pack_end vbox fs_entry;
  Evas_object.show fs_entry;
  Evas_object.show ic;

  let sep = Elm_separator.add win in
  Elm_separator.horizontal_set sep true;
  Elm_box.pack_end vbox sep;
  Evas_object.show sep;

  let hbox = Elm_box.add win in
  Elm_box.horizontal_set hbox true;
  Elm_box.pack_end vbox hbox;
  Evas_object.show hbox;

  let add_cb ck cb = Elm_connect.Check.changed ck (cb fs_entry) in

  let ck = Elm_check.add win in
  Elm_object.text_set ck "editable selection";
  Elm_check.state_set ck (Elm_fileselector_entry.is_save_get fs_entry);
  add_cb ck current_sel_toggle;
  Elm_box.pack_end hbox ck;
  Evas_object.show ck;

  let ck = Elm_check.add win in
  Elm_object.text_set ck "\"inwin\" mode";
  Elm_check.state_set ck (Elm_fileselector_entry.inwin_mode_get fs_entry);
  add_cb ck inwin_mode_toggle;
  Elm_box.pack_end hbox ck;
  Evas_object.show ck;

  let ck = Elm_check.add win in
  Elm_object.text_set ck "folders only";
  Elm_check.state_set ck (Elm_fileselector_entry.folder_only_get fs_entry);
  add_cb ck folder_only_toggle;
  Elm_box.pack_end hbox ck;
  Evas_object.show ck;

  let ck = Elm_check.add win in
  Elm_object.text_set ck "expandable";
  Elm_check.state_set ck (Elm_fileselector_entry.expandable_get fs_entry);
  add_cb ck expandable_toggle;
  Elm_box.pack_end hbox ck;
  Evas_object.show ck;

  Elm_connect.Fileselector_entry.file_chosen fs_entry file_chosen;

  Evas_object.resize win 400 400;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()

