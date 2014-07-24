open Format
open Common

let list = [
  ("Elm_bg", Elm_bg.funs);
  ("Elm_button", Elm_button.funs);
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

