open Efl
open Printf

let clear_btn_clicked_cb hoversel obj = Elm_hoversel.clear hoversel

let print_items obj _ =
  let items = Elm_hoversel.items_get obj in
  let aux it = printf "%s\n" (Elm_object.item_text_get it) in
  List.iter aux items;
  printf "%!"

let add_item =
  let num = ref 0 in
  fun obj ->
    incr num;
    let str = sprintf "item %d" !num in
    ignore (Elm_hoversel.item_add obj ~label:str () : Elm_object.item)

let () =
  Elm.init ();
  Elm.policy_quit_set `last_window_closed;

  let win = Elm_win.util_standard_add "hoversel" "Hoversel" in
  Elm_win.autodel_set win true;
  Evas_object.resize win 200 300;
  Evas_object.show win;

  let rect = Evas_object.rectangle_add (Evas_object.evas_get win) in
  Evas_object.color_set rect 255 0 0 255;
  Evas_object.show rect;

  let hoversel = Elm_hoversel.add win in
  Elm_hoversel.hover_parent_set hoversel win;
  Elm_hoversel.horizontal_set hoversel false;
  Elm_object.text_set hoversel "Add an item to Hoversel";
  Elm_object.part_content_set hoversel ~p:"icon" rect;
  ignore (Elm_hoversel.item_add hoversel ~label:"Print items"
    ~func:print_items () : Elm_object.item);
  ignore (Elm_hoversel.item_add hoversel ~label:"Option 2"
    ~icon:("home", `standard) () : Elm_object.item);
  Evas_object_smart.callback_add hoversel Elm_hoversel.E.clicked add_item;

  Evas_object.resize hoversel 180 30;
  Evas_object.move hoversel 10 10;
  Evas_object.show hoversel;

  let btn = Elm_button.add win in
  Elm_object.text_set btn "Clear all items";
  Evas_object_smart.callback_add btn Elm_button.E.clicked
    (clear_btn_clicked_cb hoversel);
  Evas_object.resize btn 180 30;
  Evas_object.move btn 10 50;
  Evas_object.show btn;

  Elm.run ();
  Elm.shutdown ()

