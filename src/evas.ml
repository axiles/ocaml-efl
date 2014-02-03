type ptr

type obj

type t

type smart_cb = obj -> ptr -> unit

type modifier

module Event_mouse_down = struct
  type t = {
    button : int;
    output_x : int;
    output_y : int;
    canvas_x : int;
    canvas_y : int;
    modifiers : modifier;
    flags_double_click : bool;
    flags_triple_click : bool;
  }
end

type event_mouse_down = Event_mouse_down.t

module Event_mouse_up = struct
  type t = {
    button : int;
    output_x : int;
    output_y : int;
    canvas_x : int;
    canvas_y : int;
    modifiers : modifier;
    flags_double_click : bool;
    flags_triple_click : bool;
  }
end

type event_mouse_up = Event_mouse_up.t

module Event_key_down = struct
  type t = {
    keyname : string;
    modifiers : modifier;
    key : string;
    str : string;
    compose : string;
    timestamp : int;
  }
end

type event_key_down = Event_key_down.t

type event_info = [
  | `mouse_down of event_mouse_down
  | `mouse_up of event_mouse_up
  | `key_down of event_key_down
  | `other
]

type aspect_control = [`none | `neither | `horizontal | `vertical | `both]

type load_error = [
  | `none
  | `generic
  | `does_not_exist
  | `permission_denied
  | `resource_allocation_failed
  | `corrupt_file
  | `unknown_format
]

module Event_type = struct
  type 'a t = {name : string; make_cb : 'a -> smart_cb}
  type 'a v = (obj -> 'a -> unit) t
  type u = (obj -> unit) t
  type 'a r = (obj -> 'a) t
  let create name value_of_ptr =
    let make_cb f obj ptr = f obj (value_of_ptr ptr) in
    {name; make_cb}
  let create_unit name =
    let make_cb f obj ptr = f obj in
    {name; make_cb}
  let create_ref name store_ptr =
    let make_cb f obj ptr =
      let x = f obj in store_ptr ptr x in
    {name; make_cb}
  let get_name et = et.name
  let get_cb et f = et.make_cb f
end 

let hint_expand = 1.

let hint_fill = -1.

external string_of_ptr : ptr -> string = "ml_string_of_ptr"

external string_opt_of_ptr : ptr -> string option = "ml_string_opt_of_ptr"

external pointer_canvas_xy_get : t -> int * int =
  "ml_evas_pointer_canvas_xy_get"

external smart_objects_calculate : t -> unit =
  "ml_evas_smart_objects_calculate"

external bool_of_ptr : ptr -> bool = "ml_bool_of_ptr"

external string_string_of_ptr : ptr -> string * string =
  "ml_string_string_of_ptr"

external store_ptr_bool : ptr -> bool -> unit = "ml_store_ptr_bool"

external obj_of_ptr : ptr -> obj = "ml_obj_of_ptr"

external float_of_ptr : ptr -> float = "ml_float_of_ptr"

external color_argb_premul : int -> int -> int -> int -> int * int * int =
  "ml_evas_color_argb_premul"

