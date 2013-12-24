open Efl
open Format

let table = "example/table"
let box = "example/box"
let title = "example/title"
let swallow = "example/custom"

let images = [| "home"; "close"; "arrow_up"; "arrow_down"|]

let mymodulo a b =
  if a >= 0 then a mod b
  else (a mod b) + b

let signal_cb current o emission source =
  let icon = Elm_object.part_content_get o ~p:"elm.swallow.content" () in
  print_endline "signal received";
  let x =
    if "elm,action,back" = emission then !current - 1 else
    if "elm,action,next" = emission then !current + 1
    else !current in
  current := mymodulo x (Array.length images);
  let (_ : bool) = Elm_icon.standard_set icon images.(!current) in
  ()

let () =
  Elm.init Sys.argv;

  let current = ref 0 in

  let win = Elm_win.add "layout" `basic in
  Elm_win.title_set win "Layout";
  Elm.policy_set `quit `last_window_closed;
  Elm_win.autodel_set win true;

  let bg = Elm_bg.add win in
  Elm_bg.color_set bg 255 255 255;
  Evas_object.size_hint_weight_set bg Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  let layout = Elm_layout.add win in
  Evas_object.size_hint_weight_set layout Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win layout;
  let (_ : bool) =
    Elm_layout.theme_set layout "layout" "application" "content-back-next" in
  Evas_object.show layout;

  let icon = Elm_icon.add win in
  let (_ : bool) = Elm_icon.standard_set icon images.(!current) in
  Evas_object.size_hint_weight_set layout Evas.hint_expand Evas.hint_expand;
  Elm_object.part_content_set layout ~p:"elm.swallow.content" icon;

  let add_callback s =
    Elm_layout.signal_callback_add layout s "" (signal_cb current) in
  List.iter add_callback ["elm,action,back"; "elm,action,next"];

  Evas_object.resize win 320 320;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()
