open Efl

let advance_frame obj pos =
  let frame = Ecore_animator.pos_map pos `spring 1.2 15. in
  let x = int_of_float (50. *. (1. +. frame)) in
  let f y = int_of_float (255. *. y) in
  Evas_object.resize obj x x;
  Evas_object.color_set obj (f frame) 0 (f (1. -. frame)) 255;
  true

let advance_frame3 obj =
  let x = ref 0 in
  fun () ->
    if !x >= 250 then x := 0;
    incr x;
    Evas_object.move obj !x 350;
    true
  
let advance_frame2 obj pos =
  let frame = Ecore_animator.pos_map pos `bounce 1.2 50. in
  let x = 100 - int_of_float (50. *. frame) in
  let y = int_of_float (100. *. (1. -. frame)) in
  let f z = int_of_float (255. *. z) in
  Evas_object.resize obj x x;
  Evas_object.move obj y y;
  Evas_object.color_set obj (f frame) 0 (f (1. -. frame)) 255;
  true
  
let start_second_anim obj () =
  Ecore_animator.frametime_set (1. /. 10.);
  ignore (Ecore_animator.timeline_add 20. (advance_frame2 obj));
  false

let freeze_third_anim anim () =
  Ecore_animator.freeze anim;
  false

let thaw_third_anim anim () =
  Ecore_animator.thaw anim;
  false

let () =
  Elm.init ();
  Elm.policy_quit_set `last_window_closed;
  let win = Elm_win.addx ~size:(300, 400) ~autodel:true "animators" in
  let evas = Evas_object.evas_get win in

  let rect = Evas_object.rectangle_add evas in
  Evas_object.color_set rect 0 0 255 255;
  Evas_object.resize rect 50 50;
  Evas_object.show rect;

  let rect2 = Evas_object.rectangle_add evas in
  Evas_object.color_set rect2 0 55 0 255;
  Evas_object.resize rect2 50 50;
  Evas_object.show rect2;

  Ecore_animator.frametime_set (1. /. 50.);
  ignore (Ecore_animator.timeline_add 5. (advance_frame rect));

  let anim = Ecore_animator.add (advance_frame3 rect2) in

  ignore (Ecore_timer.add 10. (start_second_anim rect));
  ignore (Ecore_timer.add 5. (freeze_third_anim anim));
  ignore (Ecore_timer.add 10. (thaw_third_anim anim));

  Evas_object.show win;
  Elm.run ();

  Ecore_animator.del anim;
  Elm.shutdown ()
  
