open Printf

let get_hash_value s =
  let open Int32 in
  let val_int x = logor (shift_left x 1) 1l in
  let int_val x = shift_right x 1 in
  let accu = ref (val_int 0l) in
  let aux c =
    accu := val_int (add (mul 223l (int_val !accu)) (of_int (int_of_char c))) in
  String.iter aux s;
  to_string !accu

let f x y = printf "#define %s %s\n" x (get_hash_value y)

let g x = f (sprintf "Val_%s" x) x

let () =
  g "after";
  g "before";
  g "canvas_focus_in";
  g "canvas_focus_out";
  g "canvas_object_focus_in";
  g "canvas_object_focus_out";
  g "changed_size_hints";
  g "del";
  g "device_changed";
  g "double_click";
  g "focus_in";
  g "focus_out";
  g "free";
  g "hold";
  g "image_preloaded";
  g "image_resize";
  g "image_unloaded";
  g "key_down";
  g "key_up";
  g "mouse_down";
  g "mouse_in";
  g "mouse_move";
  g "mouse_out";
  g "mouse_up";
  g "mouse_wheel";
  g "multi_down";
  g "multi_move";
  g "multi_up";
  g "on_hold";
  g "on_scroll";
  g "other";
  g "preloaded";
  g "render_flush_post";
  g "render_flush_pre";
  g "render_post";
  g "render_pre";
  g "resize";
  g "restack";
  g "triple_click";
  flush stdout
