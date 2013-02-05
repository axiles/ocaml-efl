open Efl
open Elm_win.E
open Elm_button.E
open Format

let on_done _ = Elm.exit ()

let counter = ref 3

let incr_cb (f_add : 'a) with_icon with_sel with_content li _ =
  let (_ : 'a) = Elm_list.item_append in
  let n = !counter in
  let label = sprintf "Item %d" n in
  incr counter;
  let icon =
    if with_icon then (
      let ic = Elm_icon.add li in
      let (_ : bool) = Elm_icon.standard_set ic "home" in
      Elm_image.resizable_set ic false false;
      Some ic)
    else None in
  let content =
    if with_content then Some (sprintf "Item content %d" n) else None in
  let func = 
    if with_sel then
      let cb _ _ =
        match content with
        | Some s -> printf "Selected label: %s with content %s\n%!" label s
        | None -> printf "Selected label: %s" label in
      Some cb
    else None in      
  try
    let (_ : Elm_object.item) = f_add li ~label ?icon ?func () in ()
  with _ -> print_endline "Error adding Item"

let prepend_cb = incr_cb Elm_list.item_prepend false false false
let add_cb_aux = incr_cb Elm_list.item_append
let add_cb = add_cb_aux false false false
let add_ic_cb = add_cb_aux true false false
let add_func_cb = add_cb_aux false true false
let add_data_cb = add_cb_aux false true true


let action_cb f li _ =
  match Elm_list.selected_item_get li with Some i -> f i | None -> ()
let action_cb_bool f b = action_cb (fun i -> f i b)

let del_cb = action_cb Elm_object.item_del
let unselect_cb = action_cb_bool Elm_list.item_selected_set false

let print_cb li _ =
  let aux x = printf "%s\n" (Elm_object.item_text_get x) in
  List.iter aux (Elm_list.items_get li);
  printf "%!"

let clear_cb li _ = Elm_list.clear li

let select_pos_cb f li _ =
  match Elm_list.selected_item_get li with
  | None -> ()
  | Some i1 ->
    match f i1 with
    | Some i2 -> Elm_list.item_selected_set i2 true
    | None -> ()

let select_next_cb = select_pos_cb Elm_list.item_next

let insert_after_cb li obj =
  match Elm_list.selected_item_get li with
  | None -> ()
  | Some i ->
    let f_add li1 = Elm_list.item_insert_after li1 i in
    incr_cb f_add false false false li obj

let select_prev_cb = select_pos_cb Elm_list.item_prev

let insert_before_cb li obj =
  match Elm_list.selected_item_get li with
  | None -> ()
  | Some i ->
    let f_add li1 = Elm_list.item_insert_before li1 i in
    incr_cb f_add false false false li obj

let set_separator_cb = action_cb_bool Elm_list.item_separator_set true
let disable_cb = action_cb_bool Elm_object.item_disabled_set true

let add_button win li bx label cb =
  let bt = Elm_button.add win in
  Elm_object.text_set bt label;
  Evas_object_smart.callback_add_safe bt clicked (cb li);
  Elm_box.pack_end bx bt;
  Evas_object.size_hint_weight_set bt Evas.hint_expand 0.;
  Evas_object.size_hint_align_set bt Evas.hint_fill 0.;
  Evas_object.show bt

let add_hbox win bx li list =
  let hbx = Elm_box.add win in
  Elm_box.horizontal_set hbx true;
  Evas_object.size_hint_weight_set hbx Evas.hint_expand 0.;
  Evas_object.size_hint_align_set hbx Evas.hint_fill 0.;
  Elm_box.pack_end bx hbx;
  Evas_object.show hbx;
  List.iter (fun (label, cb) -> add_button win li hbx label cb) list

let () =
  Elm.init Sys.argv;

  let win = Elm_win.add "list" `basic in
  Elm_win.title_set win "List Items Example";
  Evas_object_smart.callback_add_safe win delete_request on_done;

  let bg = Elm_bg.add win in
  Elm_win.resize_object_add win bg;
  Evas_object.size_hint_weight_set bg Evas.hint_expand Evas.hint_expand;
  Evas_object.show bg;

  let bx = Elm_box.add win in
  Evas_object.size_hint_weight_set bx Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win bx;
  Evas_object.show bx;

  let li = Elm_list.add win in
  Evas_object.size_hint_weight_set li Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set li Evas.hint_fill Evas.hint_fill;
  Elm_box.pack_end bx li;

  let first_items = ["Item 0"; "Item 1"; "Item 2"] in
  let first_items_aux label =
    let (_ : Elm_object.item) = Elm_list.item_append li ~label () in () in
  List.iter first_items_aux first_items;

  let list_bts = [
    [("Prepend item", prepend_cb); ("Append item", add_cb)];
    [
      ("Append with icon", add_ic_cb);
      ("Append with selected function", add_func_cb);
      ("Append with data", add_data_cb)];
    [
      ("Delete item", del_cb);
      ("Unselect item", unselect_cb);
      ("Print items", print_cb);
      ("Clear", clear_cb)];
    [
      ("Select next item", select_next_cb);
      ("Insert after item", insert_after_cb);
      ("Select previous item", select_prev_cb);
      ("Insert before item", insert_before_cb)];
    [("Set as separator", set_separator_cb); ("Disable item", disable_cb)]] in
  List.iter (add_hbox win bx li) list_bts;

  Elm_list.go li;
  Evas_object.show li;

  Evas_object.resize win 320 600;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()
