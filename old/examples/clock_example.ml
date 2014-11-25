open Efl

let () =
  Elm.init ();
  Elm.policy_quit_set `last_window_closed;

  let win = Elm_win.util_standard_add "clock" "Clock Example" in
  Elm_win.autodel_set win true;

  let bx = Elm_box.add win in
  Evas_object.size_hint_set bx [`expand];
  Elm_win.resize_object_add win bx;
  Evas_object.show bx;

  let add_clock () =
    let ck = Elm_clock.add win in
    Elm_box.pack_end bx ck;
    Evas_object.show ck;
    ck in

  ignore (add_clock () : Evas.obj);

  let ck = add_clock () in
  Elm_clock.show_am_pm_set ck true;

  let ck = add_clock () in
  Elm_clock.show_seconds_set ck false;
  Elm_clock.time_set ck 10 11 12;

  let ck = add_clock () in
  Elm_clock.edit_set ck true;
  Elm_clock.show_am_pm_set ck true;
  Elm_clock.time_set ck 10 11 12;

  let ck = add_clock () in
  Elm_clock.show_seconds_set ck true;
  Elm_clock.edit_set ck true;
  Elm_clock.edit_mode_set ck [`hour_unit; `min_unit; `sec_unit];

  Evas_object.show win;
  Elm.run ();
  Elm.shutdown ()

