(* WARNING: This example is still in heavy development *)

open Scanf

let edit_buffer_insert e text =
  Elm_entry.entry_insert e text;
  Elm_object.focus_set e true

let size_array = ["size"; "absize"; "relsize"]
let vsize_array = ["full"; "ascent"]

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
  Elm_object.text_set o "b";
  Elm_box.pack_end tb o;
  Evas_object.show o;

  let o = Elm_button.add win in
  Elm_object.text_set o "em";
  Elm_box.pack_end tb o;

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

  let autosave_change_cb obj _ =
    let state = Elm_check.state_get obj in
    Elm_entry.autosave_set en state;
    if state then Elm_entry.file_save en in
  Evas_object_smart.callback_add c "changed" autosave_change_cb;

  let image_insert_cb _ _ =
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
          let sel_cb obj _ = () in
          ignore (Elm_gengrid.item_append grid it_class sel_cb)
        with Scan_failure _ -> () in
      List.iter iter_aux emos;
      grid in
    Elm_naviframe.item_simple_push naviframe grid;
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
