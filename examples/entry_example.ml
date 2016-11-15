(* Differences from the original entry_example.c:
- We have one button "Change format" that show/hide explicityle the tags.
- Double-clicking sends the cursor to the end of line and triple-clicking does
nothing.
*)

open Printf
open Scanf
open Efl

let mapi f list =
  let rec aux i = function
    | [] -> []
    | x :: xs -> f i x :: aux (i + 1) xs in
  aux 0 list

let edit_buffer_insert e text =
  Elm_entry.entry_insert e text;
  Elm_object.focus_set e true

let default_size_hint ?(wy = Evas.hint_expand) o =
  Evas_object.size_hint_weight_set o Evas.hint_expand wy;
  Evas_object.size_hint_align_set o Evas.hint_fill Evas.hint_fill

let default_size_hint_h o = default_size_hint ~wy:0. o

let size_array = [|"size"; "absize"; "relsize"|]
let vsize_array = [|"full"; "ascent"|]

let accept_set = {Elm_entry.accepted = "0123456789"; rejected = ""}
let limit_size = {Elm_entry.max_char_count = 5; max_byte_count = 0}

let markup = ref true

let add_cancel_btn win inwin box = 
  let box2 = Elm_box.add win in
  Elm_box.horizontal_set box2 true;
  default_size_hint_h box2;
  Elm_box.pack_end box box2;
  Evas_object.show box2;
  let o = Elm_button.add win in
  Elm_object.text_set o "Cancel";
  default_size_hint o;
  Elm_box.pack_end box2 o;
  Evas_object.show o;
  let cancel_cb _ = Evas_object.del inwin in
  Elm_connect.Button.clicked o cancel_cb

let add_radio_box win box list q =
  let hbox = Elm_box.add win in
  Elm_box.horizontal_set hbox true;
  default_size_hint hbox;
  Elm_box.pack_end box hbox;
  Evas_object.show hbox;
  let aux i name =
    let r = Elm_radio.add win in
    Elm_object.text_set r name;
    Elm_radio.state_value_set r i;
    Elm_box.pack_end hbox r;
    Evas_object.show r;
    let changed_cb _ = q := Elm_radio.value_get r in
    Elm_connect.Radio.changed r changed_cb;
    r in
  match mapi aux list with
  | [] -> ()
  | r :: rs ->
    List.iter (fun r1 -> Elm_radio.group_add r1 r) rs;
    Elm_radio.value_set r !q

let add_dim_en win box name q =
  let f = Elm_frame.add win in
  Elm_object.text_set f name;
  default_size_hint_h f;
  Elm_box.pack_end box f;
  Evas_object.show f;
  let e = Elm_entry.add win in
  Elm_entry.single_line_set e true;
  Elm_entry.markup_filter_append e (Elm_entry.filter_accept_set accept_set);
  Elm_entry.markup_filter_append e (Elm_entry.filter_limit_size limit_size);
  Elm_object.text_set e (string_of_int !q);
  default_size_hint_h e;
  Elm_object.content_set f e;
  Evas_object.show e;
  let changed_cb _ =
    try q := int_of_string (Elm_object.text_get e) with _ -> () in
  Elm_connect.Entry.changed e changed_cb

