open Efl
open Format

let () =
  Elm.init ();

  Elm_app.info_set "elementary" ~checkfile:"images/plant_01.jpg" ();
  let win = Elm_win.add "image" `basic in
  Elm_win.title_set win "Image";
  Elm.policy_set `quit `last_window_closed;
  Elm_win.autodel_set win true;

  let bg = Elm_bg.add win in
  Elm_bg.color_set bg 255 255 255;
  Evas_object.size_hint_weight_set bg Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  let buf = sprintf "%s/images/plant_01.jpg" (Elm_app.data_dir_get ()) in

  let image = Elm_image.add win in
  if not (Elm_image.file_set image buf ()) then
    failwith (sprintf "Could not load image %s" buf);

  Elm_image.no_scale_set image true;
  Elm_image.resizable_set image false true;
  Elm_image.smooth_set image false;
  Elm_image.orient_set image `flip_horizontal;
  Elm_image.aspect_fixed_set image true;
  Elm_image.fill_outside_set image true;
  Elm_image.editable_set image true;

  Evas_object.size_hint_weight_set image Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win image;
  Evas_object.show image;

  Evas_object.resize win 320 320;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()
