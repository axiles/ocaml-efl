type u = Evas.Event_type.u
  
type 'a v = 'a Evas.Event_type.v

val create_unit : string -> u

val create_string_opt : string -> (string option) v

val aborted : u
val activated : u
val activated__item : Elm_object.item v
val anchor_clicked : Elm_entry.anchor_info v
val anchor_down : Elm_entry.anchor_info v
val anchor_in : Elm_entry.anchor_info v
val anchor_out : Elm_entry.anchor_info v
val anchor_up : Elm_entry.anchor_info v
val block_clicked : u
val changed : u
val changed_user : u
val clicked : u
val clicked_double : u
val clicked_double__item : Elm_object.item v
val clicked_triple : u
val cursor_changed : u
val cursor_changed_manual : u
val delay_changed : u
val delete_request : u
val directory_open : string v
val dismissed : u
val _done : (string option) v
val drop : string v
val edge_bottom : u
val edge_left : u
val edge_right : u
val edge_top : u
val file_chosen : (string option) v
val focused : u
val fullscreen : u
val highlighted : u
val iconified : u
val indicator_prop_changed : u
val ioerr : u
val language_changed : u
val longpressed : u
val maximized : u
val moved : u
val normal : u
val pos_changed : (string option) v
val preedit_changed : u
val press : u
val pressed : u
val profile_changed : u
val repeated : u
val rotation_changed : u
val selected : (string option) v
val selected_invalid : u
val selection_changed : u
val selection_cleared : u
val selection_copy : u
val selection_cut : u
val selection_paste : u
val selection_start : u
val smart_changed : u
val slide_end : u
val slider_drag_start : u
val slider_drag_stop : u
val stick : u
val text_set_done : u
val thumb_done : u
val thumb_error : u
val timeout : u
val unfullscreen : u
val unfocused : u
val unhighlighted : u
val unmaximized : u
val unpressed : u
val unselected : u
val unstick : u
val withdrawn : u


