open Printf

let ( / ) = Filename.concat

let ch = open_out ("src" / "efl.mli")

let string_iteri f s =
  for i = 0 to String.length s - 1 do
    f i s.[i]
  done

(* Forward compatible implementation of String.mapi *)
let string_mapi f s =
  let buf = Buffer.create (String.length s) in
  let aux i c = Buffer.add_char buf (f i c) in
  string_iteri aux s;
  Buffer.contents buf
  
(* Forward compatible implementarion of lowercase*)
let char_lowercase c =
  if 'A' <= c && c <= 'Z' then
    char_of_int (int_of_char c + int_of_char 'a' - int_of_char 'A')
  else c
let string_lowercase s = string_mapi (fun i c -> char_lowercase c) s

let buffer_size = 1024 

let () =
  for i = 1 to Array.length Sys.argv - 1 do
    let module_name = Sys.argv.(i) in
    let filename = "src" / string_lowercase module_name ^ ".mli" in
    fprintf ch "module %s : sig\n" module_name;
    fprintf ch "# 1 \"%s\"\n" filename;
    let ch_in = open_in filename in
    (try while true do
      let line = input_line ch_in in
      fprintf ch "%s\n" line;
    done with End_of_file -> ());
    close_in ch_in;
    fprintf ch "end\n\n";
  done;
  flush ch;
  close_out ch;
  exit 0

