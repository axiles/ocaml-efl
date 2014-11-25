open Efl
open Printf

let fit pc obj =
  let x, y, w, h = Elm_photocam.image_region_get pc in
  printf "region: {%d, %d, %d, %d}\n%!" x y w h;
  Elm_photocam.zoom_mode_set pc `auto_fit

let unfit pc obj = Elm_photocam.zoom_mode_set pc `manual

let zoom pc obj =
  let z = Elm_slider.value_get obj *. 8. in
  Elm_photocam.zoom_set pc z

let bring_in obj =
  let w, h = Elm_photocam.image_size_get obj in
  Elm_photocam.image_region_bring_in obj (w / 2) (h / 2) 500 400

let () =
  Elm.init ();
  Elm_app.info_set "elementary"
    ~checkfile:"images/insanely_huge_test_image.jpg" ();
  Elm.policy_quit_set `last_window_closed;

  let win = Elm_win.util_standard_add "photocam" "Photocam" in
  Elm_win.autodel_set win true;

  let pc = Elm_photocam.add win in
  let buf = sprintf "%s/images/insanely_huge_test_image.jpg"
    (Elm_app.data_dir_get ()) in
  ignore (Elm_photocam.file_set pc buf : Evas.load_error);
  Elm_scroller.bounce_set pc false true;
  Elm_connect.Photocam.load_detail pc bring_in;
  Evas_object.resize pc 500 400;
  Evas_object.show pc;

  let add_widget add_func f label x w cb =
    let obj = add_func win in
    Elm_object.text_set obj label;
    Evas_object.show obj;
    Evas_object.resize obj w 30;
    Evas_object.move obj x 410;
    f obj (cb pc) in

  let add_button = add_widget Elm_button.add Elm_connect.Button.clicked in
  add_button "Fit" 10 50 fit;
  add_button "Unfit" 70 70 unfit;
  add_widget Elm_slider.add Elm_connect.Slider.changed "Zoom" 150 300 zoom;

  Evas_object.resize win 500 440;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ()

