open Efl
open Printf

let pos_selected_cb obj part =
  let sel = match part with
  | None -> "none"
  | Some s -> s in
  printf "Selection: %s\n" sel;
  let label = match Elm_actionslider.selected_label_get obj with
  | None -> "none"
  | Some s -> s in
  printf "Label selected: %s\n%!" label

let position_change_magnetic_cb obj part =
  if part = Some "left" then
  match part with
  | Some "left" -> Elm_actionslider.magnet_pos_set obj true false false
  | Some "right" -> Elm_actionslider.magnet_pos_set obj false false true
  | _ -> ()

let magnet_enable_disable_cb obj part =
  match part with
  | Some "left" -> Elm_actionslider.magnet_pos_set obj false true false
  | Some "right" -> Elm_actionslider.magnet_pos_set obj false false false
  | _ -> ()

let () =
  Elm.init ();
  let win = Elm_win.add "actionslider" `basic in
  Elm_win.title_set win "Actionslider";
  Elm_win.autodel_set win true;
  Elm.policy_quit_set `last_window_closed;

  let bg = Elm_bg.add win in
  Elm_win.resize_object_add win bg;
  Evas_object.size_hint_weight_set bg Evas.hint_expand 0.;
  Evas_object.show bg;

  let bx = Elm_box.add win in
  Evas_object.size_hint_weight_set bx Evas.hint_expand 0.;
  Elm_win.resize_object_add win bx;
  Evas_object.show bx;

  let asl = Elm_actionslider.add win in
  Evas_object.size_hint_weight_set asl Evas.hint_expand 0.;
  Evas_object.size_hint_align_set asl Evas.hint_fill 0.;
  Elm_actionslider.indicator_pos_set asl false false true;
  Elm_actionslider.magnet_pos_set asl false false true;
  Elm_object.part_text_set asl ~p:"left" "Snooze";
  Elm_object.part_text_set asl ~p:"right" "Stop";
  Elm_actionslider.enabled_pos_set asl true false true;
  Elm_connect.Actionslider.pos_changed asl position_change_magnetic_cb;
  Elm_connect.Actionslider.selected asl pos_selected_cb;
  Evas_object.show asl;
  Elm_box.pack_end bx asl;

  let asl = Elm_actionslider.add win in
  Evas_object.size_hint_weight_set asl Evas.hint_expand 0.;
  Evas_object.size_hint_align_set asl Evas.hint_fill 0.;
  Elm_actionslider.indicator_pos_set asl false true false;
  Elm_actionslider.magnet_pos_set asl false true false;
  Elm_object.part_text_set asl ~p:"left" "Snooze";
  Elm_object.part_text_set asl ~p:"right" "Stop";
  Elm_actionslider.enabled_pos_set asl true false true;
  Elm_connect.Actionslider.selected asl pos_selected_cb;
  Evas_object.show asl;
  Elm_box.pack_end bx asl;

  let asl = Elm_actionslider.add win in
  let (_ : bool) = Elm_object.style_set asl "bar" in
  Evas_object.size_hint_weight_set asl Evas.hint_expand 0.;
  Evas_object.size_hint_align_set asl Evas.hint_fill 0.;
  Elm_actionslider.indicator_pos_set asl true false false;
  Elm_actionslider.magnet_pos_set asl false true true;
  Elm_object.part_text_set asl ~p:"center" "Accept";
  Elm_object.part_text_set asl ~p:"right" "Reject";
  Elm_actionslider.enabled_pos_set asl false true true;
  Elm_connect.Actionslider.selected asl pos_selected_cb;
  Evas_object.show asl;
  Elm_box.pack_end bx asl;

  let asl = Elm_actionslider.add win in
  let (_ : bool) = Elm_object.style_set asl "bar" in
  Evas_object.size_hint_weight_set asl Evas.hint_expand 0.;
  Evas_object.size_hint_align_set asl Evas.hint_fill 0.;
  Elm_actionslider.indicator_pos_set asl true false false;
  Elm_actionslider.magnet_pos_set asl true false false;
  Elm_object.part_text_set asl ~p:"center" "Accept";
  Elm_object.part_text_set asl ~p:"right" "Reject";
  Elm_object.text_set asl "Go";
  Elm_connect.Actionslider.pos_changed asl position_change_magnetic_cb;
  Elm_connect.Actionslider.selected asl pos_selected_cb;
  Evas_object.show asl;
  Elm_box.pack_end bx asl;

  let asl = Elm_actionslider.add win in
  Evas_object.size_hint_weight_set asl Evas.hint_expand 0.;
  Evas_object.size_hint_align_set asl Evas.hint_fill 0.;
  Elm_actionslider.indicator_pos_set asl true false false;
  Elm_actionslider.magnet_pos_set asl true true true;
  Elm_object.part_text_set asl ~p:"left" "Left";
  Elm_object.part_text_set asl ~p:"center" "Center";
  Elm_object.part_text_set asl ~p:"right" "Right";
  Elm_object.text_set asl "Go";
  Elm_connect.Actionslider.selected asl pos_selected_cb;
  Evas_object.show asl;
  Elm_box.pack_end bx asl;

  let asl = Elm_actionslider.add win in
  Evas_object.size_hint_weight_set asl Evas.hint_expand 0.;
  Evas_object.size_hint_align_set asl Evas.hint_fill 0.;
  Elm_actionslider.indicator_pos_set asl false true false;
  Elm_actionslider.magnet_pos_set asl false true false;
  Elm_object.part_text_set asl ~p:"left" "Enable";
  Elm_object.part_text_set asl ~p:"center" "Magnet";
  Elm_object.part_text_set asl ~p:"right" "Disable";
  Elm_connect.Actionslider.pos_changed asl magnet_enable_disable_cb;
  Elm_connect.Actionslider.selected asl pos_selected_cb;
  Evas_object.show asl;
  Elm_box.pack_end bx asl;

  Evas_object.resize win 320 400;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()

