open Printf

module AF = Autofun.Elm_slider.F (struct
  type evas_object = Evas.obj
end)
include AF

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
let fu_ind = FU.create ()

external value_set : Evas.obj -> float -> unit = "ml_elm_slider_value_set"
 
external value_get : Evas.obj -> float = "ml_elm_slider_value_get"

external unit_format_set_aux : Evas.obj -> string -> unit =
  "ml_elm_slider_unit_format_set"

external indicator_format_set_aux : Evas.obj -> string -> unit =
  "ml_elm_slider_indicator_format_set"

let default_format x = ""

external connect_changed : Evas.obj -> (Evas.obj -> unit) -> unit =
  "ml_connect_Slider_changed"

let changed_cb obj =
  let format_fun = match FU.find fu obj with
  | Some f -> f
  | None -> default_format in
  let ind_format_fun = match FU.find fu_ind obj with
  | Some f -> f
  | None -> default_format in
  let x = value_get obj in
  unit_format_set_aux obj (fstring_of_string (format_fun x));
  indicator_format_set_aux obj (fstring_of_string (ind_format_fun x))

external add_aux : Evas.obj -> Evas.obj = "ml_elm_slider_add"

let free_cb e obj () =
  FU.remove fu obj;
  FU.remove fu_ind obj

let add parent =
  let sl = add_aux parent in
  connect_changed sl changed_cb;
  changed_cb sl;
  Evas_object.event_callback_add_free sl free_cb;
  sl

let addx = Elm_object.create_addx add

let units_format_function_set obj func =
  FU.replace fu obj func;
  changed_cb obj

let unit_format_set obj fmt =
  let f x = sprintf fmt (x *. 100.) in
  units_format_function_set obj f

let indicator_format_function_set obj func =
  FU.replace fu_ind obj func;
  changed_cb obj

let indicator_format_set obj fmt =
  let f x = sprintf fmt (x *. 100.) in
  indicator_format_function_set obj f

external min_max_get : Evas.obj -> float * float = "ml_elm_slider_min_max_get"

