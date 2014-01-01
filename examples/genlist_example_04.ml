(* WARNING: this example is still under construction *)

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

let button_add win box list label cb =
  let bt = Elm_button.add win in
  Elm_object.text_set bt label;
  Elm_box.pack_end box bt;
  Evas_object.show bt;
  (match cb with
  | None -> ()
  | Some cb1 ->
    Evas_object_smart.callback_add bt Elm_button.E.clicked (cb1 list));
  bt
  
let () =
  Elm.init Sys.argv;
  let win = Elm_win.add "icon" `basic in
  Elm_win.title_set win "Icon";
  Elm.policy_set `quit `last_window_closed;
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
  (* TODO: layout_set *)
  Evas_object.size_hint_weight_set fbox Evas.hint_expand 0.;
  Evas_object.size_hint_align_set fbox Evas.hint_fill Evas.hint_fill;
  Elm_box.pack_end box fbox;
  Evas_object.show fbox;

  (* TODO: add buttons *)
  let (_ : Evas.obj) = button_add win fbox list "prepend" (Some prepend_cb) in
  let (_ : Evas.obj) = button_add win fbox list "append" (Some append_cb) in
  let (_ : Evas.obj) =
    button_add win fbox list "insert after" (Some insert_after_cb) in
  let (_ : Evas.obj) =
    button_add win fbox list "insert before" (Some insert_before_cb) in

  let glg = ref None in
  for i = 0 to n_items - 1 do
    let (_ : Elm_object.item) =
      if i mod 7 = 0 then (
        let item = add_group list !nitems in
        glg := Some item;
        item)
      else add_item list !nitems !glg in
    incr nitems;

    (* TODO: Other things on items *)
  done;

  Evas_object.resize win 420 320;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()

