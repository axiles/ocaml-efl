type t = Elm.theme

val _new : unit -> t

val free : t -> unit

val copy : t -> t -> unit

val list_item_path_get : string -> (string * bool) option

