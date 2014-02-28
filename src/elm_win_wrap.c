#include "include.h"

inline Elm_Win_Type Elm_Win_Type_val(value v_ty)
{
        switch(v_ty) {
                case Val_basic: return ELM_WIN_BASIC;
                case Val_dialog_basic: return ELM_WIN_DIALOG_BASIC;
                case Val_desktop: return ELM_WIN_DESKTOP;
                case Val_dock: return ELM_WIN_DOCK;
                case Val_toolbar: return ELM_WIN_TOOLBAR;
                case Val_menu: return ELM_WIN_MENU;
                case Val_utility: return ELM_WIN_UTILITY;
                case Val_splash: return ELM_WIN_SPLASH;
                case Val_dropdown_menu: return ELM_WIN_DROPDOWN_MENU;
                case Val_popup_menu: return ELM_WIN_POPUP_MENU;
                case Val_tooltip: return ELM_WIN_TOOLTIP;
                case Val_notification: return ELM_WIN_NOTIFICATION;
                case Val_combo: return ELM_WIN_COMBO;
                case Val_dnd: return ELM_WIN_DND;
                case Val_inlined_image: return ELM_WIN_INLINED_IMAGE;
                case Val_socket_image: return ELM_WIN_SOCKET_IMAGE;
                default: return Val_unknown;
        }
        caml_failwith("Elm_Win_Type_val");
        return ELM_WIN_BASIC;
}

inline value Val_Elm_Win_Type(Elm_Win_Type ty)
{
        switch(ty) {
                case ELM_WIN_UNKNOWN: return Val_unknown;
                case ELM_WIN_BASIC: return Val_basic;
                case ELM_WIN_DIALOG_BASIC: return Val_dialog_basic;
                case ELM_WIN_DESKTOP: return Val_desktop;
                case ELM_WIN_DOCK: return Val_dock;
                case ELM_WIN_TOOLBAR: return Val_toolbar;
                case ELM_WIN_MENU: return Val_menu;
                case ELM_WIN_UTILITY: return Val_utility;
                case ELM_WIN_SPLASH: return Val_splash;
                case ELM_WIN_DROPDOWN_MENU: return Val_dropdown_menu;
                case ELM_WIN_POPUP_MENU: return Val_popup_menu;
                case ELM_WIN_TOOLTIP: return Val_tooltip;
                case ELM_WIN_NOTIFICATION: return Val_notification;
                case ELM_WIN_COMBO: return Val_combo;
                case ELM_WIN_DND: return Val_dnd;
                case ELM_WIN_INLINED_IMAGE: return Val_inlined_image;
                case ELM_WIN_SOCKET_IMAGE: return Val_socket_image;
        }
        caml_failwith("Val_Elm_Win_Type");
        return Val_basic;
}

inline Elm_Win_Keyboard_Mode Elm_Win_Keyboard_Mode_val(value v_mode)
{
        switch(v_mode) {
                case Val_unknown: return ELM_WIN_KEYBOARD_UNKNOWN;
                case Val_off: return ELM_WIN_KEYBOARD_OFF;
                case Val_on: return ELM_WIN_KEYBOARD_ON;
                case Val_alpha: return ELM_WIN_KEYBOARD_ALPHA;
                case Val_numeric: return ELM_WIN_KEYBOARD_NUMERIC;
                case Val_pin: return ELM_WIN_KEYBOARD_PIN;
                case Val_phone_number: return ELM_WIN_KEYBOARD_PHONE_NUMBER;
                case Val_hex: return ELM_WIN_KEYBOARD_HEX;
                case Val_terminal: return ELM_WIN_KEYBOARD_TERMINAL;
                case Val_password: return ELM_WIN_KEYBOARD_PASSWORD;
                case Val_ip: return ELM_WIN_KEYBOARD_IP;
                case Val_host: return ELM_WIN_KEYBOARD_HOST;
                case Val_file: return ELM_WIN_KEYBOARD_FILE;
                case Val_url: return ELM_WIN_KEYBOARD_URL;
                case Val_keypad: return ELM_WIN_KEYBOARD_KEYPAD;
                case Val_j2me: return ELM_WIN_KEYBOARD_J2ME;
        }
        caml_failwith("Elm_Win_Keyboard_Mode");
        return ELM_WIN_KEYBOARD_UNKNOWN;
}

