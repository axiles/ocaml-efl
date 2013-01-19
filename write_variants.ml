open Printf

external get_hash_value : string -> string = "ml_get_hash_value"

let f x y = printf "#define %s %s\n" x (get_hash_value y)

let g x = f (sprintf "Val_%s" x) x

let () =
  g "allcharacter";
  g "alphabet";
  g "auto";
  g "automatic";
  g "basic";
  g "char";
  g "close";
  g "combo";
  g "default";
  g "desktop";
  g "dialog_basic";
  g "dnd";
  g "dock";
  f "Val_done" "_done";
  g "dropdown_menu";
  g "email";
  g "file";
  g "focus_back";
  g "focus_forward";
  g "focus_home";
  g "go";
  g "hex";
  g "inlined_image";
  g "invalid";
  g "ip";
  g "join";
  g "last_window_closed";
  g "login";
  g "markup";
  g "markup_utf8";
  g "menu";
  g "mixed";
  g "month";
  g "next";
  g "no_image";
  g "none";
  g "normal";
  g "notification";
  g "number";
  g "numberonly";
  g "off";
  g "on";
  g "password";
  g "phonenumber";
  g "plain_utf8";
  g "plaintext";
  g "popup_menu";
  g "quit";
  g "search";
  g "send";
  g "sentence";
  g "splash";
  g "socket_image";
  g "standard";
  g "terminal";
  g "toolbar";
  g "tooltip";
  g "url";
  g "utility";
  g "word";
  flush stdout
