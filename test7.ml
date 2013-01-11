(* WARNING: This example is still in heavy development *)

open Printf
open Scanf

let edit_buffer_insert e text =
  Elm_entry.entry_insert e text;
  Elm_object.focus_set e true

let size_array = [|"size"; "absize"; "relsize"|]
let vsize_array = [|"full"; "ascent"|]

let markup = ref true

let () =
  Elm.init Sys.argv;
  
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
  Evas_object.size_hint_weight_set tb Evas.hint_expand 0.;
  Evas_object.size_hint_align_set tb Evas.hint_fill Evas.hint_fill;
  Elm_box.pack_end box tb;
  Evas_object.show tb;

  let c = Elm_check.add win in
  Elm_check.state_set c false;
  Elm_object.text_set c "Autosave";
  Elm_box.pack_end tb c;
  Evas_object.show c;

  let o = Elm_button.add win in
  Elm_object.text_set o "Change format";
  Elm_box.pack_end tb o;
  Evas_object.show o;
  let bformat_changed = o in

  let image_insert_bt = Elm_button.add win in
  Elm_box.pack_end tb image_insert_bt;
  Evas_object.show image_insert_bt;

  let icon = Elm_layout.add win in
  Elm_layout.theme_set icon "entry" "emoticon/haha" "default";
  Elm_object.part_content_set image_insert_bt ~p:"icon" icon;

  let en = Elm_entry.add win in
  Elm_entry.autosave_set en false;
  let _ = Elm_entry.file_set en "/tmp/da_test.txt" `markup_utf8 in
  Evas_object.size_hint_weight_set en Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set en Evas.hint_fill Evas.hint_fill;
  Elm_box.pack_end box en;
  Evas_object.show en;

  let format_changed_cb _ _ =
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
  Evas_object_smart.callback_add bformat_changed "clicked" format_changed_cb;

  let autosave_change_cb obj _ =
    let state = Elm_check.state_get obj in
    Elm_entry.autosave_set en state;
    if state then Elm_entry.file_save en in
  Evas_object_smart.callback_add c "changed" autosave_change_cb;

  let image_insert_cb _ _ =
    let width = ref 64 and height = ref 64 in
    let size = ref 1 and vsize = ref 1 in
    let remo = ref None in

    let inwin = Elm_inwin.add win in
    Evas_object.size_hint_weight_set inwin Evas.hint_expand Evas.hint_expand;
    Evas_object.size_hint_align_set inwin Evas.hint_fill Evas.hint_fill;
    Evas_object.show inwin;

    let box = Elm_box.add win in
    Evas_object.size_hint_weight_set box Evas.hint_expand Evas.hint_expand;
    Evas_object.size_hint_align_set box Evas.hint_fill Evas.hint_fill;
    Elm_inwin.content_set inwin box;
    Evas_object.show box;

    let naviframe = Elm_naviframe.add win in
    Evas_object.size_hint_weight_set naviframe Evas.hint_expand
      Evas.hint_expand;
    Evas_object.size_hint_align_set naviframe Evas.hint_fill Evas.hint_fill;
    Elm_box.pack_end box naviframe;
    Evas_object.show naviframe;

    let settings =
      let box = Elm_box.add win in
      Evas_object.size_hint_weight_set box Evas.hint_expand Evas.hint_expand;
      Evas_object.size_hint_align_set box Evas.hint_fill Evas.hint_fill;
      box in

    let grid =
      let theme = match Elm_theme.list_item_path_get "default"with
      | None -> failwith ""
      | Some(t, _) -> t in
      let emos = Edje.file_collection_list theme in
      if emos = [] then failwith "";
      let grid = Elm_gengrid.add win in
      Elm_gengrid.item_size_set grid 64 80;
      Evas_object.size_hint_weight_set grid Evas.hint_expand Evas.hint_expand;
      Evas_object.size_hint_align_set grid Evas.hint_fill Evas.hint_fill;
      let iter_aux emo =
        try
          let name = sscanf emo "elm/entry/emoticon/%[^/]/default" (fun x -> x)
          in
          let label_get _ _ = name in
          let content_get obj part =
            if part <> "elm.swallow.icon" then None
            else (
              let o = Elm_layout.add obj in
              Elm_layout.theme_set o "entry/emoticon" name "default";
              Some o) in
          let del _ = () and state_get _ _ = true in
          let it_class = {Elm_gengrid.item_style = "default";
            func_text_get = label_get; func_content_get = content_get;
            func_state_get = state_get; func_del = del} in
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

      let accept_set = {Elm_entry.accepted = "0123456789"; rejected = ""} in
      let limit_size = {Elm_entry.max_char_count = 5; max_byte_count = 0} in

      let sizeopts = Elm_frame.add win in
      Elm_object.text_set sizeopts "Size";
      Evas_object.size_hint_weight_set sizeopts Evas.hint_expand 0.;
      Evas_object.size_hint_align_set sizeopts  Evas.hint_fill Evas.hint_fill;
      Elm_box.pack_end box sizeopts;
      Evas_object.show sizeopts;

      let box2 = Elm_box.add win in
      Evas_object.size_hint_weight_set box2 Evas.hint_expand Evas.hint_expand;
      Evas_object.size_hint_align_set box2 Evas.hint_fill Evas.hint_fill;
      Elm_object.content_set sizeopts box2;
      Evas_object.show box2;

      let sizebox = Elm_box.add win in
      Elm_box.horizontal_set sizebox true;
      Evas_object.size_hint_weight_set sizebox Evas.hint_expand
        Evas.hint_expand;
      Evas_object.size_hint_align_set sizebox Evas.hint_fill Evas.hint_fill;
      Elm_box.pack_end box2 sizebox;
      Evas_object.show sizebox;

      let rsize = Elm_radio.add win in
      Elm_object.text_set rsize "Scale adjusted (size)";
      Elm_radio.state_value_set rsize 0;
      Elm_box.pack_end sizebox rsize;
      Evas_object.show rsize;

      let rabsize = Elm_radio.add win in
      Elm_object.text_set rabsize "Absolute size (absize)";
      Elm_radio.state_value_set rabsize 1;
      Elm_radio.group_add rabsize rsize;
      Elm_box.pack_end sizebox rabsize;
      Evas_object.show rabsize;

      let rrelsize = Elm_radio.add win in
      Elm_object.text_set rrelsize "Relative to line (relsize)";
      Elm_radio.state_value_set rrelsize 2;
      Elm_radio.group_add rrelsize rsize;
      Elm_box.pack_end sizebox rrelsize;
      Evas_object.show rrelsize;

      let size_changed_cb _ _ = size := Elm_radio.value_get rsize in
      Elm_radio.value_set rsize !size;
      Evas_object_smart.callback_add rsize "changed" size_changed_cb;

      let vsizebox = Elm_box.add win in
      Elm_box.horizontal_set vsizebox true;
      Evas_object.size_hint_weight_set vsizebox Evas.hint_expand
        Evas.hint_expand;
      Evas_object.size_hint_align_set vsizebox Evas.hint_fill Evas.hint_fill;
      Elm_box.pack_end box2 vsizebox;
      Evas_object.show vsizebox;

      let rvfull = Elm_radio.add win in
      Elm_object.text_set rvfull "Full height (vsize=full)";
      Elm_radio.state_value_set rvfull 0;
      Elm_box.pack_end vsizebox rvfull;
      Evas_object.show rvfull;

      let rvascent = Elm_radio.add win in
      Elm_object.text_set rvascent "Ascent only (vsize=ascent)";
      Elm_radio.state_value_set rvascent 1;
      Elm_radio.group_add rvascent rvfull;
      Elm_box.pack_end vsizebox rvascent;
      Evas_object.show rvascent;

      let vsize_changed_cb _ _ = vsize := Elm_radio.value_get rvfull in
      Elm_radio.value_set rvfull !vsize;
      Evas_object_smart.callback_add rvfull "changed" vsize_changed_cb;
      
      let fwidth = Elm_frame.add win in
      Elm_object.text_set fwidth "Width";
      Evas_object.size_hint_weight_set fwidth Evas.hint_expand 0.;
      Evas_object.size_hint_align_set fwidth Evas.hint_fill Evas.hint_fill;
      Elm_box.pack_end box2 fwidth;
      Evas_object.show fwidth;

      let ewidth = Elm_entry.add win in
      Elm_entry.single_line_set ewidth true;
      Elm_entry.markup_filter_append ewidth
        (Elm_entry.filter_accept_set accept_set);
      Elm_entry.markup_filter_append ewidth
        (Elm_entry.filter_limit_size limit_size);
      Elm_object.text_set ewidth (string_of_int !width);
      Evas_object.size_hint_weight_set ewidth Evas.hint_expand 0.;
      Evas_object.size_hint_align_set ewidth Evas.hint_fill Evas.hint_fill;
      Elm_object.content_set fwidth ewidth;
      Evas_object.show ewidth;
      let width_changed_cb _ _ =
        try width := int_of_string (Elm_object.text_get ewidth) with _ -> () in
      Evas_object_smart.callback_add ewidth "changed" width_changed_cb;
      
      let fheight = Elm_frame.add win in
      Elm_object.text_set fheight "Height";
      Evas_object.size_hint_weight_set fheight Evas.hint_expand 0.;
      Evas_object.size_hint_align_set fheight Evas.hint_fill Evas.hint_fill;
      Elm_box.pack_end box2 fheight;
      Evas_object.show fheight;

      let eheight = Elm_entry.add win in
      Elm_entry.single_line_set eheight true;
      Elm_entry.markup_filter_append eheight
        (Elm_entry.filter_accept_set accept_set);
      Elm_entry.markup_filter_append eheight
        (Elm_entry.filter_limit_size limit_size);
      Elm_object.text_set eheight (string_of_int !height);
      Evas_object.size_hint_weight_set eheight Evas.hint_expand 0.;
      Evas_object.size_hint_align_set eheight Evas.hint_fill Evas.hint_fill;
      Elm_object.content_set fheight eheight;
      Evas_object.show eheight;
      let height_changed_cb _ _ =
        try
          height := int_of_string (Elm_object.text_get eheight)
        with _ -> () in
      Evas_object_smart.callback_add eheight "changed" height_changed_cb;

      let binsert = Elm_button.add win in
      Elm_object.text_set binsert "Insert";
      Elm_box.pack_end box binsert;
      Evas_object.show binsert;

      let btn_insert_cb _ _ =
        let emo = match !remo with Some x -> x | None -> assert false in
        let s = sprintf "<item %s=%dx%d vsize=%s href=emoticon/%s>"
          size_array.(!size) !width !height vsize_array.(!vsize) emo in
        let s1 = if not !markup then Elm_entry.utf8_to_markup s else s in
        edit_buffer_insert en s1;
        Evas_object.del inwin in
      Evas_object_smart.callback_add binsert "clicked" btn_insert_cb in
    fill_settings ();
    let _ = Elm_naviframe.item_simple_push naviframe settings in

    Elm_naviframe.item_simple_promote naviframe grid;
    
    let box2 = Elm_box.add win in
    Elm_box.horizontal_set box2 true;
    Evas_object.size_hint_weight_set box2 Evas.hint_expand 0.;
    Evas_object.size_hint_align_set box2 Evas.hint_fill Evas.hint_fill;
    Elm_box.pack_end box box2;
    Evas_object.show box2;

    let o = Elm_button.add win in
    Elm_object.text_set o "Cancel";
    Evas_object.size_hint_weight_set o Evas.hint_expand Evas.hint_expand;
    Evas_object.size_hint_align_set o Evas.hint_fill Evas.hint_fill;
    Elm_box.pack_end box2 o;
    Evas_object.show o;

    let cancel_cb _ _ = Evas_object.del inwin in
    Evas_object_smart.callback_add o "clicked" cancel_cb in
  Evas_object_smart.callback_add image_insert_bt "clicked" image_insert_cb;

  let win_del_cb obj _ = Evas_object.del obj; Elm.exit () in
  Evas_object_smart.callback_add win "delete,request" win_del_cb;

  Elm_object.focus_set en true;

  Evas_object.resize win 300 780;

  Elm.run ();
  Elm.shutdown ()
