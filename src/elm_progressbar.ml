(* For elm_progressbar_function_set we do not have a void* data so we have to
reproduce this function via a callback *)

open Printf

let ht = Hashtbl.create 255

external value_set : Evas.obj -> float -> unit = "ml_elm_progressbar_value_set"
 
external value_get : Evas.obj -> float = "ml_elm_progressbar_value_get"

let default_format x = sprintf "%d %%" (int_of_float (x *. 100.))

let changed_cb obj =
  let format_fun = try Hashtbl.find ht obj with Not_found -> default_format in
  let x = value_get obj in
  Elm_object.part_text_set obj ~p:"elm.text.status" (format_fun x)

module E = struct
  type u = Evas.Event_type.u
  let f = Evas.Event_type.create_unit
  let changed = f "changed"
end

external add_aux : Evas.obj -> Evas.obj = "ml_elm_progressbar_add"

let add parent =
  let pb = add_aux parent in
  Evas_object_smart.callback_add pb E.changed changed_cb;
  changed_cb pb;
  pb

external pulse_set : Evas.obj -> bool -> unit = "ml_elm_progressbar_pulse_set"

external pulse_get : Evas.obj -> bool = "ml_elm_progressbar_pulse_get"

external pulse : Evas.obj -> bool -> unit = "ml_elm_progressbar_pulse"

external span_size_set : Evas.obj -> int -> unit =
  "ml_elm_progressbar_span_size_set"

external span_size_get : Evas.obj -> int = "ml_elm_progressbar_span_size_get"

let unit_format_function_set obj func =
  Hashtbl.replace ht obj func;
  changed_cb obj

let unit_format_set obj fmt =
  let f x = sprintf fmt x in
  unit_format_function_set obj f

external horizontal_set : Evas.obj -> bool -> unit =
  "ml_elm_progressbar_horizontal_set"

external horizontal_get : Evas.obj -> bool = "ml_elm_progressbar_horizontal_get"

external inverted_set : Evas.obj -> bool -> unit =
  "ml_elm_progressbar_inverted_set"

external inverted_get : Evas.obj -> bool = "ml_elm_progressbar_inverted_get"

