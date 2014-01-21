type orient = [`top | `bottom | `left | `right]

external add : Evas.obj -> Evas.obj = "ml_elm_panel_add"

external orient_set : Evas.obj -> orient -> unit = "ml_elm_panel_orient_set"

external orient_get : Evas.obj -> orient = "ml_elm_panel_orient_get"

external hidden_set : Evas.obj -> bool -> unit = "ml_elm_panel_hidden_set"

external hidden_get : Evas.obj -> bool = "ml_elm_panel_hidden_get"

