open Efl
open Printf

let ( & ) f x = f x

let add_test win box name action =
  let bt = Elm_button.add win in
  Elm_object.text_set bt name;
  Elm_box.pack_end box bt;
  Evas_object.show bt;
  Elm_connect.Button.clicked bt (fun _ -> action ())

let question_box_action () =
  Elm_toolbox.question_box ~title:"Saving before exiting"
    ~buttons:["Yes"; "No"; "Cancel"] ~default:2
    "Would you like to save before exiting?"  & fun k ->
  match k with
  | 0 -> print_endline "Saving"
  | 1 -> print_endline "Not saving"
  | 2 -> print_endline "Canceling"
  | _ -> assert false

let message_box_action () =
  Elm_toolbox.message_box ~title:"Info" "Hello World" & fun () ->
  print_endline "Message box closed"

let input_action (f : 'a) () =
  let (_ : 'a) = Elm_toolbox.input_string in
  f ~title:"Entry" ~default_text:"Default text" "Please enter some text"
    & fun x ->
  match x with
  | None -> print_endline "No text have been entered"
  | Some s -> printf "%s\n%!" s

let input_string_action = input_action Elm_toolbox.input_string
let input_text_action = input_action Elm_toolbox.input_text

let () =
  Elm.init ();
  Elm.policy_quit_set `last_window_closed;

  let win = Elm_win.util_standard_add "toolbox" "Toolbox" in
  Elm_win.autodel_set win true;

  let box = Elm_box.add win in
  Elm_win.resize_object_add win box;
  Evas_object.size_hint_set box [`expand; `fill];
  Evas_object.show box;

  let tests = [("Question", question_box_action);
    ("Message", message_box_action); ("Input String", input_string_action);
    ("Input Text", input_text_action)] in
  List.iter (fun (name, action) -> add_test win box name action) tests;

  Evas_object.resize win 300 400;
  Evas_object.show win;
  Elm.run ();
  Elm.shutdown ()

