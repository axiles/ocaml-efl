let () =
  Elm.init Sys.argv;
  
  let win = Elm_win.add "entry-example" `basic in
  Elm_win.title_set win "Emacs Lite";
  Evas_object.show win;

  let bg = Elm_bg.add win in
  Evas_object.size_hint_weight_set bg Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  let box = Elm_box.add win in
  Evas_object.size_hint_weight_set box Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win box;
  Evas_object.show box;

  let tb = Elm_box.add win in
  Elm_box.horizontal_set tb true;
  Evas_object.size_hint_weight_set tb Evas.hint_expand 0.;
  Evas_object.size_hint_align_set tb Evas.hint_fill Evas.hint_fill;
  Elm_box.pack_end box tb;
  Evas_object.show tb;

  let o = Elm_check.add win in
  Elm_check.state_set o false;
  Elm_object.text_set o "Autosave";
  Elm_box.pack_end tb o;
  Evas_object.show o;

  let o = Elm_button.add win in
  Elm_object.text_set o "b";
  Elm_box.pack_end tb o;
  Evas_object.show o;

  let o = Elm_button.add win in
  Elm_object.text_set o "em";
  Elm_box.pack_end tb o;

  let o = Elm_button.add win in
  Elm_box.pack_end tb o;
  Evas_object.show o;

  let icon = Elm_layout.add win in
  Elm_layout.theme_set icon "entry" "emoticon/haha" "default";
  Elm_object.part_content_set o ~p:"icon" icon;

  let en = Elm_entry.add win in
  Elm_entry.autosave_set en false;
  let _ = Elm_entry.file_set en "/tmp/da_test.txt" `markup_utf8 in
  Evas_object.size_hint_weight_set en Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set en Evas.hint_fill Evas.hint_fill;
  Elm_box.pack_end box en;
  Evas_object.show en;

  Elm_object.focus_set en true;

  Evas_object.resize win 300 780;

  Elm.run ();
  Elm.shutdown ()
