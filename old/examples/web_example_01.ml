open Efl

let url = "http://www.enlightenment.org"

let () =
  Elm.init ();
  if not (Elm.need_web ()) then exit 1;
  Elm.policy_quit_set `last_window_closed;

  let win = Elm_win.add "Elementary Webkit Widget" `basic in
  Elm_win.autodel_set win true;
  Evas_object.resize win 720 600;
  Evas_object.show win;

  let web = Elm_web.add win in
  Evas_object.size_hint_set web [`expand];
  Elm_win.resize_object_add win web;
  Elm_web.history_enabled_set win false;

  if not (Elm_web.url_set web url) then (
    print_endline "URL not found";
    exit 1);
  Evas_object.show web;

  Elm.run ();
  Elm.shutdown ()

