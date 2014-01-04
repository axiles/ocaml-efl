(* WARNING: This example is still in heavy development *)

open Efl
open Format
open Elm_win.E
open Elm_button.E

let on_done _ = Elm.exit ()

let add_pb win bx =
  let pb = Elm_progressbar.add win in
  Evas_object.size_hint_weight_set pb Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_weight_set pb Evas.hint_fill 0.5;
  Elm_box.pack_end bx pb;
  pb

let add_pb1 win bx =
  let pb = add_pb win bx in
  Evas_object.show pb;
  pb

let add_pb2 win bx =
  let pb = add_pb win bx in
  Elm_object.text_set pb "Infinite bounce";
  Elm_progressbar.pulse_set pb true;
  Evas_object.show pb;
  pb

let add_pb3 win bx =
  let ic = Elm_icon.add win in
  let buf = sprintf "%s/images/logo_small.png" (Elm_app.data_dir_get ()) in
  let (_ : bool) = Elm_image.file_set ic buf () in
  let pb = add_pb win bx in
  Elm_object.text_set pb "Label";
  Elm_object.part_content_set pb ~p:"icon" ic;
  Elm_progressbar.inverted_set pb true;
  Elm_progressbar.span_size_set pb 200;
  Evas_object.show ic;
  Evas_object.show pb;
  pb

let add_pb4 win bx =
  let pb = add_pb win bx in
  Elm_object.text_set pb "Label";
  Evas_object.show pb;
  let label = Elm_label.add win in
  Elm_object.text_set label "ETA: N/A";
  Evas_object.size_hint_weight_set label Evas.hint_expand Evas.hint_expand;
  Elm_box.pack_end bx label;
  Evas_object.show label;
  pb

let start_cb list_pb _ =
  List.iter (fun pb -> Elm_progressbar.pulse pb true) list_pb

let stop_cb list_pb _ =
  List.iter (fun pb -> Elm_progressbar.pulse pb false) list_pb

let add_bt win bt_bx label cb =
  let bt = Elm_button.add win in
  Elm_object.text_set bt label;
  Evas_object_smart.callback_add bt clicked cb;
  Elm_box.pack_end bt_bx bt;
  Evas_object.show bt

let () =
  Elm.init ();

  Elm_app.info_set "elementary" ~checkfile:"images/logo_small.jpg" ();
  let win = Elm_win.add "progressbar" `basic in
  Elm_win.title_set win "Progress bar example";
  Evas_object_smart.callback_add win delete_request on_done;

  let bg = Elm_bg.add win in
  Elm_win.resize_object_add win bg;
  Evas_object.size_hint_weight_set bg Evas.hint_expand Evas.hint_expand;
  Evas_object.show bg;

  let bx = Elm_box.add win in
  Elm_win.resize_object_add win bx;
  Evas_object.size_hint_weight_set bx Evas.hint_expand Evas.hint_expand;
  Evas_object.show bx;

  let (_ : Evas.obj) = add_pb1 win bx in
  let pb2 = add_pb2 win bx in
  let (_ : Evas.obj) = add_pb3 win bx in
  let (_ : Evas.obj) = add_pb4 win bx in

  let bt_bx = Elm_box.add win in
  Elm_box.horizontal_set bt_bx true;
  Evas_object.size_hint_weight_set bt_bx Evas.hint_expand Evas.hint_expand;
  Elm_box.pack_end bx bt_bx;
  Evas_object.show bt_bx;

  let list_bt = [("Start", start_cb); ("Stop", stop_cb)] in
  List.iter (fun (label, cb) -> add_bt win bt_bx label (cb [pb2])) list_bt;

  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()
