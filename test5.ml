open Printf
open Scanf

let () =
  Elm.init Sys.argv;

  let win = Elm_win.add "Button example" `basic in
  Elm.policy_set `quit `last_window_closed;
  Elm_win.title_set win "Button example";
  Elm_win.autodel_set win true;
  Evas_object.resize win 300 320;
  Evas_object.show win;

  let bg = Elm_bg.add win in
  Evas_object.size_hint_weight_set bg Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  let add_param_button box text =
    let btn = Elm_button.add win in
    Elm_object.text_set btn text;
    Elm_box.pack_end box btn;
    Evas_object.show btn;
    btn in
  
  let add_param_line box name val_list =
    let box2 = Elm_box.add win in
    Elm_box.horizontal_set box2 true;
    Evas_object.size_hint_weight_set box2 Evas.hint_expand 0.;
    Elm_box.pack_end box box2;
    Evas_object.show box2;
    let get_text x = sprintf "%s: %.1f" name x in
    List.map (fun x -> add_param_button box2 (get_text x)) val_list
  in

  let add_icon_button box icon_name cursor =
    let btn = Elm_button.add win in
    (match cursor with
    | Some horizontal ->
      Elm_button.autorepeat_set btn true;
      Elm_button.autorepeat_initial_timeout_set btn 1.;
      Elm_button.autorepeat_gap_timeout_set btn 0.5;
      let wx, wy, ax, ay =
        let w = Evas.hint_expand and a = Evas.hint_fill in
        if horizontal then (w, 0., a, 0.) else (0., w, 0., a) in
      Evas_object.size_hint_weight_set btn wx wy;
      Evas_object.size_hint_align_set btn ax ay
    | None ->
      Evas_object.size_hint_weight_set btn Evas.hint_expand Evas.hint_expand);
    Elm_box.pack_end box btn;
    Evas_object.show btn;
    let icon = Elm_icon.add win in
    Elm_icon.standard_set icon icon_name;
    Elm_object.part_content_set btn ~p:"icon" icon;
    btn in

  let add_cursor_button box icon_name horizontal =
    add_icon_button box icon_name (Some horizontal) in

  let box = Elm_box.add win in
  Evas_object.size_hint_weight_set box Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win box;
  Evas_object.show box;

  let initial_param_list = add_param_line box "Initial" [0.; 1.; 5.] in
  let gap_param_list = add_param_line box "Gap" [0.1; 0.5; 1.] in

  let cursor_up = add_cursor_button box "arrow_up" true in

  let box2 = Elm_box.add win in
  Elm_box.horizontal_set box2 true;
  Evas_object.size_hint_weight_set box2 Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set box2 Evas.hint_fill Evas.hint_fill;
  Elm_box.pack_end box box2;
  Evas_object.show box2;

  let cursor_left = add_cursor_button box2 "arrow_left" false in
  let mid = add_icon_button box2 "close" None in
  let cursor_right = add_cursor_button box2 "arrow_right" false in

  let cursor_down = add_cursor_button box "arrow_down" true in

  let cursors = [cursor_up; cursor_down; cursor_left; cursor_right] in

  let icon_still = ref None in

  let release_cb _ _ =
    match !icon_still with
    | None -> ()
    | Some icon ->
      Elm_object.part_content_set mid ~p:"icon" icon;
      icon_still := None in

  let move_cursor obj _ =
    (match !icon_still with
    | Some _ -> ()
    | None ->
      let icon_s = Elm_object.content_unset mid in
      Evas_object.hide icon_s;
      icon_still := Some icon_s;
      let icon = Elm_icon.add mid in
      Elm_icon.standard_set icon "chat";
      Elm_object.part_content_set mid ~p:"icon" icon);
    let ax, ay = Evas_object.size_hint_align_get mid in
    let aux (ax1, ay1) (cursor, dx, dy) =
      if obj == cursor then (ax1 +. dx, ay1 +. dy) else (ax1, ay1) in
    let sp = 0.05 in
    let list =
      [(cursor_up, 0., -. sp); (cursor_down, 0., sp); (cursor_left, -. sp, 0.);
        (cursor_right, sp, 0.)] in
    let ax1, ay1 = List.fold_left aux (ax, ay) list in
    let ax2 = min (max ax1 0.) 1. and ay2 = min (max ay1 0.) 1. in
    Evas_object.size_hint_align_set mid ax2 ay2 in

  let aux1 cursor =
    Evas_object_smart.callback_add cursor "repeated" move_cursor;
    Evas_object_smart.callback_add cursor "unpressed" release_cb in
  List.iter aux1 cursors;

  let options_cb obj _ =
    let s, x = sscanf (Elm_object.text_get obj) "%s %f" (fun s x -> (s, x)) in
    let f = match s with
    | "Initial:" -> Elm_button.autorepeat_initial_timeout_set
    | "Gap:" -> Elm_button.autorepeat_gap_timeout_set
    | _ -> assert false in
    List.iter (fun cursor -> f cursor x) cursors in

  let aux2 cursor =
    Evas_object_smart.callback_add cursor "clicked" options_cb in
  List.iter aux2 (initial_param_list @ gap_param_list);




  Elm.run ();
  Elm.shutdown ();
