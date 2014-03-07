(** Useful functions for OCaml EFL *)

val question_box :
  title:string -> buttons:string list -> ?default:int -> ?icon:Evas.obj ->
    ?parent:Evas.obj -> string -> (int -> unit) -> unit

