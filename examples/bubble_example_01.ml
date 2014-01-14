open Efl

let next_pos (p : Elm_bubble.pos) =
  match p with
  | `top_left -> `top_right
  | `top_right -> `bottom_left
  | `bottom_left -> `bottom_right
  | `bottom_right -> `top_left
  | `invalid -> `invalid

let bla =
  let corner = ref `top_left in
  fun obj ->
    corner := next_pos !corner;
    Elm_bubble.pos_set obj !corner

let () =
  Elm.init ();
  let win = Elm_win.add "bubble" `basic in
  Elm_win.title_set win "bubble";
  Elm_win.autodel_set win true;
  Elm.policy_quit_set `last_window_closed;
  Evas_object.resize win 300 200;
  Evas_object.show win;

  let bg = Elm_bg.add win in
  Evas_object.size_hint_weight_set bg Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  let label = Elm_label.add win in
  Elm_object.text_set label "This is CONTENT of our bubble";
  Evas_object.show label;

  let icon = Evas_object.rectangle_add (Evas_object.evas_get win) in
  Evas_object.color_set icon 0 0 255 255;
  Evas_object.show icon;

  let bubble = Elm_bubble.add win in
  Elm_object.part_content_set bubble ~p:"icon" icon;
  Elm_object.part_text_set icon ~p:"info" "INFO";
  Elm_object.text_set bubble "LABEL";
  Elm_object.content_set bubble label;
  Evas_object.resize bubble 300 100;
  Evas_object.show bubble;

  Evas_object_smart.callback_add bubble Elm_bubble.E.clicked bla;

  let label = Elm_label.add win in
  Elm_object.text_set label "Bubble with no icon, info or label";
  Evas_object.show label;

  let bubble = Elm_bubble.add win in
  Elm_object.content_set bubble label;
  Evas_object.resize bubble 200 50;
  Evas_object.move bubble 0 110;
  Evas_object.show bubble;

  Elm.run ();
  Elm.shutdown ()

