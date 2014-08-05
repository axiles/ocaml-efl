open Format
open Common

let list = [
  ("Elm_bg", Elm_bg.funs);
  ("Elm_box", Elm_box.funs);
  ("Elm_bubble", Elm_bubble.funs);
  ("Elm_button", Elm_button.funs);
  ("Elm_calendar", Elm_calendar.funs);
  ("Elm_check", Elm_check.funs);
  ("Elm_clock", Elm_clock.funs);
  ("Elm_colorselector", Elm_colorselector.funs);
  ("Elm_datetime", Elm_datetime.funs);
  ("Elm_dayselector", Elm_dayselector.funs);
  ("Elm_diskselector", Elm_diskselector.funs);
  ("Elm_entry", Elm_entry.funs);
  ("Elm_flip", Elm_flip.funs);
  ("Elm_flipselector", Elm_flipselector.funs);
  ("Elm_frame", Elm_frame.funs);
  ("Elm_gengrid", Elm_gengrid.funs);
  ("Elm_genlist", Elm_genlist.funs);
  ("Elm_gesture_layer", Elm_gesture_layer.funs);
  ("Elm_glview", Elm_glview.funs);
  ("Elm_grid", Elm_grid.funs);
  ("Elm_hover", Elm_hover.funs); 
  ("Elm_icon", Elm_icon.funs);
  ("Elm_image", Elm_image.funs);
  ("Elm_index", Elm_index.funs);
  ("Elm_label", Elm_label.funs);
  ("Elm_list", Elm_list.funs);
  ("Elm_map", Elm_map.funs);
  ("Elm_mapbuf", Elm_mapbuf.funs);
  ("Elm_menu", Elm_menu.funs);
  ("Elm_notify", Elm_notify.funs);
  ("Elm_panel", Elm_panel.funs);
  ("Elm_panes", Elm_panes.funs);
  ("Elm_photo", Elm_photo.funs);
  ("Elm_photocam", Elm_photocam.funs);
  ("Elm_plug", Elm_plug.funs);
  ("Elm_progressbar", Elm_progressbar.funs);
  ("Elm_radio", Elm_radio.funs);
  ("Elm_scroller", Elm_scroller.funs);
  ("Elm_segment_control", Elm_segment_control.funs);
  ("Elm_separator", Elm_separator.funs);
  ("Elm_slider", Elm_slider.funs);
  ("Elm_slideshow", Elm_slideshow.funs);
  ("Elm_spinner", Elm_spinner.funs);
]

let write filename print secs =
  let ch = open_out filename in
  let fmt = formatter_of_out_channel ch in
  print fmt secs;
  fprintf fmt "%!";
  close_out ch

let ( / ) = Filename.concat

let () =
  let secs = Sections.create list in
  write ("src" / "autofun.ml") Sections.print_ml secs;
  write ("src" / "autofun_wrap.c") Sections.print_c secs;
  exit 0

