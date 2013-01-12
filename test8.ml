open Format
open Efl

let cb obj _ = printf "val is now: %d\n%!" (Elm_radio.value_get obj)

let () =
  Elm.init Sys.argv;

  let win = Elm_win.add "radio" `basic in
  Elm_win.title_set win "Radio";
  Elm_win.autodel_set win true;
  Elm.policy_set `quit `last_window_closed;

  let bg = Elm_bg.add win in
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  let bx = Elm_box.add win in
  Elm_box.horizontal_set bx true;
  Evas_object.size_hint_weight_set bx Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set bx Evas.hint_fill Evas.hint_fill;
  Elm_win.resize_object_add win bx;
  Evas_object.show bx;

  let radio = Elm_radio.add win in
  let group = radio in
  Elm_object.text_set radio "Radio 1";
  Elm_radio.state_value_set radio 1;
  Elm_radio.value_set group 1;
  let ic = Elm_icon.add win in
  Elm_icon.standard_set ic "home";
  Elm_object.part_content_set radio ~p:"icon" ic;
  Elm_radio.group_add radio group;
  Elm_box.pack_end bx radio;
  Evas_object.size_hint_weight_set radio Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set radio Evas.hint_fill Evas.hint_fill;
  Evas_object.show radio;
  Evas_object_smart.callback_add radio "changed" cb;

  let radio = Elm_radio.add win in
  Elm_object.text_set radio "Radio 2";
  Elm_radio.state_value_set radio 2;
  let ic = Elm_icon.add win in
  Elm_icon.standard_set ic "file";
  Elm_object.part_content_set radio ~p:"icon" ic;
  Elm_radio.group_add radio group;
  Elm_box.pack_end bx radio;
  Evas_object.size_hint_weight_set radio Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set radio Evas.hint_fill Evas.hint_fill;
  Evas_object.show radio;
  Evas_object_smart.callback_add radio "changed" cb;

  let radio = Elm_radio.add win in
  Elm_object.text_set radio "Radio 3";
  Elm_radio.state_value_set radio 3;
  Elm_radio.group_add radio group;
  Elm_box.pack_end bx radio;
  Evas_object.size_hint_weight_set radio Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set radio Evas.hint_fill Evas.hint_fill;
  Evas_object.show radio;
  Evas_object_smart.callback_add radio "changed" cb;

  let radio = Elm_radio.add win in
  Elm_object.text_set radio "Radio 4";
  Elm_radio.state_value_set radio 4;
  Elm_box.pack_end bx radio;
  Evas_object.size_hint_weight_set radio Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set radio Evas.hint_fill Evas.hint_fill;
  Evas_object.show radio;

  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()
