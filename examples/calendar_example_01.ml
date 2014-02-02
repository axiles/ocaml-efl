open Efl

let () =
  Elm.init ();
  let win = Elm_win.util_standard_add "calendar" "Calendar Creation Example" in
  Elm_win.autodel_set win true;
  Elm.policy_quit_set `last_window_closed;

  let cal = Elm_calendar.add win in
  Evas_object.size_hint_set cal [`expand];
  Elm_win.resize_object_add win cal;
  Evas_object.show cal;

  Evas_object.show win;
  Elm.run ();
  Elm.shutdown ()

