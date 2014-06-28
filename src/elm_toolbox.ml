let add_dialog ?p name =
  let win = Elm_win.add ?p name `dialog_basic in
  Elm_win.modal_set win true;
  let bg = Elm_bg.add win in
  Elm_win.resize_object_add win bg;
  Evas_object.size_hint_set bg [`expand];
  Evas_object.show bg;
  win

let iteri f list =
  let rec aux k x = f k x; k + 1 in
  ignore (List.fold_left aux 0 list : int)

let add_vbox win =
  let box = Elm_box.add win in
  Elm_win.resize_object_add win box;
  Evas_object.size_hint_set box [`expand; `fill];
  Evas_object.show box;
  box

let add_label win packing text =
  let label = Elm_label.add win in
  packing label;
  Evas_object.size_hint_set label [`expand; `fill];
  Elm_object.text_set label text;
  Evas_object.show label

let add_icon win box icon =
  match icon with
  | None -> Elm_box.pack_end box
  | Some i ->
     let hbox = Elm_box.add win in
     Elm_box.horizontal_set hbox true;
     Evas_object.size_hint_set hbox [`expand; `fill];
     Elm_box.pack_end box hbox;
     Evas_object.show hbox;
     Elm_box.pack_end hbox i;
     Elm_box.pack_end hbox

let add_hbox win box =
  let hbox = Elm_box.add win in
  Elm_box.horizontal_set hbox true;
  Evas_object.size_hint_set hbox [`hexpand; `hfill];
  Elm_box.pack_end box hbox;
  Evas_object.show hbox;
  hbox

let add_bt win box text cb =
  let bt = Elm_button.add win in
  Elm_object.text_set bt text;
  Elm_box.pack_end box bt;
  Evas_object.show bt;
  Evas_object_smart.callback_add bt Elm_sig.clicked cb;
  bt

let question_box ~title ~buttons ?default ?icon ?parent question cb =
  let win = add_dialog ?p:parent "question_box" in
  Elm_win.title_set win title;
  let quit x = Evas_object.del win; cb x in
  let del_cb obj =
    match default with
    | Some d -> quit d
    | None -> () in
  Evas_object_smart.callback_add win Elm_sig.delete_request del_cb;

  let box = add_vbox win in

  let label_packing = add_icon win box icon in

  add_label win label_packing question;

  let hbox = add_hbox win box in

  let add_bt i text_bt =
    let bt = add_bt win hbox text_bt (fun _ -> quit i) in
    match default with
    | Some d -> if i = d then Evas_object.focus_set bt true
    | None -> () in
  iteri add_bt buttons;

  (*Elm_win.center win true true;*)
  Evas_object.show win

let message_box ~title ?icon ?(ok = "Ok") ?parent msg cb =
  let win = add_dialog ?p:parent "message_box" in
  Elm_win.title_set win title;
  let quit () = Evas_object.del win; cb () in
  let del_cb obj = quit () in
  Evas_object_smart.callback_add win Elm_sig.delete_request del_cb;

  let box = add_vbox win in

  let label_packing = add_icon win box icon in

  add_label win label_packing msg;

  ignore (add_bt win box ok del_cb : Evas.obj);

  Evas_object.show win

let input sl name ~title ?(ok = "Ok") ?(cancel = "Cancel") ?default_text ?parent
    msg cb =
  let win = add_dialog ?p:parent name in
  Elm_win.title_set win title;
  let quit x = Evas_object.del win; cb x in
  let cancel_cb obj = quit None in
  let ok_cb entry obj =
    quit (Some (Elm_entry.markup_to_utf8 (Elm_entry.entry_get entry))) in
  Evas_object_smart.callback_add win Elm_sig.delete_request cancel_cb;

  let box = add_vbox win in

  add_label win (Elm_box.pack_end box) msg;

  let entry = Elm_entry.add win in
  Evas_object.size_hint_set entry [`expand; `fill];
  Elm_box.pack_end box entry;
  (match default_text with Some t -> Elm_entry.entry_set entry t | None -> ());
  Evas_object.show entry;
  Elm_entry.single_line_set entry sl;
  if sl then
    Evas_object_smart.callback_add entry Elm_sig.activated (ok_cb entry);

  let hbox = add_hbox win box in
  ignore (add_bt win hbox ok (ok_cb entry));
  ignore (add_bt win hbox cancel cancel_cb);

  Evas_object.show win;
  Elm_object.focus_set entry true;
  Elm_entry.cursor_end_set entry

let input_string = input true "input_string"

let input_text = input false "input_text"

