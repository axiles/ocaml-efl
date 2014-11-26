open Efl

let hide obj = Evas_object.hide obj

let add_notify win bx ?orient allow_events ?timeout ?cb name =
  let content = Elm_label.add win in
  Elm_object.text_set content name;
  Evas_object.show content;

  let notify = Elm_notify.add win in
  (match orient with
  | Some((h, v)) -> Elm_notify.align_set notify h v
  | None -> ());
  Elm_notify.allow_events_set notify allow_events;
  (match timeout with Some x -> Elm_notify.timeout_set notify x | None -> ());
  Elm_object.content_set notify content;
  Evas_object.size_hint_weight_set notify Evas.hint_expand Evas.hint_expand;
  Evas_object.show notify;
  Elm_box.pack_end bx notify;
  (match cb with
  | Some f-> Elm_connect.Notify.block_clicked notify f
  | None -> ())

let add_notify1 win bx = add_notify win bx false ~timeout:5. ~cb:hide "default"
let add_notify2 win bx name orient = add_notify win bx ~orient true name

let () =
  Elm.init ();

  let win = Elm_win.add "notify" `basic in
  Elm_win.title_set win "Notify";
  Elm_win.autodel_set win true;
  Elm.policy_quit_set `last_window_closed;

  let bg = Elm_bg.add win in
  Evas_object.size_hint_weight_set bg Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  let bx = Elm_box.add win in
  Elm_box.horizontal_set bx false;
  Evas_object.size_hint_weight_set bx Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set bx Evas.hint_fill Evas.hint_fill;
  Elm_win.resize_object_add win bx;
  Evas_object.show bx;
  
  add_notify1 win bx;
  add_notify2 win bx "bottom" (0.5, 1.);
  add_notify2 win bx "center" (0.5, 0.5);

  Evas_object.resize win 100 200;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()
