open Efl

let () =
  Elm.init ();

  let win = Elm_win.add "label" `basic in
  Elm_win.title_set win "Label";
  Elm_win.autodel_set win true;
  Elm.policy_quit_set `last_window_closed;

  let bg = Elm_bg.add win in
  Evas_object.size_hint_weight_set bg Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  let label = Elm_label.add win in
  Elm_object.text_set label "Some long text for our label, that is long but \
    not too long.";
  Elm_label.slide_duration_set label 3.;
  Elm_label.slide_mode_set label true;
  let (_ : bool) = Elm_object.style_set label "slide_bounce" in
  Evas_object.move label 0 10;
  Evas_object.resize label 200 15;
  Evas_object.show label;

  let label2 = Elm_label.add win in
  Elm_object.text_set label2 "This is the text for our second label, which is \
    much longer than the previous one, maybe even too long, but maybe not.";
  Elm_label.ellipsis_set label2 true;
  Evas_object.resize label2 200 15;
  Evas_object.move label2 0 30;
  Evas_object.show label2;

  let label3 = Elm_label.add win in
  Elm_object.text_set label3 "Some more long text much as before, long but \
    not too long.";
  Elm_label.line_wrap_set label3 `char;
  Elm_label.ellipsis_set label3 true;
  Evas_object.resize label3 200 15;
  Evas_object.move label3 0 50;
  Evas_object.show label3;

  let label4 = Elm_label.add win in
  Elm_object.text_set label4 "And for this label we choose a different text, \
    for no reason other than that we can.";
  Elm_label.line_wrap_set label4 `char;
  Evas_object.resize label4 200 30;
  Evas_object.move label4 0 80;
  Evas_object.show label4;

  let label5 = Elm_label.add win in
  Elm_object.text_set label5 "And for this label we choose a different text, \
    for no reason other than we can.";
  Elm_label.line_wrap_set label5 `word;
  Evas_object.resize label5 200 40;
  Evas_object.move label5 0 110;
  Evas_object.show label5;

  let label6 = Elm_label.add win in
  Elm_object.text_set label6 "Short text";
  let (_ : bool) = Elm_object.style_set label6 "marker" in
  Evas_object.color_set label6 255 0 0 255;
  Evas_object.resize label6 200 15;
  Evas_object.move label6 0 140;
  Evas_object.show label6;

  Evas_object.resize win 200 170;
  Evas_object.show win;
  Elm.run ();
  Elm.shutdown ()
