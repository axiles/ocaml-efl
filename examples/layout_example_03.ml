open Efl
open Format

let title = "example/title"
let swallow = "example/custom"

let btn_large = ref false

let swallow_btn_cb layout btn =
  if not !btn_large then (
    btn_large := true;
    Elm_object.signal_emit layout "button,enlarge" "";
    Elm_object.text_set btn "Reduce me!"
  ) else (
    btn_large := false;
    Elm_object.signal_emit layout "button,reduce" "";
    Elm_object.text_set btn "Enlarge me!")

let size_changed_cb layout emission source =
  Elm_layout.sizing_eval layout;
  let edje = Elm_layout.edje_get layout in
  let w, h = Edje.object_size_min_calc edje in
  printf "Minimum size for this theme: %dx%d\n%!" w h

let () =
  Elm.init Sys.argv;

  Elm_app.info_set "elementary" ~checkfile:"examples/layout_example.edj" ();
  let win = Elm_win.add "layout" `basic in
  let (_ : bool) = Elm.policy_set `quit `last_window_closed in
  Elm_win.autodel_set win true;

  let bg = Elm_bg.add win in
  Elm_bg.color_set bg 255 255 255;
  Evas_object.size_hint_weight_set bg Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  let layout = Elm_layout.add win in
  Evas_object.size_hint_weight_set layout Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win layout;
  let buf =
    sprintf "%s/examples/layout_example.edj" (Elm_app.data_dir_get ()) in
  let (_ : bool) = Elm_layout.file_set layout buf "example/mylayout3" in
  Evas_object.show layout;

  Elm_object.signal_callback_add layout "size,changed" "" size_changed_cb;

  (match Elm_layout.data_get layout "title" with
  | Some s ->
    Elm_win.title_set win s;
    Elm_object.part_text_set layout ~p:title s
  | None -> ());

  let btn = Elm_button.add win in
  Elm_object.text_set btn "Enlarge me!";
  Evas_object.size_hint_weight_set btn Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set btn Evas.hint_fill Evas.hint_fill;
  Elm_object.part_content_set layout ~p:swallow btn;
  Evas_object_smart.callback_add_safe btn Elm_button.E.clicked
    (swallow_btn_cb layout);

  Evas_object.resize win 160 160;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()
