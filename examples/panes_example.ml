open Efl
open Printf

let press obj = print_endline "Pressed"

let unpress obj =
  printf "Unpress, size: %f\n%!" (Elm_panes.content_left_size_get obj)

let clicked obj = print_endline "Clicked"

let clicked_double =
  let size = ref 0. in
  fun obj ->
    let tmp_size = Elm_panes.content_left_size_get obj in
    if tmp_size > 0. then (
      Elm_panes.content_left_size_set obj 0.;
      print_endline "Double clicked, hidding."
    ) else (
      Elm_panes.content_left_size_set obj !size;
      print_endline "Double clicked, restoring size."
    );
    size := tmp_size

let () =
  Elm.init ();
  Elm.policy_quit_set `last_window_closed;

  let win = Elm_win.util_standard_add "panes" "Panes Example" in
  Elm_win.autodel_set win true;
  Elm_win.focus_highlight_enabled_set win true;

  let panes = Elm_panes.add win in
  Evas_object.size_hint_set panes [`expand];
  Elm_win.resize_object_add win panes;
  Evas_object.show panes;

  let bt = Elm_button.add win in
  Elm_object.text_set bt "Left";
  Evas_object.size_hint_set bt [`expand; `fill];
  Evas_object.show bt;
  Elm_object.part_content_set panes ~p:"left" bt;

  let panes_h = Elm_panes.add win in
  Elm_panes.horizontal_set panes_h true;
  Evas_object.size_hint_set panes_h [`expand; `fill];
  Evas_object.show panes_h;
  Elm_object.part_content_set panes ~p:"right" panes_h;

  let bt = Elm_button.add win in
  Elm_object.text_set bt "Up";
  Evas_object.size_hint_set bt [`expand; `fill];
  Evas_object.show bt;
  Elm_object.part_content_set panes_h ~p:"left" bt;

  let bt = Elm_button.add win in
  Elm_object.text_set bt "Down";
  Evas_object.size_hint_set bt [`expand; `fill];
  Evas_object.show bt;
  Elm_object.part_content_set panes_h ~p:"right" bt;

  let add_cb = Evas_object_smart.callback_add panes in
  add_cb Elm_sig.clicked clicked;
  add_cb Elm_sig.clicked_double clicked_double;
  add_cb Elm_sig.press press;
  add_cb Elm_sig.unpress unpress;

  Evas_object.resize win 320 400;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()

