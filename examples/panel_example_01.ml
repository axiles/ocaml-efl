open Efl

let add_content win panel text =
  let content = Elm_label.add win in
  Elm_object.text_set content text;
  Evas_object.show content;
  Elm_object.content_set panel content

let add_panel win bx =
  let panel = Elm_panel.add win in
  Evas_object.size_hint_set panel [`expand; `fill];
  Evas_object.show panel;
  Elm_box.pack_end bx panel;
  panel

let () =
  Elm.init ();
  Elm.policy_quit_set `last_window_closed;

  let win = Elm_win.util_standard_add "panel" "Panel" in
  Elm_win.autodel_set win true;

  let bx = Elm_box.add win in
  Elm_box.horizontal_set bx false;
  Evas_object.size_hint_set bx [`expand];
  Elm_win.resize_object_add win bx;
  Evas_object.show bx;

  let panel = add_panel win bx in
  Elm_panel.orient_set panel `top;
  Elm_panel.toggle panel;
  add_content win panel "content";

  let panel = add_panel win bx in
  Elm_panel.orient_set panel `right;
  Elm_panel.hidden_set panel true;
  add_content win panel "content2";

  let panel = add_panel win bx in
  add_content win panel "content3";

  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()

