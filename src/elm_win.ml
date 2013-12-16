type ty = [
  | `basic
  | `dialog_basic
  | `desktop
  | `dock
  | `toolbar
  | `menu
  | `utility
  | `splash
  | `dropdown_menu
  | `popup_menu
  | `tooltip
  | `notification
  | `combo
  | `dnd
  | `inlined_image
  | `socket_image]

type keyboard_mode = [
  | `unknown
  | `off
  | `on
  | `alpha
  | `numeric
  | `pin
  | `phone_number
  | `hex
  | `terminal
  | `password
  | `ip
  | `host
  | `file
  | `url
  | `keypad
  | `j2me]

type indicator_mode = [
  | `unknown
  | `hide
  | `show]

type indicator_opacity_mode = [
  | `opacity_unknown
  | `opaque
  | `translucent
  | `transparent]

type illume_command = Elm.illume_command

external add : ?p:Evas.obj -> string -> ty -> Evas.obj =
  "ml_elm_win_add"

external util_standard_add : string -> string -> Evas.obj =
  "ml_elm_win_util_standard_add"

external resize_object_add : Evas.obj -> Evas.obj -> unit =
  "ml_elm_win_resize_object_add"

external resize_object_del : Evas.obj -> Evas.obj -> unit =
  "ml_elm_win_resize_object_del"

external title_set : Evas.obj -> string -> unit = "ml_elm_win_title_set"

external title_get : Evas.obj -> string = "ml_elm_win_title_get"

external icon_name_set : Evas.obj -> string -> unit = "ml_elm_win_icon_name_set"

external icon_name_get : Evas.obj -> string = "ml_elm_win_icon_name_get"

external role_set : Evas.obj -> string -> unit = "ml_elm_win_role_set"

external role_get : Evas.obj -> string = "ml_elm_win_role_get"

external icon_object_set : Evas.obj -> Evas.obj -> unit =
  "ml_elm_win_icon_object_set"

external icon_object_get : Evas.obj -> Evas.obj = "ml_elm_win_icon_object_get"

external autodel_set : Evas.obj -> bool -> unit = "ml_elm_win_autodel_set"

external autodel_get : Evas.obj -> bool = "ml_elm_win_autodel_get"

external activate : Evas.obj -> unit = "ml_elm_win_activate"

external lower : Evas.obj -> unit = "ml_elm_win_lower"

external raises : Evas.obj -> unit = "ml_elm_win_raise"

external center : Evas.obj -> bool -> bool -> unit = "ml_elm_win_center"

external borderless_set : Evas.obj -> bool -> unit = "ml_elm_win_borderless_set"

external borderless_get : Evas.obj -> bool = "ml_elm_win_borderless_get"

external shaped_set : Evas.obj -> bool -> unit = "ml_elm_win_shaped_set"

external shaped_get : Evas.obj -> bool = "ml_elm_win_shaped_get"

external alpha_set : Evas.obj -> bool -> unit = "ml_elm_win_alpha_set"

external alpha_get : Evas.obj -> bool = "ml_elm_win_alpha_get"

external override_set : Evas.obj -> bool -> unit = "ml_elm_win_override_set"

external override_get : Evas.obj -> bool = "ml_elm_win_override_get"

external fullscreen_set : Evas.obj -> bool -> unit = "ml_elm_win_fullscreen_set"

external fullscreen_get : Evas.obj -> bool = "ml_elm_win_fullscreen_get"

external maximized_set : Evas.obj -> bool -> unit = "ml_elm_win_maximized_set"

external maximized_get : Evas.obj -> bool = "ml_elm_win_maximized_get"

external iconified_set : Evas.obj -> bool -> unit = "ml_elm_win_iconified_set"

external iconified_get : Evas.obj -> bool = "ml_elm_win_iconified_get"

external withdrawn_set : Evas.obj -> bool -> unit = "ml_elm_win_withdrawn_set"

external withdrawn_get : Evas.obj -> bool = "ml_elm_win_withdrawn_get"

external available_profiles_set : Evas.obj -> string array -> unit =
  "ml_elm_win_available_profiles_set"

external available_profiles_get : Evas.obj -> string array =
  "ml_elm_win_available_profiles_get"

external profile_set : Evas.obj -> string -> unit = "ml_elm_win_profile_set"

external profile_get : Evas.obj -> string = "ml_elm_win_profile_get"

external urgent_set : Evas.obj -> bool-> unit = "ml_elm_win_urgent_set"

external urgent_get : Evas.obj -> bool = "ml_elm_win_urgent_get"

external demand_attention_set : Evas.obj -> bool -> unit =
  "ml_elm_win_demand_attention_set"

external demand_attention_get : Evas.obj -> bool =
  "ml_elm_win_demand_attention_get"

external modal_set : Evas.obj -> bool -> unit = "ml_elm_win_modal_set"

external modal_get : Evas.obj -> bool = "ml_elm_win_modal_get"

external aspect_set : Evas.obj -> float -> unit = "ml_elm_win_aspect_set"

external aspect_get : Evas.obj -> float = "ml_elm_win_aspect_get"

external size_base_set : Evas.obj -> int -> int -> unit =
  "ml_elm_win_size_base_set"

external size_base_get : Evas.obj -> int * int = "ml_elm_win_size_base_get"

external size_step_set : Evas.obj -> int -> int -> unit =
  "ml_elm_win_size_step_set"

external size_step_get : Evas.obj -> int * int = "ml_elm_win_size_step_get"

external layer_set : Evas.obj -> int -> unit = "ml_elm_win_layer_set"

external layer_get : Evas.obj -> int = "ml_elm_win_layer_get"

external rotation_set : Evas.obj -> int -> unit = "ml_elm_win_rotation_set"

external rotation_with_resize_set : Evas.obj -> int -> unit =
  "ml_elm_win_rotation_with_resize_set"

external rotation_get : Evas.obj -> int = "ml_elm_win_rotation_get"

external sticky_set : Evas.obj -> bool -> unit = "ml_elm_win_sticky_set"

external sticky_get : Evas.obj -> bool = "ml_elm_win_sticky_get"

external conformant_set : Evas.obj -> bool -> unit = "ml_elm_win_conformant_set"

external conformant_get : Evas.obj -> bool = "ml_elm_win_conformant_get"

external quickpanel_set : Evas.obj -> bool -> unit = "ml_elm_win_quickpanel_set"

external quickpanel_get : Evas.obj -> bool = "ml_elm_win_quickpanel_get"

external quickpanel_priority_major_set : Evas.obj -> int -> unit =
  "ml_elm_win_quickpanel_priority_major_set"

external quickpanel_priority_major_get : Evas.obj -> int =
  "ml_elm_win_quickpanel_priority_major_get"

external quickpanel_priority_minor_set : Evas.obj -> int -> unit =
  "ml_elm_win_quickpanel_priority_minor_set"

external quickpanel_priority_minor_get : Evas.obj -> int =
  "ml_elm_win_quickpanel_priority_minor_get"

external quickpanel_zone_set : Evas.obj -> int -> unit =
  "ml_elm_win_quickpanel_zone_set"

external quickpanel_zone_get : Evas.obj -> int =
  "ml_elm_win_quickpanel_zone_get"

external prop_focus_skip_set : Evas.obj -> bool -> unit =
  "ml_elm_win_prop_focus_skip_set"

external illume_command_send : Evas.obj -> Elm.illume_command -> unit =
  "ml_elm_win_illume_command_send"
  
external inlined_image_object_get : Evas.obj -> Evas.obj =
  "ml_elm_win_inlined_image_object_get"

external focus_get : Evas.obj -> bool = "ml_elm_win_focus_get"

external screen_constrain_set : Evas.obj -> bool -> unit =
  "ml_elm_win_screen_constrain_set"

external screen_constrain_get : Evas.obj -> bool =
  "ml_elm_win_screen_constrain_get"

external screen_size_get : Evas.obj -> int * int * int * int =
  "ml_elm_win_screen_size_get"

external screen_dpi_get : Evas.obj -> int * int = "ml_elm_win_screen_dpi_get"

external focus_highlight_enabled_set : Evas.obj -> bool -> unit =
  "ml_elm_win_focus_highlight_enabled_set"

external focus_highlight_enabled_get : Evas.obj -> bool =
  "ml_elm_win_focus_highlight_enabled_get"

external focus_highlight_style_set : Evas.obj -> string option -> unit =
  "ml_elm_win_focus_highlight_style_set"

external focus_highlight_style_get : Evas.obj -> string option =
  "ml_elm_win_focus_highlight_style_get"

external keyboard_mode_set : Evas.obj -> keyboard_mode -> unit =
  "ml_elm_win_keyboard_mode_set"

external keyboard_mode_get : Evas.obj -> keyboard_mode =
  "ml_elm_win_keyboard_mode_get"

external keyboard_win_set : Evas.obj -> bool -> unit =
  "ml_elm_win_keyboard_win_set"

external keyboard_win_get : Evas.obj -> bool =
  "ml_elm_win_keyboard_win_get"

external indicator_mode_set : Evas.obj -> indicator_mode -> unit =
  "ml_elm_win_indicator_mode_set"

external indicator_mode_get : Evas.obj -> indicator_mode =
  "ml_elm_win_indicator_mode_get"

external indicator_opacity_set : Evas.obj -> indicator_opacity_mode -> unit =
  "ml_elm_win_indicator_opacity_set"

external indicator_opacity_get : Evas.obj -> indicator_opacity_mode =
  "ml_elm_win_indicator_opacity_get"

external screen_position_get : Evas.obj -> int * int =
  "ml_elm_win_screen_position_get"

external socket_listen : Evas.obj -> string -> int -> bool -> unit =
  "ml_elm_win_socket_listen"

external xwindow_get : Evas.obj -> Ecore.x_window = "ml_elm_win_xwindow_get"

external wl_window_get : Evas.obj -> Ecore.wl_window =
  "ml_elm_win_wl_window_get"

external floating_mode_set : Evas.obj -> bool -> unit =
  "ml_elm_win_floating_mode_set"

external floating_mode_get : Evas.obj -> bool = "ml_elm_win_floating_mode_get"

external window_id_get : Evas.obj -> Ecore.window = "ml_elm_win_window_id_get"

module E = struct
  type u = Evas.Event_type.u
  let f = Evas.Event_type.create_unit
  let delete_request = f "delete,request"
  let moved = f "moved"
  let withdrawn = f "widthdrawn"
  let iconified = f "iconified"
  let normal = f "normal"
  let stick = f "stick"
  let unstick = f "unstick"
  let fullscreen = f "fullscreen"
  let unfullscreen = f "unfullscreen"
  let maximized = f "maximized"
  let unmaximized = f "unmaximized"
  let ioerr = f "ioerr"
  let indicator_prop_changed = f "indicator,prop,changed"
  let rotation_changed = f "rotation,changed"
  let profile_changed = f "profile,changed"
  let focused = f "focused"
  let unfocused = f "unfocused"
end



