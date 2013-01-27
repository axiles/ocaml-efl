open Efl

let retval = ref (-1)

let win_del _ _ =
  retval := -1;
  Elm.exit ()

let on_ok _ _ =
  retval := 0;
  Elm.exit ()

let on_cancel _ _ =
  retval := -1;
  Elm.exit ()

let () =
  Elm.init Sys.argv;
 
  let text =
    if Array.length Sys.argv > 1 then Sys.argv.(1) else "No text provided" in

  let win = Elm_win.add "dialog" `basic in
  Elm_win.title_set win "Dialog";
  Evas_object_smart.callback_add win "delete,request" win_del;

  let bg = Elm_bg.add win in
  Evas_object.size_hint_weight_set bg 0. 0.;
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  let bx = Elm_box.add win in
  Evas_object.size_hint_weight_set bx 0. 0.;
  Elm_win.resize_object_add win bx;
  Evas_object.show bx;

  let fr = Elm_frame.add win in
  let (_ : bool) = Elm_object.style_set fr "pad_large" in
  Evas_object.size_hint_weight_set fr 0. 0.;
  Evas_object.size_hint_align_set fr (-1.) (-1.);
  Elm_box.pack_end bx fr;
  Evas_object.show fr;

  let lb = Elm_label.add win in
  Elm_object.text_set lb text;
  Elm_object.content_set fr lb;
  Evas_object.show lb;

  let fr0 = Elm_frame.add win in
  let (_ : bool) = Elm_object.style_set fr0 "outdent_bottom" in
  Evas_object.size_hint_weight_set fr0 0. 0.;
  Evas_object.size_hint_align_set fr (-1.) (-1.);
  Elm_box.pack_end bx fr0;
  Evas_object.show fr0;

  let fr = Elm_frame.add win in
  let (_ : bool) = Elm_object.style_set fr "pad_medium" in
  Elm_object.content_set fr0 fr;
  Evas_object.show fr;

  let bx2 = Elm_box.add win in
  Elm_box.horizontal_set bx2 true;
  Elm_box.homogeneous_set bx2 true;
  Elm_object.content_set fr bx2;
  Evas_object.show bx2;

  let bt = Elm_button.add win in
  Elm_object.text_set bt "OK";
  Evas_object.size_hint_weight_set bt 1. 1.;
  Evas_object.size_hint_align_set bt (-1.) (-1.);
  Elm_box.pack_end bx2 bt;
  Evas_object.show bt;
  Evas_object_smart.callback_add bt "clicked" on_ok;

  let bt = Elm_button.add win in
  Elm_object.text_set bt "Cancel";
  Evas_object.size_hint_weight_set bt 1. 1.;
  Evas_object.size_hint_align_set bt (-1.) (-1.);
  Elm_box.pack_end bx2 bt;
  Evas_object.show bt;
  Evas_object_smart.callback_add bt "clicked" on_cancel;

  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ();
  exit !retval
