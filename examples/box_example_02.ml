open Efl

let test_box_transition_change box list0 =
  let hd0, tl0 = match list0 with
  | [] -> assert false
  | x :: xs -> (x, xs) in
  let rec aux list last_layout () =
    let next_layout, list1 = match list with
    | [] -> (hd0, tl0)
    | x :: xs -> (x, xs) in
    let free () = () in
    let aux1 = aux list1 next_layout in
    let layout_data = Elm_box.transition_new 2. last_layout free next_layout
      free aux1 in
    Elm_box.layout_set box (Elm_box.layout_transition layout_data) free in
  aux list0 Evas_object.box_layout_horizontal ()


let transitions = Evas_object.([
  box_layout_vertical;
  box_layout_horizontal;
  box_layout_stack;
  box_layout_homogeneous_vertical;
  box_layout_homogeneous_horizontal;
  box_layout_flow_vertical;
  box_layout_flow_horizontal;
  box_layout_stack])

let () =
  Elm.init ();
  Elm.policy_quit_set `last_window_closed;

  let win = Elm_win.util_standard_add "box-transition" "Box transition" in
  Elm_win.autodel_set win true;
  Evas_object.resize win 300 320;
  Evas_object.show win;

  let bigbox = Elm_box.addx ~size_hint:[`expand] ~win win in

  let bx = Elm_box.addx ~box:bigbox ~size_hint:[] win in 
  Elm_box.horizontal_set bx true;

  let bt_add = Elm_button.addx ~text:"Add" ~box:bx ~size_hint:[] win in

  let bt_clear = Elm_button.addx ~text:"Clear" ~box:bx ~size_hint:[] win in

  let bx = Elm_box.addx ~box:bigbox win in

  let unpack_cb obj =
    Elm_box.unpack bx obj;
    Evas_object.move obj 0 50;
    Evas_object.color_set obj 128 64 0 128 in

  let bt = Elm_button.addx ~text:"Button 1" ~box:bx win in
  Evas_object_smart.callback_add bt Elm_sig.clicked unpack_cb;

  let bt = Elm_button.addx ~text:"Button 2" ~size_hint:[`hexpand; `valign 1.]
    ~box:bx win in
  Evas_object_smart.callback_add bt Elm_sig.clicked unpack_cb;
  let bt = Elm_button.addx ~text:"Button 3" ~size_hint:[] ~box:bx win in
  Evas_object_smart.callback_add bt Elm_sig.clicked unpack_cb;

  let add_cb _ =
    let btn = Elm_button.addx ~text:"I do nothing" ~size_hint:[] bx in
    let children = Elm_box.children_get bx in
    (match children with
    | [] -> Elm_box.pack_end bx btn
    | o :: _ -> Elm_box.pack_after bx btn o) in
  Evas_object_smart.callback_add bt_add Elm_sig.clicked add_cb;

  let clear_cb _ = Elm_box.clear bx in
  Evas_object_smart.callback_add bt_clear Elm_sig.clicked clear_cb;

  Elm_box.layout_set bx Evas_object.box_layout_horizontal (fun () -> ());
  test_box_transition_change bx transitions;

  Elm.run ();
  Elm.shutdown ()

