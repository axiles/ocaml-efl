open Format
open Efl

let cb obj = printf "val is now: %d\n%!" (Elm_radio.value_get obj)

let format_obj obj =
  Evas_object.size_hint_weight_set obj Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set obj Evas.hint_fill Evas.hint_fill;
  Evas_object.show obj

type group =
| Nothing
| Cb_only
| Group_and_cb of Evas.obj

let add_radio win bx i icon_name group = 
  let radio = Elm_radio.add win in
  Elm_object.text_set radio (sprintf "Radio %d" i);
  Elm_radio.state_value_set radio i;
  (match icon_name with
  | None -> ()
  | Some s ->
    let ic = Elm_icon.add win in
    let (_ : bool) = Elm_icon.standard_set ic s in
    Elm_object.part_content_set radio ~p:"icon" ic);
  (match group with
  | Nothing | Cb_only -> ()
  | Group_and_cb g -> Elm_radio.group_add radio g);
  Elm_box.pack_end bx radio;
  format_obj radio;
  (match group with
  | Nothing -> ()
  | Cb_only | Group_and_cb _ ->
    Evas_object_smart.callback_add radio Elm_sig.changed cb);
  radio

let add_radio_next win bx i icon_name group =
  let g = match group with None -> Nothing | Some x -> Group_and_cb x in
  let _ = add_radio win bx i icon_name g in ()

let () =
  Elm.init ();

  let win = Elm_win.add "radio" `basic in
  Elm_win.title_set win "Radio";
  Elm_win.autodel_set win true;
  Elm.policy_quit_set `last_window_closed;

  let bg = Elm_bg.add win in
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  let bx = Elm_box.add win in
  Elm_box.horizontal_set bx true;
  format_obj bx;
  Elm_win.resize_object_add win bx;

  let group = Some (add_radio win bx 1 (Some "home") Cb_only) in
  let list = [(2, Some "file", group); (3, None, group); (4, None, None)] in
  List.iter (fun (i, icn, g) -> add_radio_next win bx i icn g) list;

  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()
