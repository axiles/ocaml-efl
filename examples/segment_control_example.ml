open Efl
module SC = Elm_segment_control
open Printf

let () =
  Elm.init ();
  Elm.policy_quit_set `last_window_closed;

  let win =
    Elm_win.util_standard_add "segment_control" "Segment Control Example" in
  Elm_win.autodel_set win true;

  let sc = SC.add win in
  Evas_object.size_hint_set sc [`expand];
  Elm_win.resize_object_add win sc;
  Evas_object.show sc;

  ignore (SC.item_add sc ~label:"only text" () : Elm_object.item);

  let add_ic_it ?label name =
    let ic = Elm_icon.add win in
    ignore (Elm_icon.standard_set ic name : bool);
    ignore (SC.item_add sc ~icon:ic ?label () : Elm_object.item) in
  add_ic_it "close";
  add_ic_it ~label:"Home" "home";
  add_ic_it ~label:"" "close";

  let count = SC.item_count_get sc in
  ignore (SC.item_insert_at sc ~label:"Inserted at" (count - 1) :
          Elm_object.item);

  let seg_it = SC.item_insert_at sc ~label:"To be deleted" 2 in
  Elm_object.item_del seg_it;

  ignore (SC.item_insert_at sc ~label:"to be deleted" 2 : Elm_object.item);
  SC.item_del_at sc 2;

  (match SC.item_get sc 0 with
  | Some it -> Elm_object.item_text_set it "Only Text"
  | None -> assert false);

  let count = SC.item_count_get sc in
  (match SC.item_get sc (count / 2) with
  | Some it -> SC.item_selected_set it true
  | None -> assert false);
  (match SC.item_selected_get sc with
  | Some it ->
     let idx = SC.item_index_get it in
     printf "Item selected: %d\n%!" idx
  | None -> assert false);

  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()
