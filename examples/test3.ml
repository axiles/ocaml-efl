open Efl

let retval = ref (-1)

let win_del _ =
  retval := -1;
  Elm.exit ()

let on_ok _ =
  retval := 0;
  Elm.exit ()

let on_cancel _ =
  retval := -1;
  Elm.exit ()

let () =
  Elm.init ();
 
  let text =
    if Array.length Sys.argv > 1 then Sys.argv.(1) else "No text provided" in

  let win = Elm_win.add "dialog" `basic in
  Elm_win.title_set win "Dialog";
  Evas_object_smart.callback_add win Elm_sig.delete_request win_del;

  ignore (Elm_bg.addx ~size_hint:[] ~win win);

  let bx = Elm_box.addx ~size_hint:[] ~win win in

  let fr = Elm_frame.addx ~size_hint:[`weight0; `fill] ~box:bx win in
  ignore (Elm_object.style_set fr "pad_large");

  let lb = Elm_label.addx ~text win in
  Elm_object.content_set fr lb;

  let fr0 = Elm_frame.addx ~size_hint:[`weight0; `fill] ~box:bx win in
  ignore (Elm_object.style_set fr0 "outdent_bottom");

  let fr = Elm_frame.addx ~size_hint:[] win in
  ignore (Elm_object.style_set fr "pad_medium");
  Elm_object.content_set fr0 fr;

  let bx2 = Elm_box.addx ~size_hint:[] win in
  Elm_box.horizontal_set bx2 true;
  Elm_box.homogeneous_set bx2 true;
  Elm_object.content_set fr bx2;

  let bt = Elm_button.addx ~text:"OK" ~box:bx2 win in
  Evas_object_smart.callback_add bt Elm_sig.clicked on_ok;

  let bt = Elm_button.addx ~text:"Cancel" ~box:bx2 win in
  Evas_object_smart.callback_add bt Elm_sig.clicked on_cancel;

  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ();
  exit !retval
