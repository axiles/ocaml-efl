open Format
open Efl

let cb obj = printf "val is now: %d\n%!" (Elm_radio.value_get obj)

type group =
| Nothing
| Cb_only
| Group_and_cb of Evas.obj

let add_radio win bx i icon_name group = 
  let radio = Elm_radio.addx ~text:(sprintf "Radio %d" i) ~box:bx win in
  Elm_radio.state_value_set radio i;
  (match icon_name with
  | None -> ()
  | Some s ->
    let ic = Elm_icon.add win in
    ignore (Elm_icon.standard_set ic s);
    Elm_object.part_content_set radio ~p:"icon" ic);
  (match group with
  | Nothing | Cb_only -> ()
  | Group_and_cb g -> Elm_radio.group_add radio g);
  (match group with
  | Nothing -> ()
  | Cb_only | Group_and_cb _ ->
    Elm_connect.Radio.changed radio cb);
  radio

let add_radio_next win bx i icon_name group =
  let g = match group with None -> Nothing | Some x -> Group_and_cb x in
  let _ = add_radio win bx i icon_name g in ()

let () =
  Elm.init ();

  let win = Elm_win.util_standard_add "radio" "Radio" in
  Elm_win.autodel_set win true;
  Elm.policy_quit_set `last_window_closed;

  let bx = Elm_box.addx ~win win in
  Elm_box.horizontal_set bx true;

  let group = Some (add_radio win bx 1 (Some "home") Cb_only) in
  let list = [(2, Some "file", group); (3, None, group); (4, None, None)] in
  List.iter (fun (i, icn, g) -> add_radio_next win bx i icn g) list;

  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()

