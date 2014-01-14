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

  let bigbox = Elm_box.add win in
  Evas_object.size_hint_set bigbox [`expand];
  Elm_win.resize_object_add win bigbox;
  Evas_object.show bigbox;

  let bx = Elm_box.add win in
  Elm_box.horizontal_set bx true;
  Elm_box.pack_end bigbox bx;
  Evas_object.show bx;

  let bt_add = Elm_button.add win in
  Elm_object.text_set bt_add "Add";
  Elm_box.pack_end bx bt_add;
  Evas_object.show bt_add;

  let bt_clear = Elm_button.add win in
  Elm_object.text_set bt_clear "Clear";
  Elm_box.pack_end bx bt_clear;
  Evas_object.show bt_clear;

  let bx = Elm_box.add win in
  Evas_object.size_hint_set bx [`expand; `fill];
  Elm_box.pack_end bigbox bx;
  Evas_object.show bx;

  let unpack_cb obj =
    Elm_box.unpack bx obj;
    Evas_object.move obj 0 50;
    Evas_object.color_set obj 128 64 0 128 in

  let bt = Elm_button.add win in
  Elm_object.text_set bt "Button 1";
  Evas_object_smart.callback_add bt Elm_button.E.clicked unpack_cb;
  Evas_object.size_hint_set bt [`expand; `fill];
  Elm_box.pack_end bx bt;
  Evas_object.show bt;

  let bt = Elm_button.add win in
  Elm_object.text_set bt "Button 2";
  Evas_object_smart.callback_add bt Elm_button.E.clicked unpack_cb;
  Evas_object.size_hint_set bt [`hexpand; `valign 1.];
  Elm_box.pack_end bx bt;
  Evas_object.show bt;

  let bt = Elm_button.add win in
  Elm_object.text_set bt "Button 3";
  Evas_object_smart.callback_add bt Elm_button.E.clicked unpack_cb;
  Elm_box.pack_end bx bt;
  Evas_object.show bt;

  let add_cb _ =
    let btn = Elm_button.add bx in
    Elm_object.text_set btn "I do nothing";
    let children = Elm_box.children_get bx in
    (match children with
    | [] -> Elm_box.pack_end bx btn
    | o :: _ -> Elm_box.pack_after bx btn o);
    Evas_object.show btn in
  Evas_object_smart.callback_add bt_add Elm_button.E.clicked add_cb;

  let clear_cb _ = Elm_box.clear bx in
  Evas_object_smart.callback_add bt_clear Elm_button.E.clicked clear_cb;

  Elm_box.layout_set bx Evas_object.box_layout_horizontal (fun () -> ());
  test_box_transition_change bx transitions;

  Elm.run ();
  Elm.shutdown ()

