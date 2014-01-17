type t = Elm.theme

val _new : unit -> t

val free : t -> unit

val copy : t -> t -> unit

val ref_set : t -> t option -> unit

val ref_get : t -> t option

val default_get : unit -> t

val overlay_add : ?th:t -> string -> unit

val overlay_del : ?th:t -> string -> unit

val overlay_list_get : t -> string list

val extension_add : ?th:t -> string -> unit

val extension_del : ?th:t -> string -> unit

val extension_list_get : t -> string list

val set : ?th:t -> string -> unit

val get : ?th:t -> unit -> string

val list_get : ?th:t -> unit -> string list

val list_item_path_get : string -> (string * bool) option

val flush : ?th:t -> unit -> unit

val full_flush : unit -> unit

val name_available_list_get : unit -> string list

val data_get : ?th:t -> string -> string option

val group_path_find : ?th:t -> string -> string option

