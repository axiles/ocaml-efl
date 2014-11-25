open Efl

let () =
  Elm.init ();
  Elm.policy_quit_set `last_window_closed;

  let win = Elm_win.util_standard_add "Datetime" "Datetime" in
  Elm_win.autodel_set win true;

  let bx = Elm_box.add win in
  Evas_object.size_hint_set bx [`expand];
  Elm_win.resize_object_add win bx;
  Elm_box.horizontal_set bx true;
  Evas_object.show bx;

  let add_datetime list =
    let dt = Elm_datetime.add win in
    Evas_object.size_hint_set dt [`expand; `hfill];
    List.iter (fun t -> Elm_datetime.field_visible_set dt t false) list;
    Elm_box.pack_end bx dt;
    Evas_object.show dt in

  List.iter add_datetime [[`hour; `minute; `ampm]; [`year; `month; `date]; []];

  Evas_object.show win;
  Elm.run ();
  Elm.shutdown ()

