open Efl
open Printf

let ref_list_mouse_down = ref 0

let dismissed_cb obj = Evas_object.del obj

let ctxpopup_item_cb obj event_info =
  let it = Elm_object.item_of_ptr event_info in
  printf "ctxpopup item selected: %s\n%!" (Elm_object.item_text_get it)

let item_new ctxpopup label icon =
  let ic = Elm_icon.add ctxpopup in
  ignore (Elm_icon.standard_set ic icon);
  Elm_image.resizable_set ic false false;
  Elm_ctxpopup.item_append ctxpopup ?label ~icon:ic ~func:ctxpopup_item_cb ()

let list_item_cb obj event_info =
  if !ref_list_mouse_down > 0 then ()
  else (
    let ctxpopup = Elm_ctxpopup.add obj in
    Evas_object_smart.callback_add ctxpopup Elm_sig.dismissed dismissed_cb;

    let item_new1 label icon =
      ignore (item_new ctxpopup (Some label) icon : Elm_object.item) in
    item_new1 "Go to home folder" "home";
    item_new1 "Save file" "file";
    item_new1 "Delete file" "delete";
    let it = item_new ctxpopup (Some "Navigate to folder") "folder" in
    Elm_object.item_disabled_set it true;
    item_new1 "Edit entry" "edit";
    let it = item_new ctxpopup (Some "Set date and time") "clock" in
    Elm_object.item_disabled_set it true;

    let x, y = Evas.pointer_canvas_xy_get (Evas_object.evas_get obj) in
    Evas_object.move ctxpopup x y;
    Evas_object.show ctxpopup;
    
    let it = Elm_object.item_of_ptr event_info in
    Elm_list.item_selected_set it false
  )

let list_item_cb2 obj event_info =
  if !ref_list_mouse_down > 0 then ()
  else (
    let ctxpopup = Elm_ctxpopup.add obj in
    Evas_object_smart.callback_add ctxpopup Elm_sig.dismissed dismissed_cb;
    Elm_ctxpopup.horizontal_set ctxpopup true;

    let item_new1 icon =
      ignore (item_new ctxpopup None icon : Elm_object.item) in
    List.iter item_new1 ["home"; "file"; "delete"; "folder"];
    let it = item_new ctxpopup None "edit" in
    Elm_object.item_disabled_set it true;
    item_new1 "clock";

    let x, y = Evas.pointer_canvas_xy_get (Evas_object.evas_get obj) in
    Evas_object.move ctxpopup x y;
    Evas_object.show ctxpopup;
    
    let it = Elm_object.item_of_ptr event_info in
    Elm_list.item_selected_set it false
  ) 

let list_mouse_down e obj info = incr ref_list_mouse_down

let list_mouse_up e obj info = decr ref_list_mouse_down

let win_del obj = ref_list_mouse_down := 0

let () =
  Elm.init ();
  Elm.policy_quit_set `last_window_closed;

  let win = Elm_win.util_standard_add "Contextual popup" "Contextual popup" in
  Evas_object_smart.callback_add win Elm_sig.delete_request win_del;
  Elm_win.autodel_set win true;
  Evas_object.resize win 400 400;
  Evas_object.show win;

  let list = Elm_list.add win in
  Evas_object.event_callback_add_mouse_down list list_mouse_down;
  Evas_object.event_callback_add_mouse_up list list_mouse_up;
  Evas_object.size_hint_set list [`expand];
  Elm_win.resize_object_add win list;

  let add_item label func =
    ignore (Elm_list.item_append list ~label ~func () : Elm_object.item) in
  add_item "Ctxpopup with icons and labels" list_item_cb;
  add_item "Ctxpopup with icons only" list_item_cb2;
  Evas_object.show list;
  Elm_list.go list;

  Elm.run ();
  Elm.shutdown ()




