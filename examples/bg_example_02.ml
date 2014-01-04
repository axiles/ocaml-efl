open Efl
open Format

let on_done _ = Elm.exit ()

let () =
  Elm.init ();

  Elm_app.info_set "elementary" ~checkfile:"images/plant_01.jpg" ();
  let win = Elm_win.add "bg-image" `basic in
  Elm_win.title_set win "Bg Image";
  Evas_object_smart.callback_add win Elm_win.E.delete_request on_done;
  Elm_win.autodel_set win true;

  let bg = Elm_bg.add win in
  Elm_bg.load_size_set bg 20 20;
  Elm_bg.option_set bg `center;
  let buf = sprintf "%s/images/plant_01.jpg" (Elm_app.data_dir_get ()) in
  Elm_bg.file_set bg buf ();
  Evas_object.size_hint_weight_set bg Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  Evas_object.resize win 320 320;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()
