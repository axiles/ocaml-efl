open Efl
open Format

let run = ref false

let progress_format_cb x =
  let files = int_of_float ((1. -. x) *. 14000.) in
  sprintf "%d files left" files

let on_changed =
  let tstart = ref 0. in
  let eta = ref 0. in
  fun label obj ->
    let x = Elm_progressbar.value_get obj in
    if x = 0. then (
      tstart := 0.;
      Elm_object.text_set label "ETA: N/A";
    ) else (
      if !tstart = 0. then tstart := Unix.time ();
      let tdiff = Unix.time () -. !tstart in
      eta := 0.3 *. !eta +. 0.7 *. (tdiff /. x) *. (1. -. x);
      let buf = sprintf "ETA: %.0fs" !eta in
      Elm_object.text_set label buf)

let add_pb win bx =
  let pb = Elm_progressbar.add win in
  Evas_object.size_hint_set pb [`expand; `hfill];
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
  Evas_object.size_hint_aspect_set ic `vertical 1 1;
  let pb = add_pb win bx in
  Elm_object.text_set pb "Label";
  Elm_object.part_content_set pb ~p:"icon" ic;
  Elm_progressbar.inverted_set pb true;
  Elm_progressbar.span_size_set pb 200;
  Elm_progressbar.unit_format_function_set pb progress_format_cb;
  Evas_object.show ic;
  Evas_object.show pb;
  pb

let add_pb4 win bx =
  let pb = add_pb win bx in
  Elm_object.text_set pb "Label";
  Evas_object.show pb;
  let label = Elm_label.add win in
  Elm_object.text_set label "ETA: N/A";
  Evas_object.size_hint_set label [`center; `expand];
  Elm_box.pack_end bx label;
  Evas_object.show label;
  Elm_connect.Progressbar.changed pb (on_changed label);
  pb

let add_pb5 win bx =
  let pb = Elm_progressbar.add win in
  Elm_progressbar.horizontal_set pb false;
  Evas_object.size_hint_set pb [`fill; `expand];
  Elm_box.pack_end bx pb;
  Elm_object.text_set pb "percent";
  Evas_object.show pb;
  pb

let add_pb6 win bx =
  let pb = add_pb win bx in
  Elm_progressbar.horizontal_set pb false;
  Elm_progressbar.span_size_set pb 80;
  Elm_progressbar.pulse_set pb true;
  Elm_progressbar.unit_format_function_set pb (fun x -> "");
  Elm_object.text_set pb "Infinite bounce";
  Evas_object.show pb;
  pb

let add_pb7 win bx =
  let ic = Elm_icon.add win in
  let buf = sprintf "%s/images/logo_small.png" (Elm_app.data_dir_get ()) in
  let (_ : bool) = Elm_image.file_set ic buf () in
  let pb = add_pb win bx in
  Elm_progressbar.horizontal_set pb false;
  Elm_object.text_set pb "Label";
  Elm_object.part_content_set pb ~p:"icon" ic;
  Elm_progressbar.inverted_set pb true;
  Elm_progressbar.unit_format_set pb "%1.2f%%";
  Elm_progressbar.span_size_set pb 200;
  Evas_object.show ic;
  Evas_object.show pb;
  pb

let add_pb8 win bx =
  let pb = add_pb win bx in
  let (_ : bool) = Elm_object.style_set pb "wheel" in
  Elm_object.text_set pb "Style: wheel";
  Elm_progressbar.pulse_set pb true;
  Evas_object.show pb;
  pb

let progressbar_example_value_set list =
  let pb1 = match list with [] -> assert false | x :: _ -> x in
  let progress = Elm_progressbar.value_get pb1 in
  let x = if progress < 1. then progress +. 0.0123 else 0. in
  List.iter (fun pb -> Elm_progressbar.value_set pb x) list;
  if x >= 1. then run := false

let timer_fun list =
  let rec loop () =
    Thread.delay 0.1;
    Ecore.call (fun () ->
      progressbar_example_value_set list);
    if !run then loop () in
  loop ()

let start_cb list_pb_pulse list_pb_values _ =
  List.iter (fun pb -> Elm_progressbar.pulse pb true) list_pb_pulse;
  if not !run then (
    let (_ : Thread.t) = Thread.create timer_fun list_pb_values in
    run := true;
  )

let stop_cb list_pb _ _ =
  List.iter (fun pb -> Elm_progressbar.pulse pb false) list_pb;
  run := false

let on_done list_pb _ =
  if !run then stop_cb list_pb () ()
  else Elm.exit ()

let add_bt win bt_bx label cb =
  let bt = Elm_button.add win in
  Elm_object.text_set bt label;
  Elm_connect.Button.clicked bt cb;
  Elm_box.pack_end bt_bx bt;
  Evas_object.show bt

let () =
  Elm.init ();

  Elm_app.info_set "elementary" ~checkfile:"images/logo_small.jpg" ();
  let win = Elm_win.add "progressbar" `basic in
  Elm_win.title_set win "Progress bar example";

  let bg = Elm_bg.add win in
  Elm_win.resize_object_add win bg;
  Evas_object.size_hint_set bg [`expand];
  Evas_object.show bg;

  let bx = Elm_box.add win in
  Elm_win.resize_object_add win bx;
  Evas_object.size_hint_set bx [`expand];
  Evas_object.show bx;

  let pb1 = add_pb1 win bx in
  let pb2 = add_pb2 win bx in
  let pb3 = add_pb3 win bx in
  let pb4 = add_pb4 win bx in

  let hbx = Elm_box.add win in
  Elm_box.horizontal_set hbx true;
  Evas_object.size_hint_set hbx [`expand; `fill];
  Elm_box.pack_end bx hbx;
  Evas_object.show hbx;

  let pb5 = add_pb5 win hbx in
  let pb6 = add_pb6 win hbx in
  let pb7 = add_pb7 win hbx in
  let pb8 = add_pb8 win bx in

  let bt_bx = Elm_box.add win in
  Elm_box.horizontal_set bt_bx true;
  Evas_object.size_hint_set bt_bx [`expand];
  Elm_box.pack_end bx bt_bx;
  Evas_object.show bt_bx;

  let list_bt = [("Start", start_cb); ("Stop", stop_cb)] in
  let list_pb = [pb2; pb6; pb8] in

  List.iter (fun (label, cb) -> add_bt win bt_bx label (cb  list_pb
      [pb1; pb3; pb4; pb5; pb7])) list_bt;
  Elm_connect.Win.delete_request win (on_done list_pb);

  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()
