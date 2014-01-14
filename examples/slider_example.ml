open Efl
open Printf

let changed_cb obj =
  let x = Elm_slider.value_get obj in
  printf "Changed to %1.2f\n%!" x

let delay_changed_cb obj =
  let x = Elm_slider.value_get obj in
  printf "Delay changed to %1.2f\n%!" x

let indicator_format x = sprintf "%1.2f u" x

let () =
  Elm.init ();
  Elm.policy_quit_set `last_window_closed;

  let win = Elm_win.util_standard_add "slider" "Slider Example" in
  Elm_win.autodel_set win true;

  let bx = Elm_box.add win in
  Evas_object.size_hint_set bx [`expand];
  Elm_win.resize_object_add win bx;
  Evas_object.show bx;

  let sl = Elm_slider.add win in
  Evas_object.size_hint_set sl [`hfill; `expand];
  Elm_box.pack_end bx sl;
  Evas_object.show sl;
  
  let sl = Elm_slider.add win in
  Elm_object.text_set sl "Counter";

  let ic = Elm_icon.add win in
  ignore (Elm_icon.standard_set ic "home" : bool);
  Elm_image.resizable_set ic false false;
  Elm_object.part_content_set sl ~p:"icon" ic;

  let ic = Elm_icon.add win in
  ignore (Elm_icon.standard_set ic "folder" : bool);
  Elm_image.resizable_set ic false false;
  Elm_object.part_content_set sl ~p:"end" ic;
  
  Evas_object.size_hint_set sl [`hfill; `expand];
  Elm_box.pack_end bx sl;
  Evas_object.show sl;
 
  let sl = Elm_slider.add win in
  Elm_slider.value_set sl 1.;
  Elm_slider.span_size_set sl 200;
  Evas_object.size_hint_set sl [`hfill; `expand];
  Elm_box.pack_end bx sl;
  Evas_object.show sl;

  let sl = Elm_slider.add win in
  Elm_slider.unit_format_set sl "%1.0f units";
  Elm_slider.min_max_set sl 0. 100.;
  Evas_object.size_hint_set sl [`hfill; `expand];
  Elm_box.pack_end bx sl;
  Evas_object.show sl;

  let sl = Elm_slider.add win in
  Elm_slider.indicator_format_set sl "%1.2f";
  Elm_slider.inverted_set sl true;
  Evas_object.size_hint_set sl [`hfill; `expand];
  Elm_box.pack_end bx sl;
  Evas_object.show sl;

  let sl = Elm_slider.add win in
  Elm_slider.horizontal_set sl false;
  Elm_slider.indicator_format_function_set sl indicator_format;
  Evas_object.size_hint_set sl [`vfill; `vexpand];
  Elm_box.pack_end bx sl;
  Evas_object.show sl;

  let sl = Elm_slider.add win in
  Elm_slider.unit_format_set sl "%1.3f units";
  Evas_object.size_hint_set sl [`hfill; `expand];
  Elm_box.pack_end bx sl;
  Evas_object.show sl;
  Evas_object_smart.callback_add sl Elm_slider.E.changed changed_cb;
  Evas_object_smart.callback_add sl Elm_slider.E.delay_changed delay_changed_cb;


  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()
