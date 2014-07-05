open Efl
open Format

let print obj =
  printf "check %smarked\n%!" (if Elm_check.state_get obj then "" else "un")

let () =
  Elm.init ();

  let win = Elm_win.util_standard_add "check" "Check" in
  Elm_win.autodel_set win true;
  Elm.policy_quit_set `last_window_closed;

  let cb = Elm_check.addx ~text:"checkbox" ~pos:(10, 10) ~size:(200, 30) win in
  Elm_connect.Check.changed cb print;

  let icon = Evas_object.rectangle_add (Evas_object.evas_get win) in
  Evas_object.color_set icon 0 255 0 255;
  Evas_object.resize icon 20 20;
  Evas_object.show icon;

  ignore (Elm_check.addx ~text:"another checkbox"
    ~part_content:[("icon", icon)] ~pos:(10, 50) ~size:(200, 30) win);

  Elm_check.state_set cb true;

  Evas_object.resize win 200 100;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()
