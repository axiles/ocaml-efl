type day = [`sun | `mon | `tue | `wed | `thu | `fri | `sat | `max]

val add : Evas.obj -> Evas.obj

val day_selected_set : Evas.obj -> day -> bool -> unit

val day_selected_get : Evas.obj -> day -> bool

val week_start_set : Evas.obj -> day -> unit

val week_start_get : Evas.obj -> day

val weekend_start_set : Evas.obj -> day -> unit

val weekend_start_get : Evas.obj -> day

