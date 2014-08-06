module AF = Autofun.Elm_progressbar.F (struct
  type evas_object = Evas.obj
end)
include AF

(* For elm_progressbar_function_set we do not have a void* data so we have to
reproduce this function via a callback *)

open Printf

(* This replace every % by %% *)
let fstring_of_string s =
  let num_percent = ref 0 in
  String.iter (fun c -> if c = '%' then incr num_percent) s;
  let s1 = String.create (String.length s + !num_percent) in
  let rec aux i j =
    if i >= String.length s then ()
    else (
      let c = s.[i] in
      if c = '%' then (
        s1.[j] <- '%';
        s1.[j + 1] <- '%';
        aux (i + 1) (j + 2)
      ) else (
        s1.[j] <- c;
        aux (i + 1) (j + 1))) in
  aux 0 0;
  s1

module FU : sig
  type t
  val create : unit -> t
  val replace : t -> Evas.obj -> (float -> string) -> unit
  val remove : t -> Evas.obj -> unit
  val find : t -> Evas.obj -> (float -> string) option
end = struct
  module M = Map.Make (struct
    type t = Evas.obj
    let compare : Evas.obj -> Evas.obj -> int = compare
  end)
  type t = (float -> string) M.t ref
  let create () = ref M.empty
  let replace fu obj f = fu := M.add obj f !fu
  let remove fu obj = fu := M.remove obj !fu
  let find fu obj = try Some (M.find obj !fu) with Not_found -> None
end

let fu = FU.create ()

external unit_format_set_aux : Evas.obj -> string -> unit =
  "ml_elm_progressbar_unit_format_set"

let default_format x = sprintf "%d %%" (int_of_float (x *. 100.))

let changed_cb obj =
  let format_fun = match FU.find fu obj with
  | Some f -> f
  | None -> default_format in
  let x = value_get obj in
  unit_format_set_aux obj (fstring_of_string (format_fun x))

external connect_changed : Evas.obj -> (Evas.obj -> unit) -> unit =
  "ml_connect_Progressbar_changed"

external add_aux : Evas.obj -> Evas.obj = "ml_elm_progressbar_add"

let free_cb e obj () = FU.remove fu obj

let add parent =
  let pb = add_aux parent in
  connect_changed pb changed_cb;
  changed_cb pb;
  Evas_object.event_callback_add_free pb free_cb;
  pb

let addx = Elm_object.create_addx add

external pulse : Evas.obj -> bool -> unit = "ml_elm_progressbar_pulse"

let unit_format_function_set obj func =
  FU.replace fu obj func;
  changed_cb obj

let unit_format_set obj fmt =
  let f x = sprintf fmt (x *. 100.) in
  unit_format_function_set obj f

external part_value_set : Evas.obj -> ?p:string -> float -> unit =
  "ml_elm_progressbar_part_value_set"

external part_value_get : Evas.obj -> ?p:string -> unit -> float =
  "ml_elm_progressbar_part_value_get"

