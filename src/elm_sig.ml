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
let changed = create_unit "changed"
let changed_user = create_unit "changed_user"
let clicked = create_unit "clicked"
let clicked_double = create_unit "clicked,double"
let clicked_double__item = create_item "clicked_double"
let clicked_triple = create_unit "clicked,triple"
let cursor_changed = create_unit "cursor,changed"
let cursor_changed_manual = create_unit "cursor,changed,manual"
let directory_open = create_string "directory,open"
let dismissed = create_unit "dismissed"
let _done = create_string_opt "done"
let drop = create_string "drop"
let edge_bottom = create_unit "edge,bottom"
let edge_left = create_unit "edge,left"
let edge_right = create_unit "edge,right"
let edge_top = create_unit "edge,top"
let file_chosen = create_string_opt "file,chosen"
let focused = create_unit "focused"
let highlighted = create_unit "highlighted"
let language_changed = create_unit "language,changed"
let longpressed = create_unit "longpressed"
let pos_changed = create_string_opt "pos_changed"
let preedit_changed = create_unit "preedit,changed"
let press = create_unit "press"
let pressed = create_unit "pressed"
let repeated = create_unit "repeated"
let selected = create_string_opt "selected"
let selected_invalid = create_unit "selected,invalid"
let selection_changed = create_unit "selection,changed"
let selection_cleared = create_unit "selection,cleared"
let selection_copy = create_unit "selection,copy"
let selection_cut = create_unit "selection,cut"
let selection_paste = create_unit "selection,paste"
let selection_start = create_unit "selection,start"
let smart_changed = create_unit "smart,changed"
let text_set_done = create_unit "text,set,done"
let thumb_done = create_unit "thumb,done"
let thumb_error = create_unit "thumb,error"
let unfocused = create_unit "unfocused"
let unhighlighted = create_unit "unhighlighted"
let unselected = create_unit "unselected"
let unpressed = create_unit "unpressed"

