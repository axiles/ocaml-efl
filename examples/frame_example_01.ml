open Efl

let add_rect win cr cg cb =
  let r = Evas_object.rectangle_add (Evas_object.evas_get win) in
  Evas_object.color_set r cr cg cb 255;
  Evas_object.show r;
  r

let add_frame win (cr, cg, cb) text ?style (x, y) =
  let r = add_rect win cr cg cb in
  let f = Elm_frame.add win in
  Elm_object.content_set f r;
  Elm_object.text_set f text;
  Evas_object.resize f 100 100;
  Evas_object.move f x y;
  (match style with
  | None -> ()
  | Some s -> ignore (Elm_object.style_set f s : bool));
  Evas_object.show f

let () =
  Elm.init ();
  Elm.policy_quit_set `last_window_closed;
  let win = Elm_win.util_standard_add "frame" "Frame" in
  Elm_win.autodel_set win true;

  let add = add_frame win in
  add (255, 0, 0) "Default frame" (25, 25);
  add (0, 255, 0) "Padding frame" ~style:"pad_small" (150, 25);
  add (0, 0, 255) "Top outend frame" ~style:"outdent_top" (25, 150);
  add (0, 0, 0) "Bottom outend frame" ~style:"outdent_bottom" (150, 150);

  Evas_object.resize win 275 275;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()

