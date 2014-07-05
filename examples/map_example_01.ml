open Efl

let bt_zoom delta map obj =
  Elm_map.zoom_mode_set map `manual;
  let zoom = Elm_map.zoom_get map in
  Elm_map.zoom_set map (zoom + delta)

let bt_zoom_in = bt_zoom 1 and bt_zoom_out = bt_zoom (-1)

let bt_zoom_fit map obj = Elm_map.zoom_mode_set map `auto_fit
let bt_zoom_fill map obj = Elm_map.zoom_mode_set  map `auto_fill

let nasty_hack o () =
  Evas.smart_objects_calculate (Evas_object.evas_get o); false

let () =
  Elm.init ();
  Elm.policy_quit_set `last_window_closed;

  let win = Elm_win.util_standard_add "map" "Map Creation Example" in
  Elm_win.autodel_set win true;

  let map = Elm_map.add win in
  Evas_object.size_hint_set map [`expand];
  Elm_win.resize_object_add win map;
  Evas_object.show map;

  let box = Elm_box.add win in
  Evas_object.show box;

  let add_bt label cb =
    let bt = Elm_button.add win in
    Elm_object.text_set bt label;
    Elm_box.pack_end box bt;
    Evas_object.show bt;
    Elm_connect.Button.clicked bt (cb map) in
  add_bt "+" bt_zoom_in;
  add_bt "-" bt_zoom_out;
  add_bt "X" bt_zoom_fit;
  add_bt "#" bt_zoom_fill;

  Elm_map.zoom_set map 12;
  Elm_map.region_show map (-43.2) (-22.9);
  Evas_object.resize win 512 512;
  Evas_object.show win;

  ignore (Ecore_timer.add 0.5 (nasty_hack win) : Ecore.timer);

  Elm.run ();
  Elm.shutdown ()

