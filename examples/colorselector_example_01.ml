open Efl
open Printf

let color_change rect obj =
  let r, g, b, a = Elm_colorselector.color_get obj in
  let r1, g1, b1 = Evas.color_argb_premul a r g b in
  Evas_object.color_set rect r1 g1 b1 a

let color_palette_clicked_cb rect obj color_it =
  let r, g, b, a = Elm_colorselector.palette_item_color_get color_it in
  let r1, g1, b1 = Evas.color_argb_premul a r g b in
  Evas_object.color_set rect r1 g1 b1 a

let color_palette_longpressed_cb obj it =
  let r, g, b, a = Elm_colorselector.palette_item_color_get it in
  printf "\ncolor = %d-%d-%d-%d\n%!" r g b a

let add_frame win bx label =
  let fr = Elm_frame.add win in
  Evas_object.size_hint_set fr [`hweight 1.; `vweight 0.5; `fill];
  Elm_object.text_set fr label;
  Elm_box.pack_end bx fr;
  Evas_object.show fr;
  fr

let () =
  Elm.init ();
  Elm.policy_quit_set `last_window_closed;

  let win = Elm_win.util_standard_add "color selector" "Color selector" in
  Elm_win.autodel_set win true;

  let bx = Elm_box.add win in
  Evas_object.size_hint_set bx [`expand];
  Elm_win.resize_object_add win bx;
  Evas_object.show bx;

  let fr = add_frame win bx "Color View" in

  let rect = Evas_object.rectangle_add (Evas_object.evas_get win) in
  Elm_object.content_set fr rect;
  Evas_object.color_set rect 255 90 18 255;
  Evas_object.show rect;

  let fr = add_frame win bx "Color Selector" in

  let cs = Elm_colorselector.add win in
  Elm_colorselector.palette_name_set cs "painting";
  Evas_object.size_hint_set cs [`hexpand; `hfill; `valign 0.];
  Elm_colorselector.color_set cs 255 90 18 255;
  Evas_object.show cs;
  let add_cb s cb = Evas_object_smart.callback_add cs s cb in
  add_cb Elm_sig.changed (color_change rect);
  add_cb Elm_sig.color_item_selected (color_palette_clicked_cb rect);
  add_cb Elm_sig.color_item_longpressed color_palette_longpressed_cb;
  Elm_object.content_set fr cs;

  Evas_object.resize win 320 480;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()

