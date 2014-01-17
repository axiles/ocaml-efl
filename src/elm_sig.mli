type u = Evas.Event_type.u
  
type 'a v = 'a Evas.Event_type.v

val create_unit : string -> u

val create_string_opt : string -> (string option) v

val aborted : u
val activated : u
val anchor_clicked : Elm_entry.anchor_info v
val anchor_down : Elm_entry.anchor_info v
val anchor_in : Elm_entry.anchor_info v
val anchor_out : Elm_entry.anchor_info v
val anchor_up : Elm_entry.anchor_info v
val changed : u
val changed_user : u
val clicked : u
val clicked_double : u
val clicked_triple : u
val cursor_changed : u
val cursor_changed_manual : u
val directory_open : string v
val _done : (string option) v
val file_chosen : (string option) v
val focused : u
val language_changed : u
val longpressed : u
val pos_changed : (string option) v
val preedit_changed : u
val press : u
val pressed : u
val repeated : u
val selected : (string option) v
val selected_invalid : u
val selection_changed : u
val selection_cleared : u
val selection_copy : u
val selection_cut : u
val selection_paste : u
val selection_start : u
val text_set_done : u
val unfocused : u
val unpressed : u


