open Printf

module AF = Autofun.Elm_spinner.F (struct
  type evas_object = Evas.obj
end)
include AF

open Common
             
let ht = Hashtbl.create 15

external label_format_set_aux : Evas.obj -> string -> unit =
  "ml_elm_spinner_label_format_set"

let default_format x = sprintf "%.0f" x

let changed_cb obj =
  let format_fun = try Hashtbl.find ht obj with Not_found -> default_format in
  let x = value_get obj in
  label_format_set_aux obj (fstring_of_string (format_fun x))

external add_aux : Evas.obj -> Evas.obj = "ml_elm_spinner_add"

external connect_changed : Evas.obj -> (Evas.obj -> unit) -> unit =
  "ml_connect_Spinner_changed"

let add parent =
  let pb = add_aux parent in
  connect_changed pb changed_cb;
  changed_cb pb;
  pb

let addx = Elm_object.create_addx add

external min_max_get : Evas.obj -> float * float = "ml_elm_spinner_min_max_get"

let label_format_function_set obj func =
  Hashtbl.replace ht obj func;
  changed_cb obj

let label_format_set obj fmt =
  let format_func x = sprintf fmt x in
  label_format_function_set obj format_func

