(** Ecore Evas *)

type t = Ecore.evas

val engines_get : unit -> string list

val new_ :
  ?engine_name:string -> ?x:int -> ?y:int -> w:int -> h:int ->
    ?extra_option:string -> unit -> t

(** Same as function new_ *)
val create :
  ?engine_name:string -> ?x:int -> ?y:int -> w:int -> h:int ->
    ?extra_option:string -> unit -> t

