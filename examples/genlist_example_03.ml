(* Contrary to the original genlist_example_03, no information about pointers
is printed.

The index of the items is printed instead.*)

open Efl
open Printf

let n_items = 30

let string_of_weekday = function
  | 0 -> "Sun"
  | 1 -> "Mon"
  | 2 -> "Tue"
  | 3 -> "Wed"
  | 4 -> "Thu"
  | 5 -> "Fri"
  | 6 -> "Sat"
  | _ -> invalid_arg "string_of_weekday"

let string_of_month = function
  | 0 -> "Jan"
  | 1 -> "Feb"
  | 2 -> "Mar"
  | 3 -> "Apr"
  | 4 -> "May"
  | 5 -> "Jun"
  | 6 -> "Jul"
  | 7 -> "Aug"
  | 8 -> "Sep"
  | 9 -> "Oct"
  | 10 -> "Nov"
  | 11 -> "Dec"
  | _ -> invalid_arg "string_of_month"

let string_of_time t =
  let open Unix in
  sprintf "%s %s %d %d:%d:%d %d" (string_of_weekday t.tm_wday)
    (string_of_month t.tm_mon) t.tm_mday t.tm_hour t.tm_min t.tm_sec
    (t.tm_year + 1900)

let int_of_item item = Elm_genlist.item_index_get item - 1

let add_item list i =
  let item_label_get obj part =
    let t = Unix.localtime (Unix.time ()) in
    if part = "elm.text" then sprintf "Item # %d" i
    else sprintf "created at %s" (string_of_time t) in
  let item_content_get obj part =
    let ic = Elm_icon.add obj in
    if part = "elm.swallow.icon" then
      (let (_ : bool) = Elm_icon.standard_set ic "clock" in ());
    Evas_object.size_hint_aspect_set ic `vertical 1 1;
    Some ic in
  let item_sel_cb obj _ = printf "Item %d selected\n%!" i in
  let item_state_get obj _ = false in
  let item_del obj = () in
  let reusable_content_get obj part old = Some old in
  let itc = {Elm_genlist.item_style = "double_label";
    func_text_get = item_label_get;
    func_content_get = item_content_get;
    func_state_get = item_state_get;
    func_del = item_del;
    func_reusable_content_get = reusable_content_get} in
  Elm_genlist.item_append list itc None `none item_sel_cb

let genlist_add win box =
  let list = Elm_genlist.add win in
  Evas_object.size_hint_weight_set list Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set list Evas.hint_fill Evas.hint_fill;
  Elm_box.pack_end box list;
  Evas_object.show list;
  list

let genlist_fill list =
  for i = 0 to n_items - 1 do
    let (_ : Elm_object.item) = add_item list i in
    ()
  done

let add_and_fill win box m =
  let list = genlist_add win box in
  (match m with None -> () | Some m1 -> Elm_genlist.mode_set list m1);
  genlist_fill list

let () =
  Elm.init ();
  let win = Elm_win.add "icon" `basic in
  Elm_win.title_set win "Icon";
  Elm.policy_quit_set `last_window_closed;
  Elm_win.autodel_set win true;

  let bg = Elm_bg.add win in
  Evas_object.size_hint_weight_set bg Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  let box = Elm_box.add win in
  Elm_box.horizontal_set box true;
  Evas_object.size_hint_weight_set box Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set box Evas.hint_fill Evas.hint_fill;
  Elm_win.resize_object_add win box;
  Evas_object.show box;

  add_and_fill win box None;
  add_and_fill win box (Some `limit);
  add_and_fill win box (Some `compress);

  Evas_object.resize win 800 320;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()

