open Efl

let () =
  Elm.init ();

  let win = Elm_win.util_standard_add "label" "Label" in
  Elm_win.autodel_set win true;
  Elm.policy_quit_set `last_window_closed;

  let label = Elm_label.addx
    ~text:"Some long text for our label, that is long but not too long."
    ~pos:(0, 10) ~size:(200, 15) ~size_hint:[] win in
  Elm_label.slide_duration_set label 3.;
  Elm_label.slide_mode_set label true;
  ignore (Elm_object.style_set label "slide_bounce");
  Evas_object.move label 0 10;
  Evas_object.resize label 200 15;

  let label2 = Elm_label.addx
    ~text:"This is the text for our second label, which is much longer than \
      the previous one, maybe even too long, but maybe not."
    ~size:(200, 15) ~pos:(0, 30) ~size_hint:[] win in
  Elm_label.ellipsis_set label2 true;

  let label3 = Elm_label.addx
    ~text:"Some more long text much as before, long but not too long."
    ~size:(200, 15) ~pos:(0, 50) win in
  Elm_label.line_wrap_set label3 `char;
  Elm_label.ellipsis_set label3 true;

  let label4 = Elm_label.addx
    ~text:"And for this label we choose a different text, for no reason other \
      than that we can."
    ~size:(200, 30) ~pos:(0, 80) win in
  Elm_label.line_wrap_set label4 `char;

  let label5 = Elm_label.addx
    ~text:"And for this label we choose a different text, for no reason other \
      than we can."
    ~size:(200, 40) ~pos:(0, 110) win in
  Elm_label.line_wrap_set label5 `word;

  ignore (Elm_label.addx ~text:"Short text" ~style:"marker"
    ~color:(255, 0, 0, 255) ~size:(200, 15) ~pos:(0, 140) win);

  Evas_object.resize win 200 170;
  Evas_object.show win;
  Elm.run ();
  Elm.shutdown ()
