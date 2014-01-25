open Efl
open Printf
module DS = Elm_diskselector

let lbl =
  ["Sunday"; "Monday"; "Tuesday"; "Wednesday"; "Thursday"; "Friday"; "Saturday"]

let () =
  Elm.init ();
  Elm.policy_quit_set `last_window_closed;

  let win = Elm_win.util_standard_add "diskselector" "Diskselector Example" in
  Elm_win.autodel_set win true;

  let bx = Elm_box.add win in
  Evas_object.size_hint_set bx [`expand];
  Elm_win.resize_object_add win bx;
  Evas_object.show bx;

  let add_ds () =
    let ds = DS.add win in
    Evas_object.size_hint_set ds [`expand; `fill];
    Elm_box.pack_end bx ds;
    let aux label = ignore (DS.item_append ds ~label () : Elm_object.item) in
    List.iter aux lbl;
    Evas_object.show ds;
    ds in

  ignore (add_ds () : Evas.obj);

  let ds = add_ds () in
  DS.round_enabled_set ds true;
  DS.side_text_max_length_set ds 2;

  let ds = add_ds () in
  DS.display_item_num_set ds 5;
  printf "Number of Items in Diskselector : %d\n%!"
    (DS.display_item_num_get ds);

  let ds = add_ds () in
  Elm_scroller.bounce_set ds true true;
  Elm_scroller.policy_set ds `auto `on;

  Evas_object.resize win 320 421;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()

