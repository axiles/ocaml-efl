open Efl

let render obj =
  GlClear.clear [`color];
  GlDraw.color (1., 0., 0.);
  GlDraw.begins `triangles;
  GlDraw.vertex2 (-0.5, -0.5);
  GlDraw.vertex2 (0.5, -0.5);
  GlDraw.vertex2 (0., 0.5);
  GlDraw.ends ();
  Elm_glview.changed_set obj

let () =
  Elm.init ();
  Elm.policy_quit_set `last_window_closed;
  let win = Elm_win.util_standard_add "glview" "GLView" in
  Elm_win.autodel_set win true;
  Evas_object.resize win 400 300;
  Evas_object.show win;

  let glview = Elm_glview.add win in
  Evas_object.size_hint_set glview [`expand];
  Elm_win.resize_object_add win glview;
  Evas_object.show glview;
  Elm_glview.render_func_set glview render;

  Elm.run ();
  Elm.shutdown ()

