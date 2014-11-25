open Efl
open Printf

let () =
  Elm.init ();
  Elm.policy_quit_set `last_window_closed;
  let win = Elm_win.addx ~autodel:true ~title:"Testing events" "event" in
  let btn = Elm_button.addx ~win ~text:"Hello" win in
  let et = Ecore.event_type_new () in
  let handler_cb _ s = printf "Hello %s\n%!" s; true in
  let handler = Ecore.event_handler_add et handler_cb in
  let clicked_cb _ = ignore (Ecore.event_add et "World" (fun _ -> ())) in
  Elm_connect.Button.clicked btn clicked_cb;
  Evas_object.show win;
  Elm.run ();
  Ecore.event_handler_del handler;
  Elm.shutdown ()

