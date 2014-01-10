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

let ht = Hashtbl.create 255
let ht_ind = Hashtbl.create 255

external value_set : Evas.obj -> float -> unit = "ml_elm_slider_value_set"
 
external value_get : Evas.obj -> float = "ml_elm_slider_value_get"

external unit_format_set_aux : Evas.obj -> string -> unit =
  "ml_elm_slider_unit_format_set"

external indicator_format_set_aux : Evas.obj -> string -> unit =
  "ml_elm_slider_indicator_format_set"

let default_format x = ""

module E = struct
  type u = Evas.Event_type.u
  let f = Evas.Event_type.create_unit
  let changed = f "changed"
  let slider_drag_start = f "slider,drag,start"
  let slider_drag_stop = f "slider,drag,stop"
  let delay_changed = f "delay,changed"
  let focused = f "focused"
  let unfocused = f "unfocused"
end

let changed_cb obj =
  let format_fun = try Hashtbl.find ht obj with Not_found -> default_format in
  let ind_format_fun = try Hashtbl.find ht_ind obj
    with Not_found -> default_format in
  let x = value_get obj in
  unit_format_set_aux obj (fstring_of_string (format_fun x));
  indicator_format_set_aux obj (fstring_of_string (ind_format_fun x))

external add_aux : Evas.obj -> Evas.obj = "ml_elm_slider_add"

let add parent =
  let pb = add_aux parent in
  Evas_object_smart.callback_add pb E.changed changed_cb;
  changed_cb pb;
  pb

let units_format_function_set obj func =
  Hashtbl.replace ht obj func;
  changed_cb obj

let unit_format_set obj fmt =
  let f x = sprintf fmt (x *. 100.) in
  units_format_function_set obj f

let indicator_format_function_set obj func =
  Hashtbl.replace ht_ind obj func;
  changed_cb obj

let indicator_format_set obj fmt =
  let f x = sprintf fmt (x *. 100.) in
  indicator_format_function_set obj f

external span_size_set : Evas.obj -> int -> unit = "ml_elm_slider_span_size_set"

external span_size_get : Evas.obj -> int = "ml_elm_slider_span_size_get"

external horizontal_set : Evas.obj -> bool -> unit =
  "ml_elm_slider_horizontal_set"

external horizontal_get : Evas.obj -> bool = "ml_elm_slider_horizontal_get"

external min_max_set : Evas.obj -> float -> float -> unit =
  "ml_elm_slider_min_max_set"

external min_max_get : Evas.obj -> float * float = "ml_elm_slider_min_max_get"

external inverted_set : Evas.obj -> bool -> unit =
  "ml_elm_slider_inverted_set"

external inverted_get : Evas.obj -> bool = "ml_elm_slider_inverted_get"

external indicator_show_set : Evas.obj -> bool -> unit =
  "ml_elm_slider_indicator_show_set"

external indicator_show_get : Evas.obj -> bool =
  "ml_elm_slider_indicator_show_get"

