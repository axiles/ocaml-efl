open Efl
open Printf

let changed_cb obj day =
  let selected = Elm_dayselector.day_selected_get obj day in
  let buf = match day with
  | `sun -> "Sun"
  | `mon -> "Mon"
  | `tue -> "Tue"
  | `wed -> "Wed"
  | `thu -> "Thu"
  | `fri -> "Fri"
  | `sat -> "Sat"
  | `max -> "???" in
  fprintf stderr "%s state is %b\n%!" buf selected

let () =
  Elm.init ();
  Elm.policy_quit_set `last_window_closed;

  let win = Elm_win.util_standard_add "dayselector" "Dayselector Example" in
  Elm_win.autodel_set win true;

  let bx = Elm_box.add win in
  Evas_object.size_hint_set bx [`expand];
  Elm_win.resize_object_add win bx;
  Evas_object.show bx;

  let add_dayselector style =
    let ds = Elm_dayselector.add win in
    Evas_object.size_hint_set ds [`expand; `hfill];
    Evas_object_smart.callback_add ds Elm_sig.dayselector_changed changed_cb;
    (match style with
    | None -> ()
    | Some s -> ignore (Elm_object.style_set ds s : bool));
    Elm_box.pack_end bx ds;
    Evas_object.show ds in
  List.iter add_dayselector [None; Some "mon_first"];

  Evas_object.resize win 350 120;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()