let () =
  Elm.init ();
  
  let win = Elm_win.add "entry-example" `basic in
  Elm_win.title_set win "Emacs Lite";
  Evas_object.show win;

  let bg = Elm_bg.add win in
  Evas_object.size_hint_weight_set bg Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  let box = Elm_box.add win in
  Evas_object.size_hint_weight_set box Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win box;
  Evas_object.show box;

  let tb = Elm_box.add win in
  Elm_box.horizontal_set tb true;
  default_size_hint_h tb;
  Elm_box.pack_end box tb;
  Evas_object.show tb;

  let c = Elm_check.add win in
  Elm_check.state_set c false;
  Elm_object.text_set c "Autosave";
  Elm_box.pack_end tb c;
  Evas_object.show c;

  let bformat_changed = Elm_button.add win in
  Elm_object.text_set bformat_changed "Change format";
  Elm_box.pack_end tb bformat_changed;
  Evas_object.show bformat_changed;

  let image_insert_bt = Elm_button.add win in
  Elm_box.pack_end tb image_insert_bt;
  Evas_object.show image_insert_bt;

  let icon = Elm_layout.add win in
  let (_ : bool) =
    Elm_layout.theme_set icon "entry" "emoticon/haha" "default" in
  Elm_object.part_content_set image_insert_bt ~p:"icon" icon;

  let en = Elm_entry.add win in
  Elm_entry.autosave_set en false;
  let _ = Elm_entry.file_set en "/tmp/da_test.txt" `markup_utf8 in
  default_size_hint en;
  Elm_box.pack_end box en;
  Evas_object.show en;

  let format_changed_cb _ =
    let f s =
      if not !markup then Elm_entry.markup_to_utf8 s
      else Elm_entry.utf8_to_markup s in
    let cursor = Elm_entry.cursor_pos_get en in
    Elm_entry.cursor_begin_set en;
    Elm_entry.cursor_selection_begin en;
    Elm_entry.cursor_pos_set en cursor;
    Elm_entry.cursor_selection_end en;
    let s_prev =
      match Elm_entry.selection_get en with
      | Some s -> s | None -> assert false in
    let s = Elm_object.text_get en in
    Elm_entry.cursor_begin_set en;
    Elm_entry.entry_insert en (f s_prev);
    let new_cursor = Elm_entry.cursor_pos_get en in
    Elm_object.text_set en (f s);
    markup := not !markup;
    Elm_object.focus_set en true;
    Elm_entry.cursor_pos_set en new_cursor in
  Elm_connect.Button.clicked bformat_changed format_changed_cb;

  let autosave_change_cb obj =
    let state = Elm_check.state_get obj in
    Elm_entry.autosave_set en state;
    if state then Elm_entry.file_save en in
  Elm_connect.Check.changed c autosave_change_cb;

  let dblclick_cb _ =
    Elm_entry.cursor_line_end_set en;
    Elm_entry.select_none en in
  Elm_connect.Entry.clicked_double en dblclick_cb;

  let image_insert_cb _ =
    let width = ref 64 and height = ref 64 in
    let size = ref 1 and vsize = ref 1 in
    let remo = ref None in

    let inwin = Elm_inwin.add win in
    default_size_hint inwin;
    Evas_object.show inwin;

    let box = Elm_box.add win in
    default_size_hint box;
    Elm_inwin.content_set inwin box;
    Evas_object.show box;

    let naviframe = Elm_naviframe.add win in
    default_size_hint naviframe;
    Elm_box.pack_end box naviframe;
    Evas_object.show naviframe;

    let settings =
      let box = Elm_box.add win in
      default_size_hint box;
      box in

    let grid =
      let theme = match Elm_theme.list_item_path_get "default"with
      | None -> failwith ""
      | Some(t, _) -> t in
      let emos = Edje.file_collection_list theme in
      if emos = [] then failwith "";
      let grid = Elm_gengrid.add win in
      Elm_gengrid.item_size_set grid 64 80;
      default_size_hint grid;
      let iter_aux emo =
        try
          let name = sscanf emo "elm/entry/emoticon/%[^/]/default" (fun x -> x)
          in
          let label_get _ _ = name in
          let content_get obj part =
            if part <> "elm.swallow.icon" then None
            else (
              let o = Elm_layout.add obj in
              let (_ : bool) =
                Elm_layout.theme_set o "entry/emoticon" name "default" in
              Some o) in
          let del _ = () and state_get _ _ = true in
          let reusable_content_get obj part old = Some old in
          let it_class = {Elm_gengrid.item_style = "default";
            func_text_get = label_get; func_content_get = content_get;
            func_state_get = state_get; func_del = del;
            func_reusable_content_get = reusable_content_get} in
          let sel_cb obj _ =
            remo := Some name;
            Elm_naviframe.item_simple_promote naviframe settings in
          ignore (Elm_gengrid.item_append grid it_class sel_cb)
        with Scan_failure _ -> () in
      List.iter iter_aux emos;
      grid in
    let _ = Elm_naviframe.item_simple_push naviframe grid in

    let fill_settings () =
      let box = settings in

      let sizeopts = Elm_frame.add win in
      Elm_object.text_set sizeopts "Size";
      default_size_hint_h sizeopts;
      Elm_box.pack_end box sizeopts;
      Evas_object.show sizeopts;

      let box2 = Elm_box.add win in
      default_size_hint box2;
      Elm_object.content_set sizeopts box2;
      Evas_object.show box2;

      let size_list =
        ["Scale adjusted (size)"; "Absolute size (absize)";
          "Relative to line (relsize)"] in
      add_radio_box win box2 size_list size;
      
      let vsize_list =
        ["Full height (vsize=full)"; "Ascent only (vsize=ascent)"] in
      add_radio_box win box2 vsize_list vsize;

      add_dim_en win box2 "Width" width;
      add_dim_en win box2 "Height" height;

      let binsert = Elm_button.add win in
      Elm_object.text_set binsert "Insert";
      Elm_box.pack_end box binsert;
      Evas_object.show binsert;

      let btn_insert_cb _ =
        let emo = match !remo with Some x -> x | None -> assert false in
        let s = sprintf "<item %s=%dx%d vsize=%s href=emoticon/%s>"
          size_array.(!size) !width !height vsize_array.(!vsize) emo in
        let s1 = if not !markup then Elm_entry.utf8_to_markup s else s in
        edit_buffer_insert en s1;
        Evas_object.del inwin in
      Elm_connect.Button.clicked binsert btn_insert_cb in
    fill_settings ();
    let _ = Elm_naviframe.item_simple_push naviframe settings in

    Elm_naviframe.item_simple_promote naviframe grid;

    add_cancel_btn win inwin box in

  Elm_connect.Button.clicked image_insert_bt image_insert_cb;

  let win_del_cb obj = Evas_object.del obj; Elm.exit () in
  Elm_connect.Win.delete_request win win_del_cb;

  Elm_object.focus_set en true;

  Evas_object.resize win 300 780;

  Elm.run ();
  Elm.shutdown ()
