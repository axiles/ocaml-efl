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
  g "default";
  f "Val_done" "_done";
  g "email";
  g "file";
  g "go";
  g "hex";
  g "invalid";
  g "ip";
  g "join";
  g "last_window_closed";
  g "login";
  g "markup";
  g "markup_utf8";
  g "mixed";
  g "month";
  g "next";
  g "no_image";
  g "none";
  g "normal";
  g "number";
  g "numberonly";
  g "off";
  g "on";
  g "password";
  g "phonenumber";
  g "plain_utf8";
  g "plaintext";
  g "quit";
  g "search";
  g "send";
  g "sentence";
  g "standard";
  g "terminal";
  g "url";
  g "word";
  flush stdout