inline value Val_Elm_Win_Keyboard_Mode(Elm_Win_Keyboard_Mode mode)
{
        switch(mode) {
                case ELM_WIN_KEYBOARD_UNKNOWN: return Val_unknown;
                case ELM_WIN_KEYBOARD_OFF: return Val_off;
                case ELM_WIN_KEYBOARD_ON: return Val_on;
                case ELM_WIN_KEYBOARD_ALPHA: return Val_alpha;
                case ELM_WIN_KEYBOARD_NUMERIC: return Val_numeric;
                case ELM_WIN_KEYBOARD_PIN: return Val_pin;
                case ELM_WIN_KEYBOARD_PHONE_NUMBER: return Val_phone_number;
                case ELM_WIN_KEYBOARD_HEX: return Val_hex;
                case ELM_WIN_KEYBOARD_TERMINAL: return Val_terminal;
                case ELM_WIN_KEYBOARD_PASSWORD: return Val_password;
                case ELM_WIN_KEYBOARD_IP: return Val_ip;
                case ELM_WIN_KEYBOARD_HOST: return Val_host;
                case ELM_WIN_KEYBOARD_FILE: return Val_file;
                case ELM_WIN_KEYBOARD_URL: return Val_url;
                case ELM_WIN_KEYBOARD_KEYPAD: return Val_keypad;
                case ELM_WIN_KEYBOARD_J2ME: return Val_j2me;
        }
        caml_failwith("Val_Elm_Win_Keyboard_Mode");
        return Val_unknown;
}

inline Elm_Win_Indicator_Mode Elm_Win_Indicator_Mode_val(value v_mode)
{
        switch(v_mode) {
                case Val_unknown: return ELM_WIN_INDICATOR_UNKNOWN;
                case Val_hide: return ELM_WIN_INDICATOR_HIDE;
                case Val_show: return ELM_WIN_INDICATOR_SHOW;
        }
        caml_failwith("Elm_Win_Indicator_Mode_val");
        return ELM_WIN_INDICATOR_UNKNOWN;
}

inline value Val_Elm_Win_Indicator_Mode(Elm_Win_Indicator_Mode mode)
{
        switch(mode) {
                case ELM_WIN_INDICATOR_UNKNOWN: return Val_unknown;
                case ELM_WIN_INDICATOR_HIDE: return Val_hide;
                case ELM_WIN_INDICATOR_SHOW: return Val_show;
        }
        caml_failwith("Val_Elm_Indicator_Mode");
        return Val_unknown;
}

inline Elm_Win_Indicator_Opacity_Mode
Elm_Win_Indicator_Opacity_Mode_val(value v_mode)
{
        switch(v_mode) {
                case Val_opacity_unknown:
                        return ELM_WIN_INDICATOR_OPACITY_UNKNOWN;
                case Val_opaque: return ELM_WIN_INDICATOR_OPAQUE;
                case Val_translucent: return ELM_WIN_INDICATOR_TRANSLUCENT;
                case Val_transparent: return ELM_WIN_INDICATOR_TRANSPARENT;
        }
        caml_failwith("Elm_Win_Indicator_Opacity_Mode");
        return ELM_WIN_INDICATOR_OPACITY_UNKNOWN;
}

inline value
Val_Elm_Win_Indicator_Opacity_Mode(Elm_Win_Indicator_Opacity_Mode mode)
{
        switch(mode) {
                case ELM_WIN_INDICATOR_OPACITY_UNKNOWN:
                        return Val_opacity_unknown;
                case ELM_WIN_INDICATOR_OPAQUE: return Val_opaque;
                case ELM_WIN_INDICATOR_TRANSLUCENT: return Val_translucent;
                case ELM_WIN_INDICATOR_TRANSPARENT: return Val_transparent;
        }
        caml_failwith("Val_Elm_Win_Indicator_Opacity_Mode");
}

