open Efl
open Elm_sig

type item = Elm_object.item

let del_it data _ =
  match Elm_menu.first_item_get data with
  | None -> ()
  | Some menu_it ->
    match Elm_menu.item_next_get menu_it with
    | None -> ()
    | Some menu_it2 ->
        match Elm_menu.item_subitems_get menu_it2 with
        | [] -> ()
        | it :: _ -> Elm_object.item_del it

let show menu _ _ ev =
  Elm_menu.move menu ev.Evas.canvas_x ev.Evas.canvas_y;
  Evas_object.show menu

let () =
  Elm.init ();

  let win = Elm_win.add "menu" `basic in
  Elm_win.title_set win "Menu";
  Elm_win.autodel_set win true;
  Elm.policy_quit_set `last_window_closed;

  let bg = Elm_bg.add win in
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  let rect = Evas_object.rectangle_add (Evas_object.evas_get win) in
  Elm_win.resize_object_add win rect;
  Evas_object.color_set rect 0 0 0 0;
  Evas_object.show rect;

  let menu = Elm_menu.add win in
  let (_ : item) = Elm_menu.item_add menu ~label:"first item" () in
  let menu_it =
    Elm_menu.item_add menu ~icon:"mail-reply-all" ~label:"second item" () in
  let add = Elm_menu.item_add menu ~parent:menu_it in

  let (_ : item) = add ~icon:"object-rotate-left" ~label:"menu 1" () in
  let button = Elm_button.add win in
  Elm_object.text_set button "button - delete items";
  let menu_it1 = add () in
  Elm_object.item_content_set menu_it1 button;
  Evas_object_smart.callback_add button clicked (del_it menu);
  let (_ : item) = Elm_menu.item_separator_add menu menu_it in
  let (_ : item) = add ~label:"third item" () in
  let (_ : item) = add ~label:"fourth item"  () in
  let (_ : item) = add ~icon:"window-new" ~label:"sub menu" () in

  let menu_it = Elm_menu.item_add menu ~label:"third item" () in
  Elm_object.item_disabled_set menu_it true;

  Evas_object.event_callback_add_mouse_down rect (show menu);
  Evas_object.show menu;

  Evas_object.resize win 250 350;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()
