open Efl
open Printf

let generation_started_cb obj = print_endline "thumbnail generation started"

let generation_finished_cb obj = print_endline "thumbnail generation finished"

let generation_error_cb obj = print_endline "thumbnail generation_error"

let () =
  Elm.init ();
  ignore (Elm.need_ethumb () : bool);
  Elm_app.info_set "elementary" ~checkfile:"images/plant_01.jpg" ();
  Elm.policy_quit_set `last_window_closed;

  let win = Elm_win.util_standard_add "thumb" "Thumbnailer" in
  Elm_win.autodel_set win true;

  let thumb = Elm_thumb.add win in

  let add_cb s cb = Evas_object_smart.callback_add thumb s cb in
  add_cb Elm_sig.generate_start generation_started_cb;
  add_cb Elm_sig.generate_stop generation_finished_cb;
  add_cb Elm_sig.generate_error generation_error_cb;

  Elm_thumb.size_set thumb 160 160;
  Elm_thumb.editable_set thumb false;
  let buf = sprintf "%s/images/plant_01.jpg" (Elm_app.data_dir_get ()) in
  Elm_thumb.file_set thumb buf "";
  Elm_thumb.reload thumb;

  Evas_object.size_hint_set thumb [`expand];
  Elm_win.resize_object_add win thumb;
  Evas_object.show thumb;

  Evas_object.resize win 320 320;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()

