open Printf

external get_hash_value : string -> string = "ml_get_hash_value"

let f x y = printf "#define %s %s\n" x (get_hash_value y)

let g x = f (sprintf "Val_%s" x) x

let () =
  g "basic";
  g "quit";
  g "none";
  g "last_window_closed";
  g "char";
  g "word";
  g "mixed";
  g "file";
  g "standard";
  g "plain_utf8";
  g "markup_utf8";
  flush stdout
