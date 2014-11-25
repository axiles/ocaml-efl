(** Useful functions for OCaml EFL *)

val question_box :
  title:string -> buttons:string list -> ?default:int -> ?icon:Evas.obj ->
    ?parent:Evas.obj -> string -> (int -> unit) -> unit

val message_box :
  title:string -> ?icon:Evas.obj -> ?ok:string -> ?parent:Evas.obj -> string ->
    (unit -> unit) -> unit

val input_string :
  title:string -> ?ok:string -> ?cancel:string -> ?default_text:string ->
    ?parent:Evas.obj -> string -> (string option -> unit) -> unit

val input_text :
  title:string -> ?ok:string -> ?cancel:string -> ?default_text:string ->
    ?parent:Evas.obj -> string -> (string option -> unit) -> unit