inline Elm_Illume_Command Elm_Illume_Command_val(value v_c)
{
        switch(v_c) {
                case Val_focus_back: return ELM_ILLUME_COMMAND_FOCUS_BACK;
                case Val_focus_forward: return ELM_ILLUME_COMMAND_FOCUS_FORWARD;
                case Val_focus_home: return ELM_ILLUME_COMMAND_FOCUS_HOME;
                case Val_close: return ELM_ILLUME_COMMAND_CLOSE;
        }
        caml_failwith("Elm_Illume_Command_val");
        return ELM_ILLUME_COMMAND_FOCUS_BACK;
}

PREFIX value ml_elm_win_add(value v_parent, value v_name, value v_ty)
{
        Evas_Object* parent;
        if(v_parent == Val_int(0)) parent = NULL;
        else parent = (Evas_Object*) Field(v_parent, 0);
        Evas_Object* win = elm_win_add(parent, String_val(v_name),
                Elm_Win_Type_val(v_ty));
        if(win == NULL) caml_failwith("elm_win_add");
        return (value) win;
}

PREFIX value ml_elm_win_type_get(value v_obj)
{
        return Val_Elm_Win_Type(elm_win_type_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_util_standard_add(value v_name, value v_title)
{
        Evas_Object* obj = elm_win_util_standard_add(String_val(v_name),
                String_val(v_title));
        if(obj == NULL) caml_failwith("elm_win_util_standard_add");
        return (value) obj;
}

PREFIX value ml_elm_win_resize_object_add(value v_obj, value v_subobj)
{
        elm_win_resize_object_add((Evas_Object*) v_obj,
                (Evas_Object*) v_subobj);
        return Val_unit;
}

PREFIX value ml_elm_win_resize_object_del(value v_obj, value v_subobj)
{
        elm_win_resize_object_del((Evas_Object*) v_obj,
                (Evas_Object*) v_subobj);
        return Val_unit;
}

PREFIX value ml_elm_win_title_set(value v_obj, value v_title)
{
        elm_win_title_set((Evas_Object*) v_obj, String_val(v_title));
        return Val_unit;
}

PREFIX value ml_elm_win_title_get(value v_obj)
{
        return copy_string(elm_win_title_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_icon_name_set(value v_obj, value v_name)
{
        elm_win_icon_name_set((Evas_Object*) v_obj, String_val(v_name));
        return Val_unit;
}

PREFIX value ml_elm_win_icon_name_get(value v_obj)
{
        return copy_string(elm_win_icon_name_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_role_set(value v_obj, value v_role)
{
        elm_win_role_set((Evas_Object*) v_obj, String_val(v_role));
        return Val_unit;
}

PREFIX value ml_elm_win_role_get(value v_obj)
{
        return copy_string(elm_win_role_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_icon_object_set(value v_obj, value v_icon)
{
        elm_win_icon_object_set((Evas_Object*) v_obj, (Evas_Object*) v_icon);
        return Val_unit;
}

PREFIX value ml_elm_win_icon_object_get(value v_obj)
{
        return (value) elm_win_icon_object_get((Evas_Object*) v_obj);
}

PREFIX value ml_elm_win_autodel_set(value v_win, value v_flag)
{
        elm_win_autodel_set((Evas_Object*) v_win, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_autodel_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_autodel_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_activate(value v_obj)
{
        elm_win_activate((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_win_lower(value v_obj)
{
        elm_win_lower((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_win_raise(value v_obj)
{
        elm_win_raise((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_win_center(value v_obj, value v_h, value v_v)
{
        elm_win_center((Evas_Object*) v_obj, Eina_Bool_val(v_h),
                Eina_Bool_val(v_v));
        return Val_unit;
}

PREFIX value ml_elm_win_borderless_set(value v_obj, value v_flag)
{
        elm_win_borderless_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_borderless_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_borderless_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_shaped_set(value v_obj, value v_flag)
{
        elm_win_shaped_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_shaped_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_shaped_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_alpha_set(value v_obj, value v_flag)
{
        elm_win_alpha_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_alpha_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_alpha_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_override_set(value v_obj, value v_flag)
{
        elm_win_override_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_override_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_override_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_fullscreen_set(value v_obj, value v_flag)
{
        elm_win_fullscreen_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_fullscreen_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_fullscreen_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_main_menu_get(value v_obj)
{
        return copy_Evas_Object_opt(elm_win_main_menu_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_maximized_set(value v_obj, value v_flag)
{
        elm_win_maximized_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_maximized_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_maximized_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_iconified_set(value v_obj, value v_flag)
{
        elm_win_iconified_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_iconified_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_iconified_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_withdrawn_set(value v_obj, value v_flag)
{
        elm_win_withdrawn_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_withdrawn_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_withdrawn_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_available_profiles_set(value v_obj, value v_profiles)
{
        int size = Wosize_val(v_profiles);
        char* profiles[size];
        int i;
        for(i = 0; i < size; i++) {
                profiles[i] = String_val(Field(v_profiles, i));
        }
        elm_win_available_profiles_set((Evas_Object*) v_obj, (const char**) profiles, size);
        return Val_unit;
}

PREFIX value ml_elm_win_available_profiles_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_profiles);
        unsigned int size;
        char** profiles;
        if(!elm_win_available_profiles_get((Evas_Object*) v_obj, &profiles,
                &size))
                size = 0;
        v_profiles = caml_alloc(size, 0);
        unsigned int i;
        for(i = 0; i < size; i++) {
                Store_field(v_profiles, i, copy_string(profiles[i]));
        }
        CAMLreturn(v_profiles);
}

PREFIX value ml_elm_win_profile_set(value v_obj, value v_profile)
{
        elm_win_profile_set((Evas_Object*) v_obj, String_val(v_profile));
        return Val_unit;
}

PREFIX value ml_elm_win_profile_get(value v_obj)
{
        const char* profile = elm_win_profile_get((Evas_Object*) v_obj);
        if(profile == NULL) profile = "";
        return copy_string(profile);
}

PREFIX value ml_elm_win_urgent_set(value v_obj, value v_flag)
{
        elm_win_urgent_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_urgent_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_urgent_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_demand_attention_set(value v_obj, value v_flag)
{
        elm_win_demand_attention_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_demand_attention_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_demand_attention_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_modal_set(value v_obj, value v_flag)
{
        elm_win_modal_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_modal_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_modal_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_aspect_set(value v_obj, value v_r)
{
        elm_win_aspect_set((Evas_Object*) v_obj, Double_val(v_r));
        return Val_unit;
}

PREFIX value ml_elm_win_aspect_get(value v_obj)
{
        return copy_double(elm_win_aspect_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_size_base_set(value v_obj, value v_w, value v_h)
{
        elm_win_size_base_set((Evas_Object*) v_obj, Int_val(v_w), Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_elm_win_size_base_get(value v_obj)
{
        int w, h;
        elm_win_size_base_get((Evas_Object*) v_obj, &w, &h);
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_int(w));
        Store_field(v, 1, Val_int(h));
        return v;
}

PREFIX value ml_elm_win_size_step_set(value v_obj, value v_w, value v_h)
{
        elm_win_size_step_set((Evas_Object*) v_obj, Int_val(v_w), Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_elm_win_size_step_get(value v_obj)
{
        int w, h;
        elm_win_size_step_get((Evas_Object*) v_obj, &w, &h);
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_int(w));
        Store_field(v, 1, Val_int(h));
        return v;
}

PREFIX value ml_elm_win_layer_set(value v_obj, value v_n)
{
        elm_win_layer_set((Evas_Object*) v_obj, Int_val(v_n));
        return Val_unit;
}

PREFIX value ml_elm_win_layer_get(value v_obj)
{
        return Val_int(elm_win_layer_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_norender_push(value v_obj)
{
        elm_win_norender_push((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_win_norender_pop(value v_obj)
{
        elm_win_norender_pop((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_win_norender_get(value v_obj)
{
        return Val_int(elm_win_norender_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_render(value v_obj)
{
        elm_win_render((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_win_rotation_set(value v_obj, value v_rot)
{
        elm_win_rotation_set((Evas_Object*) v_obj, Int_val(v_rot));
        return Val_unit;
}

PREFIX value ml_elm_win_rotation_with_resize_set(value v_obj, value v_rot)
{
        elm_win_rotation_with_resize_set((Evas_Object*) v_obj, Int_val(v_rot));
        return Val_unit;
}

PREFIX value ml_elm_win_rotation_get(value v_obj)
{
        return Val_int(elm_win_rotation_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_sticky_set(value v_obj, value v_flag)
{
        elm_win_sticky_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_sticky_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_sticky_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_conformant_set(value v_obj, value v_flag)
{
        elm_win_conformant_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_conformant_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_conformant_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_quickpanel_set(value v_obj, value v_flag)
{
        elm_win_quickpanel_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_quickpanel_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_quickpanel_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_quickpanel_priority_major_set(value v_obj, value v_n)
{
        elm_win_quickpanel_priority_major_set((Evas_Object*) v_obj,
                Int_val(v_n));
        return Val_unit;
}

PREFIX value ml_elm_win_quickpanel_priority_major_get(value v_obj)
{
        return Val_int(elm_win_quickpanel_priority_major_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_quickpanel_priority_minor_set(value v_obj, value v_n)
{
        elm_win_quickpanel_priority_minor_set((Evas_Object*) v_obj,
                Int_val(v_n));
        return Val_unit;
}

PREFIX value ml_elm_win_quickpanel_priority_minor_get(value v_obj)
{
        return Val_int(elm_win_quickpanel_priority_minor_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_quickpanel_zone_set(value v_obj, value v_n)
{
        elm_win_quickpanel_zone_set((Evas_Object*) v_obj, Int_val(v_n));
        return Val_unit;
}

PREFIX value ml_elm_win_quickpanel_zone_get(value v_obj)
{
        return Val_int(elm_win_quickpanel_zone_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_prop_focus_skip_set(value v_obj, value v_flag)
{
        elm_win_prop_focus_skip_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_illume_command_send(value v_obj, value v_cmd)
{
        elm_win_illume_command_send((Evas_Object*) v_obj,
                Elm_Illume_Command_val(v_cmd), NULL);
        return Val_unit;
}

PREFIX value ml_elm_win_inlined_image_object_get(value v_obj)
{
        Evas_Object* obj = elm_win_inlined_image_object_get(
                (Evas_Object*) v_obj);
        if(obj == NULL) caml_failwith("elm_win_inlined_image_object_get");
        return (value) obj;
}

PREFIX value ml_elm_win_focus_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_focus_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_screen_constrain_set(value v_obj, value v_flag)
{
        elm_win_screen_constrain_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_screen_constrain_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_screen_constrain_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_screen_size_get(value v_obj)
{
        int x, y, w, h;
        elm_win_screen_size_get((Evas_Object*) v_obj, &x, &y, &w, &h);
        value v = caml_alloc(4, 0);
        Store_field(v, 0, Val_int(x));
        Store_field(v, 1, Val_int(y));
        Store_field(v, 2, Val_int(w));
        Store_field(v, 3, Val_int(h));
        return v;
}

PREFIX value ml_elm_win_screen_dpi_get(value v_obj)
{
        int x, y;
        elm_win_screen_dpi_get((Evas_Object*) v_obj, &x, &y);
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_int(x));
        Store_field(v, 1, Val_int(y));
        return v;
}

PREFIX value ml_elm_win_focus_highlight_enabled_set(value v_obj, value v_flag)
{
        elm_win_focus_highlight_enabled_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_focus_highlight_enabled_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_focus_highlight_enabled_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_focus_highlight_style_set(value v_obj, value v_s)
{
        const char* style;
        if(v_s == Val_int(0)) style = NULL;
        else style = String_val(Field(v_s, 0));
        elm_win_focus_highlight_style_set((Evas_Object*) v_obj, style);
        return Val_unit;
}

PREFIX value ml_elm_win_focus_highlight_style_get(value v_obj)
{
        CAMLparam0();
        CAMLlocal1(v);
        const char* style = elm_win_focus_highlight_style_get(
                (Evas_Object*) v_obj);
        if(style == NULL) v = Val_int(0);
        else {
                v = caml_alloc(1, 0);
                Store_field(v, 0, copy_string(style));
        }
        CAMLreturn(v);
}

PREFIX value ml_elm_win_focus_highlight_animate_set(value v_obj, value v_flag)
{
        elm_win_focus_highlight_animate_set((Evas_Object*) v_obj,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_focus_highlight_animate_get(value v_obj)
{
        return Val_bool(elm_win_focus_highlight_animate_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_keyboard_mode_set(value v_obj, value v_m)
{
        elm_win_keyboard_mode_set((Evas_Object*) v_obj,
                Elm_Win_Keyboard_Mode_val(v_m));
        return Val_unit;
}

PREFIX value ml_elm_win_keyboard_mode_get(value v_obj)
{
        return Val_Elm_Win_Keyboard_Mode(elm_win_keyboard_mode_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_keyboard_win_set(value v_obj, value v_flag)
{
        elm_win_keyboard_win_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_keyboard_win_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_keyboard_win_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_indicator_mode_set(value v_obj, value v_m)
{
        elm_win_indicator_mode_set((Evas_Object*) v_obj,
                Elm_Win_Indicator_Mode_val(v_m));
        return Val_unit;
}

PREFIX value ml_elm_win_indicator_mode_get(value v_obj)
{
        return Val_Elm_Win_Indicator_Mode(elm_win_indicator_mode_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_indicator_opacity_set(value v_obj, value v_m)
{
        elm_win_indicator_opacity_set((Evas_Object*) v_obj,
                Elm_Win_Indicator_Opacity_Mode_val(v_m));
        return Val_unit;
}

PREFIX value ml_elm_win_indicator_opacity_get(value v_obj)
{
        return Val_Elm_Win_Indicator_Opacity_Mode(elm_win_indicator_opacity_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_screen_position_get(value v_obj)
{
        int x, y;
        elm_win_screen_position_get((Evas_Object*) v_obj, &x, &y);
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_int(x));
        Store_field(v, 1, Val_int(y));
        return v;
}

PREFIX value ml_elm_win_socket_listen(
        value v_obj, value v_name, value v_num, value v_sys)
{
        return Val_Eina_Bool(elm_win_socket_listen((Evas_Object*) v_obj,
                String_val(v_name), Int_val(v_num), Eina_Bool_val(v_sys)));
}

PREFIX value ml_elm_win_xwindow_get(value v_obj)
{
        Ecore_X_Window win = elm_win_xwindow_get((Evas_Object*) v_obj);
        if(win == 0) raise_not_X();
        return Val_int(win);
}

PREFIX value ml_elm_win_wl_window_get(value v_obj)
{
        Ecore_Wl_Window* win = elm_win_wl_window_get((Evas_Object*) v_obj);
        if(win == NULL) raise_not_Wayland();
        return (value) win;
}

PREFIX value ml_elm_win_floating_mode_set(value v_obj, value v_flag)
{
        elm_win_floating_mode_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_floating_mode_get(value v_obj)
{
        return Val_bool(elm_win_floating_mode_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_window_id_get(value v_obj)
{
        return (value) elm_win_window_id_get((Evas_Object*) v_obj);
}

