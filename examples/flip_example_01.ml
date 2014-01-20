open Efl

let interaction_of_int : int -> Elm_flip.interaction = function
  | 1 -> `page
  | 2 -> `cube
  | 3 -> `rotate
  | _ -> assert false

let change_interaction flip obj =
  let interaction = interaction_of_int (Elm_radio.state_value_get obj) in
  Elm_flip.interaction_set flip interaction;
  Elm_flip.go flip `rotate_xz_center_axis

let () =
  Elm.init ();
  Elm.policy_quit_set `last_window_closed;

  let win = Elm_win.util_standard_add "flip" "Flip" in
  Elm_win.autodel_set win true;

  let rect = Evas_object.rectangle_add (Evas_object.evas_get win) in
  Evas_object.resize rect 150 150;
  Evas_object.color_set rect 0 0 255 255;
  Evas_object.show rect;

  let rect2 = Evas_object.rectangle_add (Evas_object.evas_get win) in
  Evas_object.color_set rect2 0 255 0 255;
  Evas_object.show rect2;

  let flip = Elm_flip.add win in
  Elm_object.part_content_set flip ~p:"front" rect;
  Elm_object.part_content_set flip ~p:"back" rect2;
  Evas_object.resize flip 150 150;
  Evas_object.move flip 10 10;
  Evas_object.show flip;

  Elm_flip.interaction_set flip `page;
  let f d =
    Elm_flip.interaction_direction_enabled_set flip d true;
    Elm_flip.interaction_direction_hitsize_set flip d 1. in
  List.iter f [`up; `down; `left; `right];

  let add_radio label value group pos =
    let radio = Elm_radio.add win in
    Elm_object.text_set radio label;
    (match group with
    | None -> Elm_radio.value_set radio value
    | Some r1 -> Elm_radio.group_add radio r1);
    Elm_radio.state_value_set radio value;
    Evas_object.resize radio 55 30;
    Evas_object.move radio pos 160;
    Evas_object.show radio;
    Evas_object_smart.callback_add radio Elm_sig.changed
      (change_interaction flip);
    radio in
  let radio = add_radio "page" 1 None 10 in
  ignore (add_radio "cube" 2 (Some radio) 70 : Evas.obj);
  ignore (add_radio "rotate" 3 (Some radio) 140 : Evas.obj);

  Evas_object.resize win 200 200;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()

