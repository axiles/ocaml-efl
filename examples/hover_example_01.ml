open Efl

let show_hover hover obj = Evas_object.show hover

let hide_hover hover obj= Evas_object.hide hover

let () =
  Elm.init ();
  Elm.policy_quit_set `last_window_closed;

  let win = Elm_win.util_standard_add "hover" "Hover" in
  Elm_win.autodel_set win true;
  
  let add_rect r g b =
    let rect = Evas_object.rectangle_add (Evas_object.evas_get win) in
    Evas_object.size_hint_min_set rect 25 25;
    Evas_object.color_set rect r g b 255;
    Evas_object.show rect;
    rect in
  let rect = add_rect 255 0 0 in
  let rect2 = add_rect 0 255 0 in
  let rect3 = add_rect 0 0 255 in

  let bt = Elm_button.add win in
  Elm_object.text_set bt "Show hover";
  Evas_object.move bt 60 90;
  Evas_object.resize bt 80 20;
  Evas_object.show bt;

  let bt2 = Elm_button.add win in
  Elm_object.text_set bt2 "Hide hover";
  Evas_object.show bt2;

  let hover = Elm_hover.add win in
  Elm_hover.parent_set hover win;
  Elm_hover.target_set hover bt;

  ignore (Elm_object.style_set hover "popout" : bool);

  Elm_object.part_content_set hover ~p:"left" rect;
  Elm_object.part_content_set hover ~p:"top" rect2;
  Elm_object.part_content_set hover ~p:"right" rect3;
  Elm_object.part_content_set hover ~p:"middle" bt2;

  Evas_object_smart.callback_add bt Elm_button.E.clicked (show_hover hover);
  Evas_object_smart.callback_add bt2 Elm_button.E.clicked (hide_hover hover);

  Evas_object.resize win 200 200;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()

