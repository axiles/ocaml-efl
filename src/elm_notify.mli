(** elm_notify_* Elm_Notify_* *)

val add : Evas.obj -> Evas.obj

val parent_set : Evas.obj -> Evas.obj -> unit

val parent_get : Evas.obj -> Evas.obj

val align_set : Evas.obj -> float -> float -> unit

val align_get : Evas.obj -> float * float

val timeout_set : Evas.obj -> float -> unit

val timeout_get : Evas.obj -> float

val allow_events_set : Evas.obj -> bool -> unit

val allow_events_get : Evas.obj -> bool

module E : sig
  type u = Evas.Event_type.u
  val timeout : u
  val block_clicked : u
end

