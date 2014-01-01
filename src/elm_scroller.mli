type policy = [`auto | `on | `off]

type single_direction = [`none | `soft | `hard | `last]

val add : Evas.obj -> Evas.obj

val content_min_limit : Evas.obj -> int -> int -> unit

val region_show : Evas.obj -> int -> int -> int -> int -> unit

val policy_set : Evas.obj -> policy -> policy -> unit

val policy_get : Evas.obj -> policy * policy

val single_direction_set : Evas.obj -> single_direction -> unit

val single_direction_get : Evas.obj -> single_direction

val region_get : Evas.obj -> int * int * int * int

val child_size_get : Evas.obj -> int * int

val page_snap_set : Evas.obj -> bool -> bool -> unit

val page_snap_get : Evas.obj -> bool * bool

val bounce_set : Evas.obj -> bool -> bool -> unit

val bounce_get : Evas.obj -> bool * bool

val page_relative_set : Evas.obj -> float -> float -> unit

val page_relative_get : Evas.obj -> float * float

val page_size_set : Evas.obj -> int -> int -> unit

val page_size_get : Evas.obj -> int * int

val current_page_get : Evas.obj -> int * int

val last_page_get : Evas.obj -> int * int

val page_show : Evas.obj -> int -> int -> unit

val page_bring_in : Evas.obj -> int -> int -> unit

val region_bring_in : Evas.obj -> int -> int -> int -> int -> unit

val propagate_events_set : Evas.obj -> bool -> unit

val propagate_events_get : Evas.obj -> bool

val gravity_set : Evas.obj -> float -> float -> unit

val gravity_get : Evas.obj -> float * float

module E : sig
  type u = Evas.Event_type.u
  val edge_left : u
  val edge_right : u
  val edge_top : u
  val edge_bottom : u
  val scroll : u
  val scroll_left : u
  val scroll_right : u
  val scroll_up : u
  val scroll_down : u
  val scroll_anim_start : u
  val scroll_anim_stop : u
  val scroll_drag_start : u
  val scroll_drag_stop : u
  val vbar_drag : u
  val vbar_press : u
  val vbar_unpress : u
  val hbar_drag : u
  val hbar_press : u
  val hbar_unpress : u
  val scroll_page_changed : u
  val focused : u
  val unfocused : u
end

