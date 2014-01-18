type u = Evas.Event_type.u

type 'a v = 'a Evas.Event_type.v

let create_unit = Evas.Event_type.create_unit
  
let create_string x = Evas.Event_type.create x Evas.string_of_ptr

let create_string_opt x = Evas.Event_type.create x Evas.string_opt_of_ptr

let create_entry_anchor_info x =
  Evas.Event_type.create x Elm_entry.anchor_info_of_ptr
  
let create_item x = Evas.Event_type.create x Elm_object.item_of_ptr

let aborted = create_unit "aborted"
let activated = create_unit "activated"
let activated__item = create_item "activated"
let anchor_clicked = create_entry_anchor_info "anchor,clicked"
let anchor_down = create_entry_anchor_info "anchor,down"
let anchor_in = create_entry_anchor_info "anchor,in"
let anchor_out = create_entry_anchor_info "anchor,out"
let anchor_up = create_entry_anchor_info "anchor,up"
let block_clicked = create_unit "block,clicked"
let changed = create_unit "changed"
let changed_user = create_unit "changed_user"
let clicked = create_unit "clicked"
let clicked_double = create_unit "clicked,double"
let clicked_double__item = create_item "clicked_double"
let clicked_triple = create_unit "clicked,triple"
let clipboard_state_off = create_unit "clipboard,state,off"
let clipboard_state_on = create_unit "clipboard,state,on"
let contracted = create_item "contracted"
let contract_request = create_item "contract,request"
let cursor_changed = create_unit "cursor,changed"
let cursor_changed_manual = create_unit "cursor,changed,manual"
let delay_changed = create_unit "delay,changed"
let delete_request = create_unit "delete,request"
let directory_open = create_string "directory,open"
let dismissed = create_unit "dismissed"
let _done = create_string_opt "done"
let drag = create_unit "drag"
let drag_start_down = create_unit "drag,start,down"
let drag_start_left = create_unit "drag,start,left"
let drag_start_right = create_unit "drag,start,right"
let drag_start_up = create_unit "drag,start,up"
let drag_stop = create_unit "drag_stop"
let drop = create_string "drop"
let edge_bottom = create_unit "edge,bottom"
let edge_left = create_unit "edge,left"
let edge_right = create_unit "edge,right"
let edge_top = create_unit "edge,top"
let expanded = create_item "expanded"
let expand_request = create_item "expand,request"
let file_chosen = create_string_opt "file,chosen"
let focused = create_unit "focused"
let fullscreen = create_unit "fullscreen"
let hbar_drag = create_unit "hbar,drag"
let hbar_press = create_unit "hbar,press"
let hbar_unpress = create_unit "hbar,unpress"
let highlighted = create_unit "highlighted"
let highlighted__item = create_item "highlighted"
let iconified = create_unit "iconified"
let index_update = create_unit "index,update"
let indicator_prop_changed = create_unit "indicator,prop,changed"
let ioerr = create_unit "ioerr"
let language_changed = create_unit "language,changed"
let longpressed = create_unit "longpressed"
let maximized = create_unit "maximized"
let multi_swipe_down = create_unit "multi,swipe,down"
let multi_swipe_left = create_unit "multi,swipe,left"
let multi_swipe_right = create_unit "multi,swipe,right"
let multi_swipe_up = create_unit "multi,swipe,up"
let multi_pinch_out = create_unit "multi,pinch,out"
let multi_pinch_in = create_unit "multi,pinch,in"
let moved = create_unit "moved"
let moved_after = create_item "moved,after"
let moved_before = create_item "moved,before"
let normal = create_unit "normal"
let pos_changed = create_string_opt "pos_changed"
let preedit_changed = create_unit "preedit,changed"
let press = create_unit "press"
let pressed = create_unit "pressed"
let pressed__item = create_item "pressed"
let profile_changed = create_unit "profile,changed"
let realized = create_item "realized"
let released = create_item "released"
let repeated = create_unit "repeated"
let rotation_changed = create_unit "rotation,changed"
let scroll = create_unit "scroll"
let scroll_anim_start = create_unit "scroll,anim,start"
let scroll_anim_stop = create_unit "scroll,anim,stop"
let scroll_drag_start = create_unit "scroll,drag,start"
let scroll_drag_stop = create_unit "scroll,drag,stop"
let scroll_page_changed = create_unit "scroll,page,changed"
let selected = create_string_opt "selected"
let selected__item = create_item "selected"
let selected_invalid = create_unit "selected,invalid"
let selection_changed = create_unit "selection,changed"
let selection_cleared = create_unit "selection,cleared"
let selection_copy = create_unit "selection,copy"
let selection_cut = create_unit "selection,cut"
let selection_paste = create_unit "selection,paste"
let selection_start = create_unit "selection,start"
let slide_end = create_unit "slide,end"
let slider_drag_start = create_unit "slider,drag,start"
let slider_drag_stop = create_unit "slider,drag,stop"
let smart_changed = create_unit "smart,changed"
let stick = create_unit "stick"
let swipe = create_unit "swipe"
let text_set_done = create_unit "text,set,done"
let theme_changed = create_unit "theme,changed"
let thumb_done = create_unit "thumb,done"
let thumb_error = create_unit "thumb,error"
let timeout = create_unit "timeout"
let transition_finished = create_unit "transition,finished"
let tree_effect_finished = create_unit "tree,effect,finished"
let unfocused = create_unit "unfocused"
let unfullscreen = create_unit "unfullscreen"
let unhighlighted = create_unit "unhighlighted"
let unhighlighted__item = create_item "unhighlighted"
let unmaximized = create_unit "unmaximized"
let unrealized = create_unit "unrealized"
let unselected = create_unit "unselected"
let unselected__item = create_item "unselected"
let unpress = create_unit "unpress"
let unpressed = create_unit "unpressed"
let unstick = create_unit "unstick"
let vbar_drag = create_unit "vbar,drag"
let vbar_press = create_unit "vbar,press"
let vbar_unpress = create_unit "vbar,unpress"
let virtualkeypad_state_off = create_unit "virtualkeypad,state,off"
let virtualkeypad_state_on = create_unit "virtualkeypad,state,on"
let withdrawn = create_unit "widthdrawn"
