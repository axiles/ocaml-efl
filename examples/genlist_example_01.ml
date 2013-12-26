(* Contrary to the original genlist_example_01, no information about pointers
is printed*)

open Efl
open Printf

let n_items = 30

let add_item win list i =
  let label_get obj part = sprintf "Item # %d" i in
  let content_get obj part =
    let ic = Elm_icon.add obj in
    if part = "elm.swallow.icon" then (
      let (_ : bool) = Elm_icon.standard_set ic "clock" in
      ());
    Evas_object.size_hint_aspect_set ic `vertical 1 1;
    Some ic in
  let sel_cb obj item = printf "Item %d selected\n%!" i in
  let state_get obj part = false in
  let del_cb obj = () in
  let itc = {
    Elm_genlist.item_style = "default";
    func_text_get = label_get;
    func_content_get = content_get;
    func_state_get = state_get;
    func_del = del_cb} in
  let (_ : Elm_object.item) =
    Elm_genlist.item_append list itc None `none sel_cb in
  ()

let () =
  Elm.init Sys.argv;
  let win = Elm_win.add "icon" `basic in
  Elm_win.title_set win "Icon";
  Elm.policy_set `quit `last_window_closed;
  Elm_win.autodel_set win true;

  let bg = Elm_bg.add win in
  Elm_bg.color_set bg 255 255 255;
  Evas_object.size_hint_weight_set bg Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  let list = Elm_genlist.add win in
  for i = 0 to n_items - 1 do
    add_item win list i
  done;

  Evas_object.size_hint_weight_set list Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win list;
  Evas_object.show list;

  Evas_object.resize win 320 320;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()

