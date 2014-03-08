open Printf

let () =
  let ch_lib = open_in Sys.argv.(1) in
  let ch_intro = open_out Sys.argv.(2) in
  let next_line () = try Some (input_line ch_lib) with End_of_file -> None in
  let rec next_module () =
    let line = next_line () in
    match line with
    | Some s -> if s.[0] = '#' then next_module () else line
    | None -> None in
  fprintf ch_intro "
  {2 Introduction}

  - {{!Start} Getting Started}
  - {{:https://forge.ocamlcore.org/projects/ocaml-efl/}
      OCaml Forge page}
  - {{:https://github.com/axiles/ocaml-efl} GitHub page}
  - {{:https://forge.ocamlcore.org/frs/?group_id=329} Download page}
  - {{:https://www.enlightenment.org} Enlightenment Website}
  

  {2 API}
  
  You can use EFL/Elementary official documentation available at the
  {{:https://www.enlightenment.org} Enlightenment Website}

  {!indexlist}
  {!modules: ";
  let rec loop () =
    match next_module () with
    | Some m -> fprintf ch_intro "%s " m; loop ()
    | None -> () in
  loop ();
  fprintf ch_intro "}\n%!";
  close_in ch_lib;
  close_out ch_intro

