type t = Ecore.timer

external add : float -> Ecore.task_cb -> Ecore.timer = "ml_ecore_timer_add"

external delay : t -> float -> unit = "ml_ecore_timer_delay"

