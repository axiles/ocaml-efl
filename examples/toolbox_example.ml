open Efl

let ( & ) f x = f x

let () =
  Elm.init ();
  Elm.policy_quit_set `last_window_closed;

  let win = Elm_win.util_standard_add "toolbox" "Toolbox" in
  Elm_win.autodel_set win true;

  let box = Elm_box.add win in
  Elm_win.resize_object_add win box;
  Evas_object.size_hint_set box [`expand; `fill];
  Evas_object.show box;

  let bt = Elm_button.add win in
  Elm_object.text_set bt "Question";
  Elm_box.pack_end box bt;
  Evas_object.show bt;
  Evas_object_smart.callback_add bt Elm_sig.clicked (fun _ ->
    Elm_toolbox.question_box ~title:"Saving before exiting"
      ~buttons:["Yes"; "No"; "Cancel"] ~default:2
      "Would you like to save before exiting?" & fun k ->
    match k with
    | 0 -> print_endline "Saving"
    | 1 -> print_endline "Not saving"
    | 2 -> print_endline "Canceling"
    | _ -> assert false);

  Evas_object.show win;
  Elm.run ();
  Elm.shutdown ()

