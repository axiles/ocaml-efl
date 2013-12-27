(* Warning: this example is still under developpment *)

open Efl
open Printf

let () =
  Elm.init Sys.argv;
  let win = Elm_win.add "genlist" `basic in
  Elm_win.title_set win "Genlist - simple";
  Elm.policy_set `quit `last_window_closed;
  Elm_win.autodel_set win true;

  let bg = Elm_bg.add win in
  Evas_object.size_hint_weight_set bg Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  let box = Elm_box.add win in
  Evas_object.size_hint_weight_set box Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set box Evas.hint_fill Evas.hint_fill;
  Elm_win.resize_object_add win box;
  Evas_object.show box;

  let list = Elm_genlist.add win in
  let sel_mode = Elm_genlist.select_mode_get list in
  let always =  sel_mode = `always in
  let no_sel = sel_mode = `none in

  printf "default values:\n";
  printf "always select: %b\n" always;
  let hbounce, vbounce = Elm_scroller.bounce_get list in
  printf "bounce - horizontal %b, vertical: %b\n" hbounce vbounce;
  printf "homogeneous: %b\n" (Elm_genlist.homogeneous_get list);
  (*printf "horizontal mode: %b\n" (Elm_genlist.mode_get list);*)
  printf "longpress timeout: %0.3f\n" (Elm_genlist.longpress_timeout_get list);
  printf "multi selection: %b\n" (Elm_genlist.multi_select_get list);
  printf "no selection mode: %b\n" no_sel;
  (* TODO: policy_get *)
  printf "block count: %d\n" (Elm_genlist.block_count_get list);
  printf "%!";

  Elm_scroller.bounce_set list false false;
  Elm_genlist.homogeneous_set list false;
  (* TODO: mode_set *)
  Elm_genlist.multi_select_set list true;
  (* TODO: select_mode_set *)
  Elm_scroller.policy_set list `off `on;
  Elm_genlist.longpress_timeout_set list 0.5;
  Elm_genlist.block_count_set list 16;

  (* TODO: add items and itc *)

  Evas_object.size_hint_weight_set list Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set list Evas.hint_fill Evas.hint_fill;
  Elm_box.pack_end box list;
  Evas_object.show list;

  let hbox = Elm_box.add win in
  Elm_box.horizontal_set hbox true;
  Evas_object.size_hint_weight_set hbox Evas.hint_expand 0.;
  Evas_object.size_hint_align_set hbox Evas.hint_fill Evas.hint_fill;
  Elm_box.pack_end box hbox;
  Evas_object.show hbox;

  let btn = Elm_button.add win in
  Elm_object.text_set btn "Show status";
  Evas_object.size_hint_weight_set btn 0. 0.;
  Evas_object.size_hint_align_set btn 0.5 0.5;
  (* TODO: Add cb *)
  Elm_box.pack_end hbox btn;
  Evas_object.show btn;

  Evas_object.resize win 200 320;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()

