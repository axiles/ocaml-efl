open Efl

let block_clicked obj = Evas_object.hide obj

let timeout obj = Evas_object.hide obj

let () =
  Elm.init ();
  let win = Elm_win.util_standard_add "popup" "Popup" in
  Elm_win.autodel_set win true;
  Elm.policy_quit_set `last_window_closed;

  let content = Elm_label.add win in
  Elm_object.text_set content "<align=center>Content</align>";

  let popup = Elm_popup.add win in
  Elm_popup.timeout_set popup 3.;
  Elm_connect.Popup.timeout popup timeout;

  Elm_object.content_set popup content;
  Elm_object.part_text_set popup ~p:"title,text" "Title";
  Evas_object.show popup;
  Elm_connect.Popup.block_clicked popup block_clicked;

  Evas_object.show win;
  Evas_object.resize win 480 800;

  Elm.run ();
  Elm.shutdown ()

