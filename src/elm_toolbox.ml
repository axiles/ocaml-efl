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

let question_box ~title ~buttons ?default ?icon ?parent question cb =
  let win = add_dialog ?p:parent "question_box" in
  Elm_win.title_set win title;
  let quit x = Evas_object.del win; cb x in
  let del_cb obj =
    match default with
    | Some d -> quit d
    | None -> () in
  Evas_object_smart.callback_add win Elm_sig.delete_request del_cb;

  let box = Elm_box.add win in
  Elm_win.resize_object_add win box;
  Evas_object.size_hint_set box [`expand; `fill];
  Evas_object.show box;

  let label_packing = match icon with
  | None -> Elm_box.pack_end box
  | Some i ->
     let hbox = Elm_box.add win in
     Elm_box.horizontal_set hbox true;
     Evas_object.size_hint_set hbox [`expand; `fill];
     Elm_box.pack_end box hbox;
     Evas_object.show hbox;
     Elm_box.pack_end hbox i;
     Elm_box.pack_end hbox in

  let label = Elm_label.add win in
  label_packing label;
  Evas_object.size_hint_set label [`expand; `fill];
  Elm_object.text_set label question;
  Evas_object.show label;

  let hbox = Elm_box.add win in
  Elm_box.horizontal_set hbox true;
  Evas_object.size_hint_set hbox [`hexpand; `hfill];
  Elm_box.pack_end box hbox;
  Evas_object.show hbox;

  let add_bt i text_bt =
    let bt = Elm_button.add win in
    Elm_object.text_set bt text_bt;
    (match default with
    | Some d -> if i = d then Evas_object.focus_set bt true
    | None -> ());
    Elm_box.pack_end hbox bt;
    Evas_object.show bt;
    Evas_object_smart.callback_add bt Elm_sig.clicked (fun _ -> quit i) in
  iteri add_bt buttons;

  (*Elm_win.center win true true;*)
  Evas_object.show win

