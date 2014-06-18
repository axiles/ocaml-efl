#include "include.h"

PREFIX value ml_elm_config_cache_flush_interval_get(value v_unit)
{
        return Val_int(elm_config_cache_flush_interval_get());
}

PREFIX value ml_elm_config_cache_flush_interval_set(value v_x)
{
        elm_config_cache_flush_interval_set(Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_config_cache_flush_enabled_get(value v_unit)
{
        return Val_bool(elm_config_cache_flush_enabled_get());
}

PREFIX value ml_elm_config_cache_flush_enabled_set(value v_flag)
{
        elm_config_cache_flush_enabled_set(Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_config_cache_font_cache_size_get(value v_unit)
{
        return Val_int(elm_config_cache_font_cache_size_get());
}

PREFIX value ml_elm_config_cache_font_cache_size_set(value v_x)
{
        elm_config_cache_font_cache_size_set(Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_config_cache_image_cache_size_get(value v_unit)
{
        return Val_int(elm_config_cache_image_cache_size_get());
}

PREFIX value ml_elm_config_cache_image_cache_size_set(value v_x)
{
        elm_config_cache_image_cache_size_set(Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_config_cache_edje_file_cache_size_get(value v_unit)
{
        return Val_int(elm_config_cache_edje_file_cache_size_get());
}

PREFIX value ml_elm_config_cache_edje_file_cache_size_set(value v_x)
{
        elm_config_cache_edje_file_cache_size_set(Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_config_cache_edje_collection_cache_size_get(value v_unit)
{
        return Val_int(elm_config_cache_edje_collection_cache_size_get());
}

PREFIX value ml_elm_config_cache_edje_collection_cache_size_set(value v_x)
{
        elm_config_cache_edje_collection_cache_size_set(Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_config_cursor_engine_only_get(value v_unit)
{
        return Val_bool(elm_config_cursor_engine_only_get());
}

PREFIX value ml_elm_config_cursor_engine_only_set(value v_flag)
{
        elm_config_cursor_engine_only_set(Bool_val(v_flag));
        return Val_unit;
}

/* Elementary Config */

PREFIX value ml_elm_config_save(value v_unit)
{
        return Val_bool(elm_config_save());
}

PREFIX value ml_elm_config_reload(value v_unit)
{
        elm_config_reload();
        return Val_unit;
}

PREFIX value ml_elm_config_all_flush(value v_unit)
{
        elm_config_all_flush();
        return Val_unit;
}

/* Elementary Engine */

PREFIX value ml_elm_config_engine_get(value v_unit)
{
        return copy_string(elm_config_engine_get());
}

PREFIX value ml_elm_config_engine_set(value v_engine)
{
        elm_config_engine_set(String_val(v_engine));
        return Val_unit;
}

PREFIX value ml_elm_config_preferred_engine_get(value v_unit)
{
        return copy_string(elm_config_preferred_engine_get());
}

PREFIX value ml_elm_config_preferred_engine_set(value v_preferred_engine)
{
        elm_config_preferred_engine_set(String_val(v_preferred_engine));
        return Val_unit;
}

PREFIX value ml_elm_config_accel_preference_get(value v_unit)
{
        return copy_string(elm_config_accel_preference_get());
}

PREFIX value ml_elm_config_accel_preference_set(value v_s)
{
        elm_config_accel_preference_set(String_val(v_s));
        return Val_unit;
}

PREFIX value ml_elm_config_access_get(value v_unit)
{
        return Val_bool(elm_config_access_get());
}

PREFIX value ml_elm_config_access_set(value v_flag)
{
        elm_config_access_set(Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_config_selection_unfocused_clear_get(value v_unit)
{
        return Val_bool(elm_config_selection_unfocused_clear_get());
}

PREFIX value ml_elm_config_selection_unfocused_clear_set(value v_flag)
{
        elm_config_selection_unfocused_clear_set(Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_config_mirrored_get(value v_unit)
{
        return Val_bool(elm_config_mirrored_get());
}

PREFIX value ml_elm_config_mirrored_set(value v_flag)
{
        elm_config_mirrored_set(Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_config_clouseau_enabled_get(value v_unit)
{
        return Val_bool(elm_config_clouseau_enabled_get());
}

PREFIX value ml_elm_config_clouseau_enabled_set(value v_flag)
{
        elm_config_clouseau_enabled_set(Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_config_indicator_service_get(value v_rot)
{
        return copy_string(elm_config_indicator_service_get(Int_val(v_rot)));
}

PREFIX value ml_elm_config_glayer_long_tap_start_timeout_get(value v_unit)
{
        return copy_double(elm_config_glayer_long_tap_start_timeout_get());
}

PREFIX value ml_elm_config_glayer_long_tap_start_timeout_set(value v_x)
{
        elm_config_glayer_long_tap_start_timeout_set(Double_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_config_glayer_double_tap_timeout_get(value v_unit)
{
        return copy_double(elm_config_glayer_double_tap_timeout_get());
}

PREFIX value ml_elm_config_glayer_double_tap_timeout_set(value v_x)
{
        elm_config_glayer_double_tap_timeout_set(Double_val(v_x));
        return Val_unit;
}

/* Elementary Fonts */

inline value copy_Elm_Text_Class(Elm_Text_Class* c)
{
        CAMLparam0();
        CAMLlocal1(v);
        Store_field(v, 0, copy_string(c->name));
        Store_field(v, 1, copy_string(c->desc));
        CAMLreturn(v);
}

inline value copy_Eina_List_Elm_Text_Class(const Eina_List* list)
{
        CAMLparam0();
        CAMLlocal3(v, v1, v_s);
        Eina_List* it;
        Elm_Text_Class* s;
        v = Val_int(0);
        EINA_LIST_REVERSE_FOREACH(list, it, s) {
                v1 = v;
                v_s = copy_Elm_Text_Class(s);
                v = caml_alloc(2, 0);
                Store_field(v, 0, v_s);
                Store_field(v, 1, v1);
        }
        CAMLreturn(v);
}

inline value copy_Elm_Font_Overlay(Elm_Font_Overlay* c)
{
        CAMLparam0();
        CAMLlocal1(v);
        Store_field(v, 0, copy_string(c->text_class));
        Store_field(v, 1, copy_string(c->font));
        Store_field(v, 2, Val_int(c->size));
        CAMLreturn(v);
}

inline value copy_Eina_List_Elm_Font_Overlay(const Eina_List* list)
{
        CAMLparam0();
        CAMLlocal3(v, v1, v_s);
        Eina_List* it;
        Elm_Font_Overlay* s;
        v = Val_int(0);
        EINA_LIST_REVERSE_FOREACH(list, it, s) {
                v1 = v;
                v_s = copy_Elm_Font_Overlay(s);
                v = caml_alloc(2, 0);
                Store_field(v, 0, v_s);
                Store_field(v, 1, v1);
        }
        CAMLreturn(v);
}

PREFIX value ml_elm_config_text_classes_list_get(value v_unit)
{
        Eina_List* l = elm_config_text_classes_list_get();
        value v_l = copy_Eina_List_Elm_Text_Class(l);
        elm_config_text_classes_list_free(l);
        return v_l;
}

PREFIX value ml_elm_config_font_overlay_list_get(value v_unit)
{
        return copy_Eina_List_Elm_Font_Overlay(
                elm_config_font_overlay_list_get());
}

PREFIX value ml_elm_config_font_overlay_set(
        value v_class, value v_font, value v_size)
{
        elm_config_font_overlay_set(String_val(v_class), String_val(v_font),
                Int_val(v_size));
        return Val_unit;
}

PREFIX value ml_elm_config_font_overlay_unset(value v_class)
{
        elm_config_font_overlay_unset(String_val(v_class));
        return Val_unit;
}

PREFIX value ml_elm_config_font_overlay_apply(value v_unit)
{
        elm_config_font_overlay_apply();
        return Val_unit;
}

/* Elementary Profile */

PREFIX value ml_elm_config_profile_get(value v_unit)
{
        return copy_string(elm_config_profile_get());
}

PREFIX value ml_elm_config_profile_dir_get(value v_profile, value v_is_user)
{
        const char* dir = elm_config_profile_dir_get(String_val(v_profile),
                Bool_val(v_is_user));
        value v_dir = copy_string(dir);
        elm_config_profile_dir_free(dir);
        return v_dir;
}

PREFIX value ml_elm_config_profile_list_get(value v_unit)
{
        Eina_List* list = elm_config_profile_list_get();
        value v_list = copy_Eina_List_string(list);
        elm_config_profile_list_free(list);
        return v_list;
}

PREFIX value ml_elm_config_profile_set(value v_profile)
{
        elm_config_profile_set(String_val(v_profile));
        return Val_unit;
}

/* Fingers */

PREFIX value ml_elm_config_finger_size_get(value v_unit)
{
        return Val_int(elm_config_finger_size_get());
}

PREFIX value ml_elm_config_finger_size_set(value v_size)
{
        elm_config_finger_size_set(Int_val(v_size));
        return Val_unit;
}

/* Focus */

PREFIX value ml_elm_config_focus_autoscroll_mode_get(value v_unit)
{
        return Val_Elm_Focus_Autoscroll_Mode(
                elm_config_focus_autoscroll_mode_get());
}

PREFIX value ml_elm_config_focus_autoscroll_mode_set(value v_m)
{
        elm_config_focus_autoscroll_mode_set(
                Elm_Focus_Autoscroll_Mode_val(v_m));
        return Val_unit;
}

PREFIX value ml_elm_config_focus_highlight_enabled_get(value v_unit)
{
        return Val_bool(elm_config_focus_highlight_enabled_get());
}

PREFIX value ml_elm_config_focus_highlight_enabled_set(value v_flag)
{
        elm_config_focus_highlight_enabled_set(Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_config_focus_highlight_animate_get(value v_unit)
{
        return Val_bool(elm_config_focus_highlight_animate_get());
}

PREFIX value ml_elm_config_focus_highlight_animate_set(value v_flag)
{
        elm_config_focus_highlight_animate_set(Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_config_focus_highlight_clip_disabled_get(value v_unit)
{
        return Val_bool(elm_config_focus_highlight_clip_disabled_get());
}

PREFIX value ml_elm_config_focus_highlight_clip_disabled_set(value v_flag)
{
        elm_config_focus_highlight_clip_disabled_set(Bool_val(v_flag));
        return Val_unit;
}

/* Password show last */

PREFIX value ml_elm_config_password_show_last_get(value v_unit)
{
        return Val_bool(elm_config_password_show_last_get());
}

PREFIX value ml_elm_config_password_show_last_set(value v_flag)
{
        elm_config_password_show_last_set(Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_config_password_show_last_timeout_get(value v_unit)
{
        return copy_double(elm_config_password_show_last_timeout_get());
}

PREFIX value ml_elm_config_password_show_last_timeout_set(value v_t)
{
        elm_config_password_show_last_timeout_set(Double_val(v_t));
        return Val_unit;
}

/* Elementary Scrolling */

PREFIX value ml_elm_config_scroll_bounce_enabled_get(value v_unit)
{
        return Val_bool(elm_config_scroll_bounce_enabled_get());
}

PREFIX value ml_elm_config_scroll_bounce_enabled_set(value v_flag)
{
        elm_config_scroll_bounce_enabled_set(Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_config_scroll_bounce_friction_get(value v_unit)
{
        return copy_double(elm_config_scroll_bounce_friction_get());
}

PREFIX value ml_elm_config_scroll_bounce_friction_set(value v_x)
{
        elm_config_scroll_bounce_friction_set(Double_val(v_x));
        return Val_unit;
}
       
PREFIX value ml_elm_config_scroll_page_scroll_friction_get(value v_unit)
{
        return copy_double(elm_config_scroll_page_scroll_friction_get());
}

PREFIX value ml_elm_config_scroll_page_scroll_friction_set(value v_x)
{
        elm_config_scroll_page_scroll_friction_set(Double_val(v_x));
        return Val_unit;
}
       
PREFIX value ml_elm_config_scroll_bring_in_scroll_friction_get(value v_unit)
{
        return copy_double(elm_config_scroll_bring_in_scroll_friction_get());
}

PREFIX value ml_elm_config_scroll_bring_in_scroll_friction_set(value v_x)
{
        elm_config_scroll_bring_in_scroll_friction_set(Double_val(v_x));
        return Val_unit;
}
       
PREFIX value ml_elm_config_scroll_zoom_friction_get(value v_unit)
{
        return copy_double(elm_config_scroll_zoom_friction_get());
}

PREFIX value ml_elm_config_scroll_zoom_friction_set(value v_x)
{
        elm_config_scroll_zoom_friction_set(Double_val(v_x));
        return Val_unit;
}
       
PREFIX value ml_elm_config_scroll_thumbscroll_enabled_get(value v_unit)
{
        return Val_bool(elm_config_scroll_thumbscroll_enabled_get());
}

PREFIX value ml_elm_config_scroll_thumbscroll_enabled_set(value v_flag)
{
        elm_config_scroll_thumbscroll_enabled_set(Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_config_scroll_thumbscroll_threshold_get(
        value v_unit)
{
        return Val_int(elm_config_scroll_thumbscroll_threshold_get());
}

PREFIX value ml_elm_config_scroll_thumbscroll_threshold_set(value v_x)
{
        elm_config_scroll_thumbscroll_threshold_set(Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_config_scroll_thumbscroll_momentum_threshold_get(
        value v_unit)
{
        return copy_double(
                elm_config_scroll_thumbscroll_momentum_threshold_get());
}

PREFIX value ml_elm_config_scroll_thumbscroll_momentum_threshold_set(value v_x)
{
        elm_config_scroll_thumbscroll_momentum_threshold_set(Double_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_config_scroll_thumbscroll_friction_get(value v_unit)
{
        return copy_double(elm_config_scroll_thumbscroll_friction_get());
}

PREFIX value ml_elm_config_scroll_thumbscroll_friction_set(value v_x)
{
        elm_config_scroll_thumbscroll_friction_set(Double_val(v_x));
        return Val_unit;
}
       
PREFIX value ml_elm_config_scroll_thumbscroll_border_friction_get(value v_unit)
{
        return copy_double(elm_config_scroll_thumbscroll_border_friction_get());
}

PREFIX value ml_elm_config_scroll_thumbscroll_border_friction_set(value v_x)
{
        elm_config_scroll_thumbscroll_border_friction_set(Double_val(v_x));
        return Val_unit;
}
       
PREFIX value ml_elm_config_scroll_thumbscroll_sensitivity_friction_get(
        value v_unit)
{
        return copy_double(
                elm_config_scroll_thumbscroll_sensitivity_friction_get());
}

PREFIX value ml_elm_config_scroll_thumbscroll_sensitivity_friction_set(
        value v_x)
{
        elm_config_scroll_thumbscroll_sensitivity_friction_set(Double_val(v_x));
        return Val_unit;
}
       
/* Widget Scaling */

PREFIX value ml_elm_config_scale_get(value v_unit)
{
        return copy_double(elm_config_scale_get());
}

PREFIX value ml_elm_config_scale_set(value v_scale)
{
        elm_config_scale_set(Double_val(v_scale));
        return Val_unit;
}

