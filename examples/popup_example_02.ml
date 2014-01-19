open Efl
open Printf

let response_cb popup obj = Evas_object.del popup

let () =
  Elm.init ();
  Elm_app.info_set "elementary" ~checkfile:"images/logo_small.png" ();
  Elm.policy_quit_set `last_window_closed;

  let win = Elm_win.util_standard_add "popup" "Popup" in
  Elm_win.autodel_set win true;

  let popup = Elm_popup.add win in

  Elm_object.text_set popup  "This is the Content-Text for popup. The wrap \
    for the content-text is character wrapping";
  Elm_popup.content_text_wrap_type_set popup `char;

  Elm_object.part_text_set popup ~p:"title,text" "Title";

  let icon1 = Elm_icon.add popup in
  let buf = sprintf "%s/images/logo_small.png" (Elm_app.data_dir_get ()) in
  ignore (Elm_image.file_set icon1 buf () : bool);
  Elm_object.part_content_set popup ~p:"title,icon" icon1;

  let btn1 = Elm_button.add popup in
  Elm_object.text_set btn1 "Ok";

  Elm_object.part_content_set popup ~p:"button1" btn1; 
  Evas_object_smart.callback_add btn1 Elm_sig.clicked (response_cb popup);

  let btn2 = Elm_button.add popup in
  Elm_object.text_set btn2 "Cancel";

  Elm_object.part_content_set popup ~p:"button2" btn2;
  Evas_object_smart.callback_add btn2 Elm_sig.clicked (response_cb popup);

  let btn3 = Elm_button.add popup in
  Elm_object.text_set btn3 "Close";

  Elm_object.part_content_set popup ~p:"button3" btn3;
  Evas_object_smart.callback_add btn3 Elm_sig.clicked (response_cb popup);
  Elm_popup.orient_set popup `top;
  Evas_object.show popup;

  Evas_object.resize win 480 800;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()

