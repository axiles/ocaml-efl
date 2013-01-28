type t = Ecore.timer

external add : float -> Ecore.task_cb -> Ecore.timer = "ml_ecore_timer_add"

