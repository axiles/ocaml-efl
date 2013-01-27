open Efl
open Format

let () =
  Elm.init Sys.argv;

  let win = Elm_win.add "icon" `basic; in
  Elm_win.title_set win "Icon";
  let (_ : bool) = Elm.policy_set `quit `last_window_closed in
  Elm_win.autodel_set win true;

  let bg = Elm_bg.add win in
  Elm_bg.color_set bg 255 255 255;
  Evas_object.size_hint_weight_set bg Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  let icon = Elm_icon.add win in
  Elm_icon.order_lookup_set icon `theme_fdo;
  let (_ : bool) = Elm_icon.standard_set icon "home" in
  let path, group = match Elm_image.file_get icon with
  | p, Some g -> (p, g)
  | _, None -> assert false in
  let name = match Elm_icon.standard_get icon with
  | Some n -> n
  | None -> assert false in
  printf "path = %s, group = %s, name = %s\n%!" path group name;

  Elm_image.no_scale_set icon true;
  Elm_image.resizable_set icon false true;
  Elm_image.smooth_set icon false;
  Elm_image.fill_outside_set icon true;

  Evas_object.size_hint_weight_set icon Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win icon;
  Evas_object.show icon;

  Evas_object.resize win 320 320;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()
