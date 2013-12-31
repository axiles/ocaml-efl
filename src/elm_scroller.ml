type policy = [`auto | `on | `off]

external add : Evas.obj -> Evas.obj = "ml_elm_scroller_add"

external content_min_limit : Evas.obj -> int -> int -> unit =
  "ml_elm_scroller_content_min_limit"

external region_show : Evas.obj -> int -> int -> int -> int -> unit =
  "ml_elm_scroller_region_show"

external policy_set : Evas.obj -> policy -> policy -> unit =
  "ml_elm_scroller_policy_set"

external policy_get : Evas.obj -> policy * policy = "ml_elm_scroller_policy_get"

external region_get : Evas.obj -> int * int * int * int =
  "ml_elm_scroller_region_get"

external child_size_get : Evas.obj -> int * int =
  "ml_elm_scroller_child_size_get"

external bounce_set : Evas.obj -> bool -> bool -> unit =
  "ml_elm_scroller_bounce_set"

external bounce_get : Evas.obj -> bool * bool = "ml_elm_scroller_bounce_get"

external page_relative_set : Evas.obj -> float -> float -> unit =
  "ml_elm_scroller_page_relative_set"

external page_relative_get : Evas.obj -> float * float =
  "ml_elm_scroller_page_relative_get"

