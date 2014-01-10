open Printf

let ht = Hashtbl.create 255
let ht_ind = Hashtbl.create 255

external value_set : Evas.obj -> float -> unit = "ml_elm_slider_value_set"
 
external value_get : Evas.obj -> float = "ml_elm_slider_value_get"

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
  let ind = ind_format_fun x in
  Elm_object.part_text_set obj ~p:"elm.units" (format_fun x);
  Elm_object.part_text_set obj ~p:"elm.indicator" ind;
  Elm_object.part_text_set obj ~p:"elm.dragable.slider:elm.indicator" ind

external add_aux : Evas.obj -> Evas.obj = "ml_elm_slider_add"

let add parent =
  let pb = add_aux parent in
  Evas_object_smart.callback_add pb E.changed changed_cb;
  changed_cb pb;
  pb

let unit_format_function_set obj func =
  Hashtbl.replace ht obj func;
  changed_cb obj

let unit_format_set obj fmt =
  let f x = sprintf fmt x in
  unit_format_function_set obj f

let indicator_format_function_set obj func =
  Hashtbl.replace ht_ind obj func;
  changed_cb obj

let indicator_format_set obj fmt =
  let f x = sprintf fmt x in
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

