open Printf

let ( / ) = Filename.concat

let ch = open_out ("src" / "efl.mli")

let buffer_size = 1024 

let () =
  let buf = String.create buffer_size in
  for i = 2 to Array.length Sys.argv - 1 do
    let module_name = Sys.argv.(i) in
    let filename = "src" / String.uncapitalize module_name ^ ".mli" in
    fprintf ch "module %s : sig\n" module_name;
    fprintf ch "# 1 \"%s\"\n" filename;
    let ch_in = open_in filename in
    let rec aux () =
      let n = input ch_in buf 0 buffer_size in
      output ch buf 0 n;
      if n < buffer_size then () else aux () in
    aux ();
    close_in ch_in;
    fprintf ch "end\n\n";
  done;
  flush ch;
  close_out ch;
  exit 0

