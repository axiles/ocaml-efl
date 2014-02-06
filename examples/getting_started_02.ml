open Efl

let on_done obj =
  Elm.exit () (* quit mainloop (Elm.run function will return *)

let () =
  Elm.init ();

  (* new window - do the usual and give it a name (hello) and a title (Hello)*)
  let win = Elm_win.util_standard_add "hello" "Hello" in
  
  (* when the user clicks "close" on a window there is a request to delete *)
  Evas_object_smart.callback_add win Elm_sig.delete_request on_done;

  (* add a box object - default is vertical. a box holds children in a row
   * either horizontally or vertically. nothing more. *)
  let box = Elm_box.add win in
  
  (* make the box horizontal *)
  Elm_box.horizontal_set box true;

  (* add object as a resize object for the window (controls window minimum
   * size as well as gets resized if window is resized) *)
  Elm_win.resize_object_add win box;

  Evas_object.show box;

  (* add a label widget, set the text and put it in the pad frame *)
  let lab = Elm_label.add win in

  (* set default text of the label *)
  Elm_object.text_set lab "Hello out there world!";

  (* pack the label at the end of the box *)
  Elm_box.pack_end box lab;

  Evas_object.show lab;

  (* add an ok button *)
  let btn = Elm_button.add win in

  (* set default text of button to "OK" *)
  Elm_object.text_set btn "Ok";

  (* pack the button at the end of the box *)
  Elm_box.pack_end box btn;

  Evas_object.show btn;

  (* call on_done when the button is clicked *)
  Evas_object_smart.callback_add btn Elm_sig.clicked on_done;

  (* now we are done, show the window *)
  Evas_object.show win;

  (* run the mainloop and process events and callbacks *)
  Elm.run ();

  Elm.shutdown ()

