(* Contrary to the original genlist_example_02, no information about pointers
is printed.

The index of the items is printed instead.*)

open Efl
open Printf

let n_items = 300

let string_of_mode (m : Elm_list.mode) =
  match m with
  | `compress -> "compress"
  | `scroll -> "scroll"
  | `limit -> "limit"
  | `expand -> "expand"
  | `last -> "last"

let string_of_policy (p : Elm_scroller.policy) =
  match p with
  | `auto -> "auto"
  | `on -> "on"
  | `off -> "off"

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

let add_item list i =
  let item_label_get obj part =
    let t = Unix.localtime (Unix.time ()) in
    if i mod 2 <> 0 then
      sprintf "Very long item # %d - realized at %s" i (string_of_time t)
    else sprintf "short item %d" i in
  let item_content_get obj part =
    let ic = Elm_icon.add obj in
    if part = "elm.swallow.icon" then
      (let (_ : bool) = Elm_icon.standard_set ic "clock" in ());
    Evas_object.size_hint_aspect_set ic `vertical 1 1;
    Some ic in
  let item_state_get obj part = false in
  let item_del obj = () in
  let item_sel_cb obj _ = printf "Selected item %d\n%!" i in
  let itc = {Elm_genlist.item_style = "default";
    func_text_get = item_label_get;
    func_content_get = item_content_get;
    func_state_get = item_state_get;
    func_del = item_del} in
  Elm_genlist.item_append list itc None `none item_sel_cb

let show_status_cb list obj =
  let int_of_item item = Elm_genlist.item_index_get item - 1 in
  let aux item = printf "%d " (int_of_item item) in
  (match Elm_genlist.selected_item_get list with
  | None -> printf "\nNo items selected\n"
  | Some glit ->
    printf "\nfirst selected item: %d\n" (int_of_item glit);
    let selected = Elm_genlist.selected_items_get list in
    printf "all selected items (%d): " (List.length selected);
    List.iter aux selected;
    printf "\n");
  let realized = Elm_genlist.realized_items_get list in
  printf "realized items (%d): " (List.length realized);
  List.iter aux realized;
  printf "\n";
  printf "genlist mode: %b\n" (Elm_genlist.decorate_mode_get list);
  (match Elm_genlist.decorated_item_get list with
  | None -> printf "mode item: none\n"
  | Some item -> printf "mode item: %d\n" (int_of_item item));
  let x, y, w, h = Evas_object.geometry_get list in
  let mx = w / 2 + x and my = h / 2 + y in
  (match Elm_genlist.at_xy_item_get list mx my with
  | None -> printf "There are no items in the middle of the screen\n%!"
  | Some(item, _) ->
    printf "Item %d is in the middle of the screen\n%!" (int_of_item item))

let realize_cb list obj = Elm_genlist.realized_items_update list

let () =
  Elm.init ();
  let win = Elm_win.add "genlist" `basic in
  Elm_win.title_set win "Genlist - simple";
  Elm.policy_quit_set `last_window_closed;
  Elm_win.autodel_set win true;

  let bg = Elm_bg.add win in
  Evas_object.size_hint_weight_set bg Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  let box = Elm_box.add win in
  Evas_object.size_hint_weight_set box Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set box Evas.hint_fill Evas.hint_fill;
  Elm_win.resize_object_add win box;
  Evas_object.show box;

  let list = Elm_genlist.add win in
  let sel_mode = Elm_genlist.select_mode_get list in
  let always =  sel_mode = `always in
  let no_sel = sel_mode = `none in

  printf "default values:\n";
  printf "always select: %b\n" always;
  let hbounce, vbounce = Elm_scroller.bounce_get list in
  printf "bounce - horizontal %b, vertical: %b\n" hbounce vbounce;
  printf "homogeneous: %b\n" (Elm_genlist.homogeneous_get list);
  printf "horizontal mode: %s\n" (string_of_mode (Elm_genlist.mode_get list));
  printf "longpress timeout: %0.3f\n" (Elm_genlist.longpress_timeout_get list);
  printf "multi selection: %b\n" (Elm_genlist.multi_select_get list);
  printf "no selection mode: %b\n" no_sel;
  let hp, vp = Elm_scroller.policy_get list in
  printf "scroller policy - horizontal: %s, vertical: %s\n"
    (string_of_policy hp) (string_of_policy vp);
  printf "block count: %d\n" (Elm_genlist.block_count_get list);
  printf "%!";

  Elm_scroller.bounce_set list false false;
  Elm_genlist.homogeneous_set list false;
  Elm_genlist.mode_set list `limit;
  Elm_genlist.multi_select_set list true;
  Elm_genlist.select_mode_set list `default;
  Elm_scroller.policy_set list `off `on;
  Elm_genlist.longpress_timeout_set list 0.5;
  Elm_genlist.block_count_set list 16;

  for i = 0 to n_items - 1 do
    let (_ : Elm_object.item) = add_item list i in
    ()
  done;

  Evas_object.size_hint_weight_set list Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set list Evas.hint_fill Evas.hint_fill;
  Elm_box.pack_end box list;
  Evas_object.show list;

  let hbox = Elm_box.add win in
  Elm_box.horizontal_set hbox true;
  Evas_object.size_hint_weight_set hbox Evas.hint_expand 0.;
  Evas_object.size_hint_align_set hbox Evas.hint_fill Evas.hint_fill;
  Elm_box.pack_end box hbox;
  Evas_object.show hbox;

  let btn = Elm_button.add win in
  Elm_object.text_set btn "Show status";
  Evas_object.size_hint_weight_set btn 0. 0.;
  Evas_object.size_hint_align_set btn 0.5 0.5;
  Evas_object_smart.callback_add btn Elm_button.E.clicked (show_status_cb list);
  Elm_box.pack_end hbox btn;
  Evas_object.show btn;

  let btn = Elm_button.add win in
  Elm_object.text_set btn "Realize";
  Evas_object.size_hint_weight_set btn 0. 0.;
  Evas_object.size_hint_align_set btn 0.5 0.5;
  Evas_object_smart.callback_add btn Elm_button.E.clicked (realize_cb list);
  Elm_box.pack_end hbox btn;
  Evas_object.show btn;

  Evas_object.resize win 200 320;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()

