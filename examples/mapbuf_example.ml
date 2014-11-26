open Efl

let param_cb f mb obj = f mb (Elm_check.state_get obj)
let enabled_cb = param_cb Elm_mapbuf.enabled_set
let alpha_cb = param_cb Elm_mapbuf.alpha_set
let smooth_cb = param_cb Elm_mapbuf.smooth_set

let () =
  Elm.init ();
  Elm.policy_quit_set `last_window_closed;

  let win = Elm_win.util_standard_add "mapbuf" "Mapbuf Example" in
  Elm_win.autodel_set win true;

  let bx = Elm_box.add win in
  Evas_object.size_hint_set bx [`expand];
  Elm_win.resize_object_add win bx;
  Evas_object.show bx;

  let mb = Elm_mapbuf.add win in
  Evas_object.size_hint_set mb [`expand; `fill];
  Elm_box.pack_end bx mb;

  let tb = Elm_table.add win in
  Evas_object.size_hint_set tb [`expand; `fill];
  Evas_object.show tb;

  for i = 0 to 7 do
    for j = 0 to 7 do
      let ic = Elm_icon.add win in
      ignore (Elm_icon.standard_set ic "home" : bool);
      Elm_image.resizable_set ic false false;
      Evas_object.show ic;
      Elm_table.pack tb ic i j 1 1;
    done;
  done;

  Elm_object.content_set mb tb;
  Evas_object.show mb;

  let hbx = Elm_box.add win in
  Elm_box.horizontal_set hbx true;
  Evas_object.size_hint_set hbx [`expand; `fill];
  Elm_box.pack_end bx hbx;
  Evas_object.show hbx;

  let add_check text ?state cb =
    let ck = Elm_check.add win in
    Elm_object.text_set ck text;
    (match state with Some s -> Elm_check.state_set ck s | None -> ());
    Elm_connect.Check.changed ck (cb mb);
    Elm_box.pack_end hbx ck;
    Evas_object.show ck;
    ck in

  let tg = add_check "Map" enabled_cb in
  ignore (Elm_object.style_set tg "toggle" : bool);
  Elm_object.part_text_set tg ~p:"on" "Enabled";
  Elm_object.part_text_set tg ~p:"off" "Disabled";

  ignore (add_check "Alpha" ~state:true alpha_cb : Evas.obj);
  ignore (add_check "Smooth" ~state:true smooth_cb : Evas.obj);

  Evas_object.resize win 240 320;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()

