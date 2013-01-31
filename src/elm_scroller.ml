type policy = [`auto | `on | `off]

external bounce_set : Evas.obj -> bool -> bool -> unit =
  "ml_elm_scroller_bounce_set"

external policy_set : Evas.obj -> policy -> policy -> unit =
  "ml_elm_scroller_policy_set"

