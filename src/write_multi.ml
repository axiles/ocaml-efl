open Scanf
open Printf

type kind = ML | C

type cmp =
| Geq
| Leq

type line =
| Normal of string
| Begin_section of cmp * int
| End_section
| End_file

let () = if Array.length Sys.argv <> 5 then failwith "Wrong number of arguments"

let kind = match Sys.argv.(1) with
  | "ml" -> ML
  | "c" -> C
  | _ -> failwith "Wrong kind"

let version =
  try sscanf Sys.argv.(2) "%d.%d.%d" (fun x y z -> y)
  with Scan_failure _ -> failwith "Wrong version number"

let input_file = Sys.argv.(3)

let output_file = Sys.argv.(4)

(* Ugly function *)
let read_line ch =
    try (
    let s = input_line ch in
    if s = "" then Normal "" else
    let patern1 () =
      let fmt = match kind with
      | ML -> format_of_string "(* BEGIN: 1.%d *)"
      | C -> format_of_string "/* BEGIN: 1.%d */" in
      sscanf s fmt (fun x -> Begin_section(Geq, x)) in
    let patern2 () =
      let fmt = match kind with
      | ML -> format_of_string "(* BEGIN: %s 1.%d *)"
      | C -> format_of_string "/* BEGIN: %s 1.%d */" in
      sscanf s fmt (fun x y ->
        let x1 = match x with
        | "<=" -> Leq
        | ">=" -> Geq
        | _ -> failwith (sprintf "Wrong operator %s" x) in
        Begin_section(x1, y)) in
    let patern3 () =
      let fmt = match kind with
      | ML -> "(* END *)"
      | C -> "/* END */" in
      if s = fmt then End_section
      else raise Exit in
    let rec aux = function
    | [] -> Normal s
    | f :: fs ->
      try f () with Scan_failure _ | Exit -> aux fs in
    aux [patern1; patern2; patern3]) with End_of_file -> End_file
 
let is_section_valid version cmp sec = 
  let f = match cmp with
  | Geq -> ( >= )
  | Leq -> ( <= ) in
  f version sec

let rec skip_section ch_in line level level0 =
  match read_line ch_in with
  | Normal _ -> skip_section ch_in (line + 1) level level0
  | Begin_section(_, _) -> skip_section ch_in (line + 1) (level + 1) level0
  | End_section ->
    if level > level0 + 1 then skip_section ch_in (line + 1) (level - 1) level0
    else line + 1
  | End_file ->
    failwith (sprintf "Unexpected end of file")

let rec read_file ch_in ch_out line level =
  match read_line ch_in with
  | Normal s ->
    fprintf ch_out "%s\n" s;
    read_file ch_in ch_out (line + 1) level
  | Begin_section(cmp, sec) ->
    let valid = is_section_valid version cmp sec in
    if valid then read_file ch_in ch_out (line + 1) (level + 1)
    else (
      let next_line = skip_section ch_in (line + 1)(level + 1) level in
      read_file ch_in ch_out next_line level
  )
  | End_section ->
    if level > 0 then read_file ch_in ch_out (line + 1) (level - 1)
    else failwith (sprintf "Unexpected end of section at line %d" line)
  | End_file ->
    if level > 0 then failwith (sprintf "Unexpected end of file")

let () =
  let ch_in = open_in input_file in
  let ch_out = open_out output_file in
  read_file ch_in ch_out 1 0;
  fprintf ch_out "%!";
  close_in ch_in;
  close_out ch_out

