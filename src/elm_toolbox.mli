(** Useful functions for OCaml EFL *)

val question_box :
  title:string -> buttons:string list -> ?default:int -> ?icon:Evas.obj ->
    ?parent:Evas.obj -> string -> (int -> unit) -> unit

val message_box :
  title:string -> ?icon:Evas.obj -> ?ok:string -> ?parent:Evas.obj -> string ->
    (unit -> unit) -> unit

