(* WARNING: This example is in heavy development *)

open Format

let win_action_do_cb win f _ _ = f win

let win_action_switch_cb win f_get f_set _ _ = f_set win (not (f_get win))

let win_action_rot_cb win f_get f_set _ _ = f_set win ((f_get win + 90) mod 360)

let win_action win box name cb =
    let btn = Elm_button.add win in
    Elm_object.text_set btn name;
    Elm_box.pack_end box btn;
    Evas_object.show btn;
    Evas_object_smart.callback_add btn "clicked" cb

let win_action_do win box win2 name f =
  win_action win box name (win_action_do_cb win2 f)

let win_action_switch win box win2 name f_get f_set =
  win_action win box name (win_action_switch_cb win2 f_get f_set)

let win_action_rot win box win2 name f_get f_set =
  win_action win box name (win_action_rot_cb win2 f_get f_set)

let win_action_all win box win2 =
  let wad = win_action_do win box win2 in
  let was = win_action_switch win box win2 in
  let war = win_action_rot win box win2 in
  wad "activate" Elm_win.activate;
  wad "lower" Elm_win.lower;
  wad "raise" Elm_win.raises;
  was "borderless" Elm_win.borderless_get Elm_win.borderless_set;
  was "shaped" Elm_win.shaped_get Elm_win.shaped_set;
  was "alpha" Elm_win.alpha_get Elm_win.alpha_set;
  was "fullscreen" Elm_win.fullscreen_get Elm_win.fullscreen_set;
  was "maximized" Elm_win.maximized_get Elm_win.maximized_set;
  was "iconified" Elm_win.iconified_get Elm_win.iconified_set;
  war "rotation" Elm_win.rotation_get Elm_win.rotation_set;
  war "rotation_resize" Elm_win.rotation_get Elm_win.rotation_with_resize_set;
  was "sticky" Elm_win.sticky_get Elm_win.sticky_set

let add_win_focus_cb win name =
  let cb _ _ = printf "Window focused: %s\n%!" name in
  Evas_object_smart.callback_add win "focus,in" cb

let () =
  Elm.init Sys.argv;

  Elm_app.info_set "elementary" ~checkfile:"images/logo.png" ();
  let win = Elm_win.add "win-example" `basic in
  Elm_win.title_set win "Elm_Win example";
  Elm_win.focus_highlight_enabled_set win true;
  Evas_object.resize win 400 400;
  Evas_object.show win;
  add_win_focus_cb win "mainwin";

  let bg = Elm_bg.add win in
  Evas_object.size_hint_weight_set bg Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  let bigbox = Elm_box.add win in
  Elm_box.horizontal_set bigbox true;
  Evas_object.size_hint_weight_set bigbox Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win bigbox;
  Evas_object.show bigbox;

  let box = Elm_box.add win in
  Evas_object.size_hint_weight_set box Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set box Evas.hint_fill Evas.hint_fill;
  Elm_box.pack_end bigbox box;
  Evas_object.show box;

  let win2 = Elm_win.add "sub-win-example" `dialog_basic in
  Elm_win.autodel_set win2 true;
  Elm_win.title_set win2 "Managed window";
  Evas_object.show win2;
  add_win_focus_cb win2 "managed";

  let o = Elm_icon.add win2 in
  let buf = sprintf "%s/images/logo.png" (Elm_app.data_dir_get ()) in
  let (_ : bool) = Elm_image.file_set o buf () in
  Elm_image.resizable_set o false false;
  Elm_image.no_scale_set o true;
  Elm_win.resize_object_add win2 o;
  Evas_object.show o;

  let o = Elm_label.add win in
  Elm_object.text_set o "<b>Managed window</b>";
  Elm_box.pack_end box o;
  Evas_object.show o;

  win_action_all win box win2;

  let box = Elm_box.add win in
  Evas_object.size_hint_weight_set box Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set box Evas.hint_fill Evas.hint_fill;
  Elm_box.pack_end bigbox box;
  Evas_object.show box;

  let win2 = Elm_win.add "sub-win-example2" `basic in
  Elm_win.autodel_set win2 true;
  Elm_win.title_set win2 "Non-managed window";
  Elm_win.override_set win2 true;
  Evas_object.show win2;
  add_win_focus_cb win2 "override";

  let o = Elm_bg.add win2 in
  Evas_object.size_hint_weight_set o Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win2 o;
  Evas_object.show o;

  let bigbox = Elm_box.add win2 in
  Evas_object.size_hint_weight_set bigbox Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win2 bigbox;
  Evas_object.show bigbox;

  let o = Elm_label.add win2 in
  Elm_object.text_set o "This window have no borders or titlebar.<ps>\
                        It was set in override mode; so the Window Manager<ps>\
                        should ignore everything about it.<ps>
                        It's up to the program to handle it properly, and some\
                        of the actions performed on it may or may not have any\
                        effect.";
  Elm_box.pack_end bigbox o;
  Evas_object.show o;

  let o = Elm_entry.add win2 in
  Elm_object.text_set o "See if you can focus me";
  Elm_entry.single_line_set o true;
  Elm_entry.scrollable_set o true;
  Evas_object.size_hint_weight_set o Evas.hint_expand 0.;
  Evas_object.size_hint_align_set o Evas.hint_fill Evas.hint_fill;
  Elm_box.pack_end bigbox o;
  Evas_object.show o;

  let o = Elm_button.add win2 in
  Elm_object.text_set o "Focus me";
  Elm_box.pack_end bigbox o;
  Evas_object.show o;

  let o = Elm_label.add win in
  Elm_object.text_set o "<b>Override Window</b>";
  Elm_box.pack_end box o;
  Evas_object.show o;

  win_action_all win box win2;

  Elm.run ();
  Elm.shutdown ()

