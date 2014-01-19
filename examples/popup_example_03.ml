open Efl
open Printf

let item_selected obj event_info =
  let it = Elm_object.item_of_ptr event_info in
  printf "popup item selected: %s\n%!" (Elm_object.item_text_get it)

let response_cb popup obj = Evas_object.hide popup

let () =
  Elm.init ();
  Elm_app.info_set "elementary" ~checkfile:"images/logo_small.png" ();
  Elm.policy_quit_set `last_window_closed;

  let win = Elm_win.util_standard_add "popup" "Popup" in
  Elm_win.autodel_set win true;

  let popup = Elm_popup.add win in

  let icon1 = Elm_icon.add popup in
  let buf = sprintf "%s/images/logo_small.png" (Elm_app.data_dir_get ()) in
  ignore (Elm_image.file_set icon1 buf () : bool);
  
  Elm_object.part_text_set popup ~p:"title,text" "Title";

  let add_item label =
    Elm_popup.item_append popup ~label ~func:item_selected () in
  let add_item1 label = ignore (add_item label : Elm_object.item) in
  List.iter add_item1 ["Message"; "Email"; "Contact"; "Video"; "Music"; "Memo"];
  let popup_it1 = add_item "Radio" in

  Elm_object.item_text_set popup_it1 "FM";
  List.iter add_item1 ["Messenger"; "Settings"; "App Installer"; "Browser"];
  ignore (Elm_popup.item_append popup ~label:"Weather" ~icon:icon1
    ~func:item_selected ());
  add_item1 "News feed";

  let btn1 = Elm_button.add popup in
  Elm_object.text_set btn1 "Ok";

  Elm_object.part_content_set popup ~p:"button1" btn1; 
  Evas_object_smart.callback_add btn1 Elm_sig.clicked (response_cb popup);

  let btn2 = Elm_button.add popup in
  Elm_object.text_set btn2 "Cancel";

  Elm_object.part_content_set popup ~p:"button2" btn2;
  Evas_object_smart.callback_add btn2 Elm_sig.clicked (response_cb popup);

  Evas_object.show popup;

  Evas_object.resize win 480 800;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()

