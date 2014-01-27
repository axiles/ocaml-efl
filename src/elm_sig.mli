type u = Evas.Event_type.u
  
type 'a v = 'a Evas.Event_type.v

type 'a r = 'a Evas.Event_type.r

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
val animate_begin : u
val animate_done : u
val block_clicked : u
val changed : u
val changed__item : Elm_object.item v
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
val delay_changed__item : Elm_object.item v
val delete_request : u
val directory_open : string v
val dismissed : u
val _done : (string option) v
val download_request : Elm_web.download v
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
val editorclient_contents_changed : u
val editorclient_selection_changed : u
val expanded : Elm_object.item v
val expand_request : Elm_object.item v
val file_chosen : (string option) v
val focused : u
val frame_created : Evas.obj v
val fullscreen : u
val generate_error : u
val generate_start : u
val generate_stop : u
val hbar_drag : u
val hbar_press : u
val hbar_unpress : u
val highlighted : u
val highlighted__item : Elm_object.item v
val icon_received : u
val iconified : u
val index_update : u
val indicator_prop_changed : u
val inputmethod_changed : bool v
val ioerr : u
val js_windowobject_clear : u
val language_changed : u
val level_down : u
val level_up : u
val link_hover_in : (string * string) v
val link_hover_out : u
val load_document_finished : Evas.obj v
val load_error : u
val load_error__frame : Elm_web.frame_load_error v
val load_finished : u
val load_newwindow_show : u
val load_progress : float v
val load_provisional : u
val load_started : u
val loaded : u
val longpressed : u
val maximized : u
val menubar_visible_get : bool r
val menubar_visible_set : bool v
val moved : u
val moved_after : Elm_object.item v
val moved_before : Elm_object.item v
val multi_swipe_down : u
val multi_swipe_left : u
val multi_swipe_right : u
val multi_swipe_up : u
val multi_pinch_in : u
val multi_pinch_out : u
val name_load : u
val name_loaded : u
val name_loaded_fail : u
val normal : u
val overflowed : u
val overlay_clicked : u
val popup_created : Elm_web.menu v
val popup_willdelete : Elm_web.menu v
val pos_changed : (string option) v
val preedit_changed : u
val press : u
val pressed : u
val pressed__item : Elm_object.item v
val profile_changed : u
val ready : u
val realized : Elm_object.item v
val repeated : u
val released : Elm_object.item v
val rotation_changed : u
val route_load : u
val route_loaded : u
val route_loaded_fail : u
val scroll : u
val scroll_anim_start : u
val scroll_anim_stop : u
val scroll_drag_start : u
val scroll_drag_stop : u
val scroll_down : u
val scroll_left : u
val scroll_page_changed : u
val scroll_right : u
val scroll_up : u
val scrollbars_visible_get : bool r
val scrollbars_visible_set : bool v
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
val spinner_drag_start : u
val spinner_drag_stop : u
val slide_end : u
val slider_drag_start : u
val slider_drag_stop : u
val statusbar_text_set : string v
val statusbar_visible_get : bool r
val statusbar_visible_set : bool v
val stick : u
val swipe : u
val text_set_done : u
val theme_changed : u
val thumb_done : u
val thumb_error : u
val tile_load : u
val tile_loaded : u
val tile_loaded_fail : u
val timeout : u
val title_changed : string v
val toolbars_visible_get : bool r
val toolbars_visible_set : bool v
val tooltip_text_set : string v
val transition_finished : u
val tree_effect_finished : u
val underflowed : u
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
val url_changed : string v
val vbar_drag : u
val vbar_press : u
val vbar_unpress : u
val view_resized : u
val virtualkeypad_state_off : u
val virtualkeypad_state_on : u
val windows_close_request : u
val withdrawn : u
val zoom_animated_end : u
val zoom_change : u
val zoom_start : u
val zoom_stop : u

