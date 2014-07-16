include Henums.Elm_glview

type func_cb = Evas.obj -> unit

external add : Evas.obj -> Evas.obj = "ml_elm_glview_add"

let addx = Elm_object.create_addx add

external size_set : Evas.obj -> int -> int -> unit = "ml_elm_glview_size_set"

external size_get : Evas.obj -> int * int = "ml_elm_glview_size_get"

external gl_api_get : Evas.obj -> Evas.gl_api = "ml_elm_glview_gl_api_get"

external mode_set : Evas.obj -> mode list -> unit = "ml_elm_glview_mode_set"

external resize_policy_set : Evas.obj -> resize_policy -> bool =
  "ml_elm_glview_resize_policy_set"

external render_policy_set : Evas.obj -> render_policy -> bool =
  "ml_elm_glview_render_policy_set"

let default_func x = ()

let ht_init = Hashtbl.create 8

let init_func obj =
  let f = try Hashtbl.find ht_init obj with Not_found -> default_func in
  f obj

let () = Callback.register "Elm_GLView_Func_Cb_init" init_func

let init_func_set obj f = Hashtbl.replace ht_init obj f

let ht_del = Hashtbl.create 8

let del_func obj =
  let f = try Hashtbl.find ht_del obj with Not_found -> default_func in
  f obj

let () = Callback.register "Elm_GLView_Func_Cb_del" del_func

let del_func_set obj f = Hashtbl.replace ht_del obj f

let ht_resize = Hashtbl.create 8

let resize_func obj =
  let f = try Hashtbl.find ht_resize obj with Not_found -> default_func in
  f obj

let () = Callback.register "Elm_GLView_Func_Cb_resize" resize_func

let resize_func_set obj f = Hashtbl.replace ht_resize obj f

let ht_render = Hashtbl.create 8

let render_func obj =
  let f = try Hashtbl.find ht_render obj with Not_found -> default_func in
  f obj

let () = Callback.register "Elm_GLView_Func_Cb_render" render_func

let render_func_set obj f = Hashtbl.replace ht_render obj f

external changed_set : Evas.obj -> unit = "ml_elm_glview_changed_set"

