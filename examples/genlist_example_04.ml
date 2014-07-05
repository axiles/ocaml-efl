(* Contrary to the original genlist_example_04, no information about pointers
is printed.

The index of the items is printed instead.*)

open Efl
open Printf

let n_items = 300

let nitems = ref 0

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

let add_item_aux f_add list i parent =
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
  let itc = {Elm_genlist.item_style = "double_label";
    func_text_get = item_label_get;
    func_content_get = item_content_get;
    func_state_get = item_state_get;
    func_del = item_del} in
  f_add list itc parent `none item_sel_cb

let add_item = add_item_aux Elm_genlist.item_append

let add_group list i =
  let group_label_get obj part = sprintf "Group %d (item #%d)" (i / 7) i in
  let group_content_get obj part =
    let ic = Elm_icon.add obj in
    if part = "elm.swallow.icon" then
      (let (_ : bool) = Elm_icon.standard_set ic "home" in ());
    Evas_object.size_hint_aspect_set ic `vertical 1 1;
    Some ic in
  let group_sel_cb obj _ =
    printf "Group %d (item #%d) selected\n%!" (i / 7) i in
  let group_state_get obj _ = false in
  let group_del obj = () in
  let itc = {Elm_genlist.item_style = "group_index";
    func_text_get = group_label_get;
    func_content_get = group_content_get;
    func_state_get = group_state_get;
    func_del = group_del} in
  Elm_genlist.item_append list itc None `group group_sel_cb

let append_cb list obj =
  let (_ : Elm_object.item) = add_item list !nitems None in
  incr nitems

let prepend_cb list obj =
  let (_ : Elm_object.item) =
    add_item_aux Elm_genlist.item_prepend list !nitems None in
    incr nitems

let insert_aux_cb f_add list obj =
  match Elm_genlist.selected_item_get list with
  | None -> ()
  | Some glit ->
    let f_add1 list1 itc p t cb = f_add list1 itc p glit t cb in
    let (_ : Elm_object.item) = add_item_aux f_add1 list !nitems None in
    incr nitems

let insert_before_cb = insert_aux_cb Elm_genlist.item_insert_before
let insert_after_cb = insert_aux_cb Elm_genlist.item_insert_after

let next_or_prev_cb f list obj =
  let glit =
    match Elm_genlist.selected_item_get list with
    | None ->
      (match Elm_genlist.first_item_get list with
      | None -> assert false
      | Some x -> x)
    | Some x -> x in
  let glit1 =
    match f glit with
    | None -> glit
    | Some x -> x in
  Elm_genlist.item_selected_set glit1 true;
  Elm_genlist.item_show glit1 `_in

let next_cb = next_or_prev_cb Elm_genlist.item_next_get
let prev_cb = next_or_prev_cb Elm_genlist.item_prev_get

let realize_cb list obj =
  match Elm_genlist.selected_item_get list with
  | None -> ()
  | Some glit -> Elm_genlist.item_update glit

let bring_in_cb glit obj = Elm_genlist.item_bring_in glit `_in
let show_cb glit obj = Elm_genlist.item_show glit `_in
let middle_in_cb glit obj = Elm_genlist.item_bring_in glit `middle
let middle_show_cb glit obj = Elm_genlist.item_show glit `middle
let top_in_cb glit obj = Elm_genlist.item_bring_in glit `top
let top_show_cb glit obj = Elm_genlist.item_show glit `top

let button_add win box list label cb =
  let bt = Elm_button.add win in
  Elm_object.text_set bt label;
  Elm_box.pack_end box bt;
  Evas_object.show bt;
  (match cb with
  | None -> ()
  | Some cb1 ->
    Elm_connect.Button.clicked bt (cb1 list));
  bt
  
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
  Evas_object.size_hint_weight_set box Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set box Evas.hint_fill Evas.hint_fill;
  Elm_win.resize_object_add win box;
  Evas_object.show box;

  let list = Elm_genlist.add win in

  Evas_object.size_hint_weight_set list Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set list Evas.hint_fill Evas.hint_fill;
  Elm_box.pack_end box list;
  Evas_object.show list;

  let fbox = Elm_box.add win in
  Elm_box.layout_set fbox Evas_object.box_layout_flow_horizontal
    (fun () -> ());
  Evas_object.size_hint_weight_set fbox Evas.hint_expand 0.;
  Evas_object.size_hint_align_set fbox Evas.hint_fill Evas.hint_fill;
  Elm_box.pack_end box fbox;
  Evas_object.show fbox;

  let button_add1 (label, cb) =
    let (_ : Evas.obj) = button_add win fbox list label (Some cb) in
    () in
  let buttons = [
    ("prepend", prepend_cb); ("append", append_cb);
    ("insert before", insert_before_cb); ("insert after", insert_after_cb);
    ("prev", prev_cb); ("next", next_cb); ("realize", realize_cb)] in
  List.iter button_add1 buttons;
  let button_add2 label = button_add win fbox list label None in
  let bt_bring_in = button_add2 "bring #50" in
  let bt_show = button_add2 "show #50" in
  let bt_middle_in = button_add2 "bring to middle #200" in
  let bt_middle_show = button_add2 "show in middle #200" in
  let bt_top_in = button_add2 "bring to top #250" in
  let bt_top_show = button_add2 "show in top #250" in

  let glg = ref None in
  for i = 0 to n_items - 1 do
    let gli =
      if i mod 7 = 0 then (
        let item = add_group list !nitems in
        Elm_genlist.item_select_mode_set item `display_only;
        glg := Some item;
        item)
      else add_item list !nitems !glg in
    incr nitems;

    let add_cb bt cb = Elm_connect.Button.clicked bt (cb gli) in
    let add_cb2 bt1 cb1 bt2 cb2 = add_cb bt1 cb1; add_cb bt2 cb2 in
    match i with
    | 3 -> Elm_object.item_disabled_set gli true
    | 50 -> add_cb2 bt_bring_in bring_in_cb bt_show show_cb
    | 200 -> add_cb2 bt_middle_in middle_in_cb bt_middle_show middle_show_cb
    | 250 -> add_cb2 bt_top_in top_in_cb bt_top_show top_show_cb
    | _ -> ()
  done;

  Evas_object.resize win 420 320;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()

