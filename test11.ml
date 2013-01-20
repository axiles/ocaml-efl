(* WARNING: This example is in heavy development *)

open Format

let () =
  Elm.init Sys.argv;

  Elm_app.info_set "elementary" ~checkfile:"images/logo.png" ();
  let win = Elm_win.add "win-example" `basic in
  Elm_win.title_set win "Elm_Win example";
  Elm_win.focus_highlight_enabled_set win true;
  Evas_object.resize win 400 400;
  Evas_object.show win;

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

  let win_action box name =
    let btn = Elm_button.add win in
    Elm_object.text_set btn name;
    Elm_box.pack_end box btn;
    Evas_object.show btn in

  win_action box "activate";
  win_action box "lower";
  win_action box "raise";
  win_action box "borderless";
  win_action box "shaped";
  win_action box "alpha";
  win_action box "fullscreen";
  win_action box "maximized";
  win_action box "iconified";
  win_action box "rotation";
  win_action box "rotation_resize";
  win_action box "sticky";

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

  win_action box "activate";
  win_action box "lower";
  win_action box "raise";
  win_action box "borderless";
  win_action box "shaped";
  win_action box "alpha";
  win_action box "fullscreen";
  win_action box "maximized";
  win_action box "iconified";
  win_action box "rotation";
  win_action box "rotation_resize";
  win_action box "sticky";

  Elm.run ();
  Elm.shutdown ()

