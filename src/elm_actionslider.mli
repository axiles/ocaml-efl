val add : Evas.obj -> Evas.obj

val selected_label_get : Evas.obj -> string option

val indicator_pos_set : Evas.obj -> bool -> bool -> bool -> unit

val indicator_pos_get : Evas.obj -> bool * bool * bool

val magnet_pos_set : Evas.obj -> bool -> bool -> bool -> unit

val magnet_pos_get : Evas.obj -> bool * bool * bool

val enabled_pos_set : Evas.obj -> bool -> bool -> bool -> unit

val enabled_pos_get : Evas.obj -> bool * bool * bool

module E : sig
  type u = Evas.Event_type.u
  type 'a v = 'a Evas.Event_type.v
  val selected : (string option) v
  val pos_changed : (string option) v
end

