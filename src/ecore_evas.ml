type t = Ecore.evas

external engines_get : unit -> string list = "ml_ecore_evas_engines_get"

external new_ :
  ?engine_name:string -> ?x:int -> ?y:int -> w:int -> h:int ->
    ?extra_option:string -> unit -> t =
        "ml_ecore_evas_new_byte" "ml_ecore_evas_new_native"

let create = new_

