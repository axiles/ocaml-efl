open Printf

let ( / ) = Filename.concat

let ch = open_out ("src" / "efl.mli")

let buffer_size = 1024 

let () =
  for i = 2 to Array.length Sys.argv - 1 do
    let module_name = Sys.argv.(i) in
    let filename = "src" / String.uncapitalize module_name ^ ".mli" in
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

