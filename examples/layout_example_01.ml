open Efl
open Printf

let table = "example/table"
let box = "example/box"
let title = "example/title"
let swallow = "example/custom"

let box_buttons = ref 0


let tbl_btn_cb layout btn =
  let (_ : Evas.obj option) = Elm_layout.table_unpack layout table btn in
  Evas_object.del btn

let rec box_btn_cb layout btn =
  let buf = sprintf "Button %02d" !box_buttons in
  incr box_buttons;
  let parent = match Elm_object.parent_widget_get layout with
  | Some p -> p
  | None -> assert false in
  let item = Elm_button.add parent in
  Elm_object.text_set item buf;
  Evas_object.size_hint_weight_set item Evas.hint_expand Evas.hint_expand;
  Evas_object.size_hint_align_set item Evas.hint_fill Evas.hint_fill;
  let (_ : bool) = Elm_layout.box_insert_before layout box item btn in
  Evas_object_smart.callback_add item Elm_button.E.clicked
    (box_btn_cb layout);
  Evas_object.show item

let swallow_btn_cb layout btn =
  let (_ : bool) = Elm_layout.table_clear layout table true in
  let (_ : bool) = Elm_layout.box_remove_all layout box true in
  let item = Elm_object.part_content_unset layout ~p:swallow () in
  Evas_object.del item

module Item : sig
  type content = Standard of string | Text of string | No_content

  type pos = Pack of int * int * int * int | Insert | Prepend | Content
 
  type t = {
    fun_add : Evas.obj -> Evas.obj;
    content : content;
    fill : bool;
    pos : pos;
    cb : (Evas.obj -> Evas.obj -> unit) option;
  }

  val add : Evas.obj -> Evas.obj -> t -> unit

  val create_icon : string -> int -> int -> t

  val create_button :
    string -> bool -> pos -> (Evas.obj -> Evas.obj -> unit) -> t

end = struct
  type content = Standard of string | Text of string | No_content

  type pos = Pack of int * int * int * int | Insert | Prepend | Content

  type t = {
    fun_add : Evas.obj -> Evas.obj;
    content : content;
    fill : bool;
    pos : pos;
    cb : (Evas.obj -> Evas.obj -> unit) option;
  }

  let add win layout item =
    let obj = item.fun_add win in
    (match item.content with
    | Standard s -> let (_ : bool) = Elm_icon.standard_set obj s in ()
    | Text s -> Elm_object.text_set obj s
    | No_content -> ());
    if item.fill then (
      Evas_object.size_hint_weight_set obj Evas.hint_expand Evas.hint_expand;
      Evas_object.size_hint_align_set obj Evas.hint_fill Evas.hint_fill);
    (match item.pos with
    | Pack(x, y, w, h) ->
        let (_ : bool) = Elm_layout.table_pack layout table obj x y w h in ()
    | Insert ->
        let (_ : bool) = Elm_layout.box_insert_at layout box obj 0 in ()
    | Prepend -> let (_ : bool) = Elm_layout.box_prepend layout box obj in ()
    | Content -> Elm_object.part_content_set layout ~p:swallow obj);
    (match item.cb with
    | Some f -> Evas_object_smart.callback_add obj Elm_button.E.clicked
      (f layout)
    | None -> ());
    Evas_object.show obj

  let create_icon name x y =
    {fun_add = Elm_icon.add; content = Standard name; fill = true;
      pos = Pack(x, y, 1, 1); cb = None}

  let create_button text fill pos cb =
    {fun_add = Elm_button.add; content = Text text; fill; pos; cb = Some cb}

end

let () =
  Elm.init ();

  Elm_app.info_set "elementary" ~checkfile:"examples/layout_example.edj" ();
  let win = Elm_win.add "layout" `basic in
  Elm.policy_set `quit `last_window_closed;
  Elm_win.autodel_set win true;

  let bg = Elm_bg.add win in
  Elm_bg.color_set bg 255 255 255;
  Evas_object.size_hint_weight_set bg Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win bg;
  Evas_object.show bg;

  let layout = Elm_layout.add win in
  Evas_object.size_hint_weight_set layout Evas.hint_expand Evas.hint_expand;
  Elm_win.resize_object_add win layout;
  let buf =
    sprintf "%s/examples/layout_example.edj" (Elm_app.data_dir_get ()) in
  let (_ : bool) = Elm_layout.file_set layout buf "example/mylayout" in
  Evas_object.show layout;

  (match Elm_layout.data_get layout "title" with
  | Some s ->
      Elm_win.title_set win s;
      Elm_object.part_text_set layout ~p:title s
  | None -> ());

  let open Item in
  let icons_data = [("home", 0, 0); ("close", 1, 0)] in
  let btns_data = [
    ("Click me!", true, Pack(0, 1, 3, 1), tbl_btn_cb);
    ("Position 0", true, Insert,  box_btn_cb);
    ("Prepended", true, Prepend, box_btn_cb);
    ("Delete All", false, Content, swallow_btn_cb)] in
  let items =
    List.map (fun (a, b, c) -> create_icon a b c) icons_data @
    [{fun_add = Elm_clock.add; fill = true; pos = Pack(2, 0, 1, 1);
      content = No_content; cb = None}] @
    List.map (fun (a, b, c, d) -> create_button a b c d) btns_data in
  List.iter (add win layout) items;

  Evas_object.resize win 320 320;
  Evas_object.show win;

  Elm.run ();
  Elm.shutdown ();
