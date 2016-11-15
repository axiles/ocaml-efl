(* WARNING: this example is still under developpment *)

open Efl
open Printf

let n_items = 6

type node_data = {
  mutable children : node_data list;
  value : int;
  level : int;
  mutable favorite : bool}

let ht = Hashtbl.create (n_items * 4)

let nitems = ref 0

let reusable_content_get obj part old = Some old

let add_item list d parent =
  let item_label_get obj part =
    if part = "elm.text" then
      (if d.favorite then sprintf "Favorite # %d" d.value
      else sprintf "Item # %d (level %d)" d.value d.level)
    else "" in
  let item_content_get obj part =
    let ic = Elm_icon.add obj in
    let ic_name = if d.favorite then "apps" else "file" in
    if part = "elm.swallow.icon" then
      (let (_ : bool) = Elm_icon.standard_set ic ic_name in ());
    Evas_object.size_hint_aspect_set ic `vertical 1 1;
    Some ic in
  let itc = {Elm_genlist.item_style = "default";
    func_text_get = item_label_get;
    func_content_get = item_content_get;
    func_state_get = (fun obj part -> false);
    func_del = (fun obj -> ());
    func_reusable_content_get = reusable_content_get} in
  let item_sel_cb obj _ =
    printf "Item # %d (level %d) selected\n%!" d.value d.level in
  let it = Elm_genlist.item_append list itc parent `none item_sel_cb in
  Hashtbl.add ht it d;
  it

let add_parent list d =
  let parent_label_get obj part =
    sprintf "Group %d (%d items)" (d.value / 7) (List.length d.children) in
  let parent_content_get obj part =
    let ic = Elm_icon.add obj in
    if part = "elm.swallow.icon" then
      (let (_ : bool) = Elm_icon.standard_set ic "folder" in ());
    Evas_object.size_hint_aspect_set ic `vertical 1 1;
    Some ic in
  let itp = {Elm_genlist.item_style = "default";
    func_text_get = parent_label_get;
    func_content_get = parent_content_get;
    func_state_get = (fun obj part -> false);
    func_del = (fun obj -> ());
    func_reusable_content_get = reusable_content_get} in
  let parent_sel_cb obj part =
    printf "Group %d (%d items)\n%!" (d.value / 7) (List.length d.children) in
  let it = Elm_genlist.item_append list itp None `tree parent_sel_cb in
  Hashtbl.add ht it d;
  it

let append_cb list obj =
  match Elm_genlist.selected_item_get list with
  | None -> ()
  | Some glit ->
     let parent = Elm_genlist.item_parent_get glit in
     let d = match parent with
     | None -> {children = []; value = !nitems; level = 0; favorite = false}
     | Some p ->
       let level = Elm_genlist.item_expanded_depth_get p + 1 in
       let pdata = try Hashtbl.find ht p with Not_found -> assert false in
       let d = {children = []; value = !nitems; level; favorite = false} in
       pdata.children <- d :: pdata.children;
       d in
     incr nitems;
     let (_ : Elm_object.item) = add_item list d parent in
     ()

let favorite_cb list obj =
  match Elm_genlist.selected_item_get list with
  | None -> ()
  | Some glit ->
    let d = try Hashtbl.find ht glit with Not_found -> assert false in
    d.favorite <- not d.favorite;
    Elm_genlist.item_update glit

let button_add win box list label cb =
  let bt = Elm_button.add win in
  Elm_object.text_set bt label;
  Elm_box.pack_end box bt;
  Evas_object.show bt;
  Elm_connect.Button.clicked bt (cb list)

let () =
  Elm.init ();
  let win = Elm_win.add "icon" `basic in
  Elm_win.title_set win "Icon";
  Elm.policy_quit_set `last_window_closed;
  Elm_win.autodel_set win true;

  let bg = Elm_bg.add win in
  Evas_object.size_hint_weight_set bg Evas.hint_expand Evas.hint_fill;
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
  Elm_box.layout_set fbox Evas_object.box_layout_flow_horizontal (fun () -> ());
  Evas_object.size_hint_weight_set fbox Evas.hint_expand 0.;
  Evas_object.size_hint_weight_set fbox Evas.hint_fill Evas.hint_fill;
  Elm_box.pack_end box fbox;
  Evas_object.show fbox;

  (* TODO: Add buttons *)
  button_add win fbox list "append item" append_cb;
  button_add win fbox list "favorite" favorite_cb;

  let glg = ref None in
  let pdata = ref None in
  for i = 0 to n_items - 1 do
    incr nitems;
    printf "Creating item: #%d\n%!" i;
    if i mod 3 = 0 then (
      let data = {children = []; value = i; level = 0; favorite = false} in
      let gli = add_parent list data in
      Elm_genlist.item_expanded_set gli true;
      glg := Some gli;
      pdata := Some data
    ) else (
      let data = {children = []; value = i; level = 1; favorite = false} in
      let (_ : Elm_object.item) = add_item list data !glg in
      (match !pdata with
      | None -> assert false
      | Some pd -> pd.children <- data :: pd.children))
  done;

  (* TODO: Add callbacks *)

  Evas_object.resize win 420 600;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()

