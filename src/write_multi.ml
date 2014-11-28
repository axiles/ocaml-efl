open Scanf
open Printf

type kind = ML | C

type line =
| Normal of string
| Begin_section of string
| End_section
| End_file

let () = if Array.length Sys.argv <> 5 then failwith "Wrong number of arguments"

let kind = match Sys.argv.(1) with
  | "ml" -> ML
  | "c" -> C
  | _ -> failwith "Wrong kind"

let version =
  try sscanf Sys.argv.(2) "%d.%d.%d" (fun x y z -> sprintf "%d.%d" x y)
  with Scan_failure _ -> failwith "Wrong version number"

let input_file = Sys.argv.(3)

let output_file = Sys.argv.(4)

let read_line ch =
  try (
    let s = input_line ch in
    if s = "" then Normal s else
    let ((fmt_open, s_close) : ('a, 'b, 'c, 'd, 'e, 'f) format6 * string) =
      match kind with
      | ML -> ("(* BEGIN: %s *)", "(* END *)")
      | C -> ("/* BEGIN: %s */", "/* END */") in
    try sscanf s fmt_open (fun x -> Begin_section x) with Scan_failure _ ->
    if s = s_close then End_section
    else Normal s
  ) with End_of_file -> End_file

let is_section_valid version sec =
  match version, sec with
  | ("1.11", "1.12") ->  false
  | ("1.12", "1.12") -> true
  | _ -> failwith "Wrong section"

let rec read_file ch_in ch_out =
  match read_line ch_in with
  | Normal s -> fprintf ch_out "%s\n" s; read_file ch_in ch_out
  | Begin_section sec ->
    let valid = is_section_valid version sec in
    read_section valid ch_in ch_out
  | End_section -> failwith "Unexpected end of section"
  | End_file -> ()

and read_section valid ch_in ch_out =
  match read_line ch_in with
  | Normal s ->
    if valid then fprintf ch_out "%s\n" s;
    read_section valid ch_in ch_out
  | Begin_section _ -> failwith "Unexpected begin of section"
  | End_section -> read_file ch_in ch_out
  | End_file -> failwith "Unexpected end of file"

let () =
  let ch_in = open_in input_file in
  let ch_out = open_out output_file in
  read_file ch_in ch_out;
  fprintf ch_out "%!";
  close_in ch_in;
  close_out ch_out

