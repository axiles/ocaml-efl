open Efl
open Format

let win_action_do_cb win f _ = f win

let win_action_switch_cb win f_get f_set _ = f_set win (not (f_get win))

let win_action_rot_cb win f_get f_set _ = f_set win ((f_get win + 90) mod 360)

let win_action win box name cb =
    let btn = Elm_button.add win in
    Elm_object.text_set btn name;
    Elm_box.pack_end box btn;
    Evas_object.show btn;
    Evas_object_smart.callback_add btn Elm_sig.clicked cb

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

let main_win_del_cb obj =
  let msg = Elm_notify.add obj in
  Elm_notify.align_set msg 0.5 0.5;
  Elm_notify.allow_events_set msg false;
  Evas_object.show msg;

  let box = Elm_box.add obj in
  Evas_object.size_hint_weight_set box Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set box Evas.hint_fill  Evas.hint_fill;
  Elm_object.content_set msg box;
  Evas_object.show box;

  let lbl = Elm_label.add obj in
  Elm_object.text_set lbl "Really want quit ?";
  Evas_object.size_hint_weight_set lbl Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set lbl Evas.hint_fill Evas.hint_fill;
  Elm_box.pack_end box lbl;
  Evas_object.show lbl;

  let sep = Elm_separator.add obj in
  Elm_separator.horizontal_set sep true;
  Elm_box.pack_end box sep;
  Evas_object.show sep;

  let box2 = Elm_box.add obj in
  Elm_box.horizontal_set box2 true;
  Evas_object.size_hint_weight_set box2 Evas.hint_expand 0.;
  Evas_object.size_hint_align_set box2 Evas.hint_fill Evas.hint_fill;
  Elm_box.pack_end box box2;
  Evas_object.show box2;

  let btn = Elm_button.add obj in
  Elm_object.text_set btn "Yes";
  Elm_box.pack_end box2 btn;
  Evas_object.show btn;

  let yes_quit_cb _ = Elm.exit () in
  Evas_object_smart.callback_add btn Elm_sig.clicked yes_quit_cb;

  let btn = Elm_button.add obj in
  Elm_object.text_set btn "No";
  Elm_box.pack_end box2 btn;
  Evas_object.show btn;

  let no_quit_cb _ = Evas_object.del msg in
  Evas_object_smart.callback_add btn Elm_sig.clicked no_quit_cb

let force_focus_cb win _ =
  try Ecore.x_window_focus (Elm_win.xwindow_get win)
  with Ecore.Not_X -> ()

let add_win_focus_cb win name =
  let cb _ = printf "Window focused: %s\n%!" name in
  Evas_object_smart.callback_add win Elm_sig.focused cb

let () =
  Elm.init ();

  Elm_app.info_set "elementary" ~checkfile:"images/logo.png" ();
  let win = Elm_win.add "win-example" `basic in
  Elm_win.title_set win "Elm_Win example";
  Elm_win.focus_highlight_enabled_set win true;
  Evas_object.resize win 400 400;
  Evas_object.show win;
  add_win_focus_cb win "mainwin";
  Evas_object_smart.callback_add win Elm_sig.delete_request
    main_win_del_cb;

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

  let o = Elm_separator.add win2 in
  Elm_separator.horizontal_set o true;
  Elm_box.pack_end bigbox o;
  Evas_object.show o;

  let o = Elm_button.add win2 in
  Elm_object.text_set o "Focus me";
  Elm_box.pack_end bigbox o;
  Evas_object.show o;
  Evas_object_smart.callback_add o Elm_sig.clicked
    (force_focus_cb win2);

  let o = Elm_label.add win in
  Elm_object.text_set o "<b>Override Window</b>";
  Elm_box.pack_end box o;
  Evas_object.show o;

  win_action_all win box win2;

  Elm.run ();
  Elm.shutdown ()

