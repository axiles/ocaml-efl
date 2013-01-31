open Efl
open Format

let on_done _ = Elm.exit ()

let bg_opt_of_int = function
  | 1 -> `center
  | 2 -> `scale
  | 3 -> `stretch
  | 4 -> `tile
  | 5 -> `last
  | _ -> invalid_arg "bg_opt_of_int"

let int_of_bg_opt = function
  | `center -> 1
  | `scale -> 2
  | `stretch -> 3
  | `tile -> 4
  | `last -> 5

let cb_radio_changed bg obj =
  Elm_bg.option_set bg (bg_opt_of_int (Elm_radio.value_get obj))

let cb_overlay_changed bg obj =
  if Elm_check.state_get obj then (
    let buff = sprintf "%s/objects/test.edj" (Elm_app.data_dir_get ()) in
    let parent = match Elm_object.parent_widget_get bg with
    | Some p -> p
    | None -> assert false in
    let over = Edje.object_add (Evas_object.evas_get parent) in
    let (_ : bool) = Edje.object_file_set over buff ~g:"bg_overlay" () in
    Elm_object.part_content_set bg ~p:"overlay" over;
  ) else Elm_object.part_content_set_null bg ~p:"overlay" ()

let cb_color_changed bg obj =
  let r, g, b = match Elm_spinner.value_get obj with
  | 1. -> (255, 255, 255)
  | 2. -> (255, 0, 0)
  | 3. -> (0, 0, 255)
  | 4. -> (0, 255, 0)
  | _ -> assert false in
  Elm_bg.color_set bg r g b

let add_radio win box bg ?rdg name opt =
  let rd = Elm_radio.add win in
  Elm_radio.state_value_set rd (int_of_bg_opt opt);
  (match rdg with Some r1 -> Elm_radio.group_add rd r1 | None -> ());
  Elm_object.text_set rd name;
  Evas_object.size_hint_weight_set rd Evas.hint_expand Evas.hint_fill;
  Evas_object_smart.callback_add_safe rd Elm_radio.E.changed
    (cb_radio_changed bg);
  Elm_box.pack_end box rd;
  Evas_object.show rd;
  rd

let add_radios win box bg =
  let aux = add_radio win box bg in
  let rdg = aux "Center" `center in
  let list = [("Scale", `scale); ("Stretch", `stretch); ("Tile", `tile)] in
  List.iter (fun (name, opt) -> ignore (aux ~rdg name opt)) list;
  Elm_radio.value_set rdg (int_of_bg_opt `scale)

let () =
  Elm.init Sys.argv;

  Elm_app.info_set "elementary" ~checkfile:"object/test.edj" ();
  let win = Elm_win.add "bg-options" `basic in
  Elm_win.title_set win "Bg Options";
  Evas_object_smart.callback_add_safe win Elm_win.E.delete_request on_done;
  Elm_win.autodel_set win true;

  let bg = Elm_bg.add win in
  Evas_object.size_hint_weight_set bg Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  let box = Elm_box.add win in
  Evas_object.size_hint_weight_set box Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win box;
  Evas_object.show box;

  let o_bg = Elm_bg.add win in
  let buf = sprintf "%s/images/plant_01.jpg" (Elm_app.data_dir_get ()) in
  Elm_bg.file_set o_bg buf ();
  Evas_object.size_hint_weight_set o_bg Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set o_bg Evas.hint_fill Evas.hint_fill;
  Elm_box.pack_end box o_bg;
  Evas_object.show o_bg;

  let hbox = Elm_box.add win in
  Elm_box.horizontal_set hbox true;
  Evas_object.size_hint_weight_set hbox Evas.hint_expand Evas.hint_fill;
  Evas_object.size_hint_align_set hbox Evas.hint_fill Evas.hint_fill;

  add_radios win hbox o_bg;

  let rd = Elm_check.add win in
  Elm_object.text_set rd "Show Overlay";
  Evas_object.size_hint_weight_set rd Evas.hint_expand Evas.hint_fill;
  Evas_object_smart.callback_add_safe rd Elm_check.E.changed
    (cb_overlay_changed o_bg);
  Elm_box.pack_end hbox rd;
  Evas_object.show rd;

  let rd = Elm_spinner.add win in
  let (_ : bool) = Elm_object.style_set rd "vertical" in
  Elm_spinner.min_max_set rd 1. 4.;
  Elm_spinner.label_format_set rd "%.0f";
  Elm_spinner.editable_set rd false;
  let list = [(1., "White"); (2., "Red"); (3., "Blue"); (4., "Green")] in
  List.iter (fun (i, c) -> Elm_spinner.special_value_add rd i c) list;
  Evas_object.size_hint_weight_set rd Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set rd Evas.hint_fill Evas.hint_fill;
  Evas_object_smart.callback_add_safe rd Elm_spinner.E.changed
    (cb_color_changed o_bg);
  Elm_box.pack_end hbox rd;
  Evas_object.show rd;

  Elm_box.pack_end box hbox;
  Evas_object.show hbox;

  Evas_object.resize win 460 320;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()
