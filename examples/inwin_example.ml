open Efl

let styles = [|"default"; "minimal"; "minimal_vertical"|]

let current_style = ref 0

let inwin = ref None

let inwin_hide obj =
  match !inwin with
  | Some w -> Evas_object.hide w
  | None ->
    Elm_object.text_set obj "No inwin!";
    Elm_object.disabled_set obj true

let inwin_destroy obj =
  match !inwin with
  | Some w ->
      Evas_object.del w;
      inwin := None
  | None ->
      Elm_object.text_set obj "No inwin!";
      Elm_object.disabled_set obj true

let btn_clicked obj =
  match !inwin with
  | Some w -> Elm_inwin.activate w
  | None ->
    let parent = match Elm_object.top_widget_get obj with
    | Some p -> p
    | None -> assert false in
    let iw = Elm_inwin.add parent in
    inwin := Some iw;
    let (_ : bool) = Elm_object.style_set iw styles.(!current_style) in
    Evas_object.show iw;

    current_style := (!current_style + 1) mod Array.length styles;

    let o = Elm_box.add parent in
    Evas_object.size_hint_weight_set o Evas.hint_expand Evas.hint_expand;
    Evas_object.size_hint_align_set o Evas.hint_fill Evas.hint_fill;
    Elm_inwin.content_set iw o;
    Evas_object.show o;

    let o = Elm_label.add parent in
    Elm_object.text_set o "Click on the first button to hide the Inwin.<ps>\
      Second to destroy it<ps>";
    Evas_object.show o;

    Elm_box.pack_end (Elm_inwin.content_get iw) o;

    let o = Elm_button.add parent in
    Elm_object.text_set o "Hide";
    Evas_object.show o;

    Evas_object_smart.callback_add_safe o Elm_button.E.clicked inwin_hide;

    Elm_box.pack_end (Elm_inwin.content_get iw) o;

    let o = Elm_button.add parent in
    Elm_object.text_set o "Destroy";
    Evas_object.show o;

    Evas_object_smart.callback_add_safe o Elm_button.E.clicked inwin_destroy;

    Elm_box.pack_end (Elm_inwin.content_get iw) o

let win_del_cb obj =
  match !inwin with
  | Some iw ->
    let o = Elm_inwin.content_unset iw in
    Evas_object.del iw;
    inwin := None;
    let hover = Elm_hover.add obj in
    Elm_hover.target_set hover obj;
    Elm_object.part_content_set hover ~p:"middle" o;
    Evas_object.show hover
  | None -> Evas_object.del obj

let screenshot_hack_cb data () = btn_clicked data ; false

let () =
  Elm.init Sys.argv;

  let (_ : bool) = Elm.policy_set `quit `last_window_closed in
  let win = Elm_win.add "inwin-example" `basic in
  Elm_win.title_set win "Inwin Example";
  Evas_object.resize win 400 400;
  Evas_object.show win;

  Evas_object_smart.callback_add_safe win Elm_win.E.delete_request win_del_cb;

  let bg = Elm_bg.add win in
  Evas_object.size_hint_weight_set bg Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  let box = Elm_box.add win in
  Evas_object.size_hint_weight_set box Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win box;
  Evas_object.show box;

  let o = Elm_button.add win in
  Elm_object.text_set o "Inwin!";
  Evas_object.size_hint_weight_set o Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set o 0. 0.;
  Elm_box.pack_end box o;
  Evas_object.show o;

  Evas_object_smart.callback_add_safe o Elm_button.E.clicked btn_clicked;

  if Elm_config_engine.get () = "shot" then
    (let (_ : Ecore.timer) = Ecore_timer.add 0.1 (screenshot_hack_cb o) in ());

  Elm.run ();
  Elm.shutdown ()
