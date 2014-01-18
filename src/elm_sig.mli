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
val clipboard_state_off : u
val clipboard_state_on : u
val contracted : Elm_object.item v
val contract_request : Elm_object.item v
val cursor_changed : u
val cursor_changed_manual : u
val delay_changed : u
val delete_request : u
val directory_open : string v
val dismissed : u
val _done : (string option) v
val drag : u
val drag_start_down : u
val drag_start_left : u
val drag_start_right : u
val drag_stop : u
val drag_start_up : u
val drop : string v
val edge_bottom : u
val edge_left : u
val edge_right : u
val edge_top : u
val expanded : Elm_object.item v
val expand_request : Elm_object.item v
val file_chosen : (string option) v
val focused : u
val fullscreen : u
val hbar_drag : u
val hbar_press : u
val hbar_unpress : u
val highlighted : u
val highlighted__item : Elm_object.item v
val iconified : u
val index_update : u
val indicator_prop_changed : u
val ioerr : u
val language_changed : u
val longpressed : u
val maximized : u
val moved : u
val moved_after : Elm_object.item v
val moved_before : Elm_object.item v
val multi_swipe_down : u
val multi_swipe_left : u
val multi_swipe_right : u
val multi_swipe_up : u
val multi_pinch_in : u
val multi_pinch_out : u
val normal : u
val pos_changed : (string option) v
val preedit_changed : u
val press : u
val pressed : u
val pressed__item : Elm_object.item v
val profile_changed : u
val realized : Elm_object.item v
val repeated : u
val released : Elm_object.item v
val rotation_changed : u
val scroll : u
val scroll_anim_start : u
val scroll_anim_stop : u
val scroll_drag_start : u
val scroll_drag_stop : u
val scroll_page_changed : u
val selected : (string option) v
val selected__item : Elm_object.item v
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
val swipe : u
val text_set_done : u
val theme_changed : u
val thumb_done : u
val thumb_error : u
val timeout : u
val transition_finished : u
val tree_effect_finished : u
val unfullscreen : u
val unfocused : u
val unhighlighted : u
val unhighlighted__item : Elm_object.item v
val unmaximized : u
val unpress : u
val unpressed : u
val unrealized : u
val unselected : u
val unselected__item : Elm_object.item v
val unstick : u
val vbar_drag : u
val vbar_press : u
val vbar_unpress : u
val virtualkeypad_state_off : u
val virtualkeypad_state_on : u
val withdrawn : u


