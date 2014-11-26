open Efl
open Printf

let changed_cb obj =
  printf "Value changed to %0.f\n%!" (Elm_spinner.value_get obj)

let delay_changed_cb obj =
  printf "Value delay changed to %0.f\n%!" (Elm_spinner.value_get obj)

let add_spinner win box =
   let sp = Elm_spinner.add win in
   Evas_object.size_hint_set sp [`hfill; `expand];
   Elm_box.pack_end box sp;
   Evas_object.show sp;
   sp

let () =
  Elm.init ();
  Elm.policy_quit_set `last_window_closed;

  let win = Elm_win.util_standard_add "spinner" "Spinner Example" in
  Elm_win.autodel_set win true;

  let bx = Elm_box.add win in
  Evas_object.size_hint_set bx [`expand];
  Elm_win.resize_object_add win bx;
  Evas_object.show bx;

  ignore (add_spinner win bx : Evas.obj);

  let sp = add_spinner win bx in
  Elm_spinner.label_format_set sp "Percentage %%%1.2f something";

  let sp = add_spinner win bx in
  Elm_spinner.label_format_set sp "%1.1f units";
  Elm_spinner.step_set sp 1.5;
  Elm_spinner.wrap_set sp true;
  Elm_spinner.min_max_set sp (-50.) 250.;

  let sp = add_spinner win bx in
  ignore (Elm_object.style_set sp "vertical" : bool);
  Elm_spinner.interval_set sp 0.2;

  let sp = add_spinner win bx in
  Elm_spinner.editable_set sp false;

  let sp = add_spinner win bx in
  Elm_spinner.editable_set sp false;
  let months = ["January"; "February"; "March"; "April"; "May"; "June"; "July";
    "August"; "Septembre"; "Octobre"; "Novembre"; "Decembre"] in
  Elm_spinner.min_max_set sp 1. (float (List.length months));
  let rec aux i = function
    | [] -> ()
    | x :: xs ->
      Elm_spinner.special_value_add sp (float i) x;
      aux (i + 1) xs in
  aux 1 months;

  let sp = add_spinner win bx in
  Elm_connect.Spinner.changed sp changed_cb;
  Elm_connect.Spinner.delay_changed sp delay_changed_cb;

  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()

