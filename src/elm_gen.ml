type item_class = {
  item_style : string;
  func_text_get : Evas.obj -> string -> string;
  func_content_get : Evas.obj -> string -> Evas.obj option;
  func_state_get : Evas.obj -> string -> bool;
  func_del : Evas.obj -> unit;
  func_reusable_content_get : Evas.obj -> string -> Evas.obj -> Evas.obj option;
}

let item_class_create ~item_style ?(func_text_get = (fun obj part -> ""))
  ?(func_content_get = (fun obj part -> None))
  ?(func_state_get = (fun obj part -> true)) ?(func_del = (fun obj -> ()))
  ?(func_reusable_content_get = (fun obj part old -> Some old)) ()
=
  {item_style; func_text_get; func_content_get; func_state_get; func_del;
    func_reusable_content_get}

